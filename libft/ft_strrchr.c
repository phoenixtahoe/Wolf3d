/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdavid <pdavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/27 14:56:06 by pdavid            #+#    #+#             */
/*   Updated: 2017/11/09 14:55:00 by pdavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	const char *i;

	i = s;
	i = i + ft_strlen(s);
	while (*i != (char)c && i != s)
		i--;
	if (*i == (char)c)
		return ((char *)i);
	return (NULL);
}
