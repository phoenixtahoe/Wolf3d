/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdavid <pdavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/04 18:51:26 by pdavid            #+#    #+#             */
/*   Updated: 2017/12/05 13:15:28 by pdavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	char	*str;

	i = 0;
	if (!s || !f)
		return (0);
	str = (char *)malloc((ft_strlen(s) + 1) * sizeof(char));
	if (str)
	{
		while (s[i])
		{
			str[i] = (*f)(i, s[i]);
			i++;
		}
		str[i] = '\0';
		return (str);
	}
	else
		return (NULL);
}
