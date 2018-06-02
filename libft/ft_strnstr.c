/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdavid <pdavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/26 16:05:07 by pdavid            #+#    #+#             */
/*   Updated: 2017/10/18 11:57:15 by pdavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t i;
	size_t x;

	i = 0;
	if (!*little)
		return ((char *)big);
	while (big[i])
	{
		x = 0;
		while (big[i] == little[x] && big[i] && i < len)
		{
			i++;
			x++;
		}
		if (!little[x])
			return ((char *)&big[i - x]);
		i = (i - x) + 1;
	}
	return (0);
}
