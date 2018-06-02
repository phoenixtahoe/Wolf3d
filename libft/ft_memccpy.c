/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdavid <pdavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/21 16:42:45 by pdavid            #+#    #+#             */
/*   Updated: 2017/11/09 13:47:36 by pdavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t i;

	i = 0;
	while (n-- > 0)
	{
		if (((char *)src)[i] == (char)c)
		{
			((char *)dst)[i] = ((char *)src)[i];
			return (&dst[i + 1]);
		}
		((char *)dst)[i] = ((char *)src)[i];
		i++;
	}
	return (NULL);
}
