/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdavid <pdavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/22 14:26:12 by pdavid            #+#    #+#             */
/*   Updated: 2017/10/18 11:44:07 by pdavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	if (!n)
		return (0);
	while (--n && (*(unsigned char *)s1 == *(unsigned char *)s2))
	{
		s1++;
		s2++;
	}
	return (*(unsigned char *)s1) - *((unsigned char *)s2);
}
