/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdavid <pdavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/10 13:33:23 by pdavid            #+#    #+#             */
/*   Updated: 2017/12/05 13:16:51 by pdavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char			*new;
	int				start;
	unsigned int	i;

	if (!s)
		return (NULL);
	i = 0;
	while ((s[i] == ' ') || (s[i] == '\t') || (s[i] == '\n'))
		i++;
	start = i;
	if (s[start] == '\0')
	{
		new = (char *)malloc(1);
		*new = '\0';
		return (new);
	}
	while (s[i + 1])
		i++;
	while ((s[i] == ' ') || (s[i] == '\t') || (s[i] == '\n'))
		i--;
	if (!(new = (ft_strsub(s, start, i - start + 1))))
		return (NULL);
	return (new);
}
