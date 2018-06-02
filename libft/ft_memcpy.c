/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdavid <pdavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/26 16:04:41 by pdavid            #+#    #+#             */
/*   Updated: 2017/11/09 13:49:59 by pdavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char			*a;
	char			*b;
	unsigned int	i;

	i = 0;
	a = (char *)src;
	b = (char *)dst;
	while (i < n)
	{
		b[i] = a[i];
		i++;
	}
	return (dst);
}
