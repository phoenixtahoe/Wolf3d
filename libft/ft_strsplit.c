/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdavid <pdavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/10 14:05:10 by pdavid            #+#    #+#             */
/*   Updated: 2017/11/09 15:16:52 by pdavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*ft_place_words(char const *s, char c, int *newi)
{
	int			i;
	int			begin;
	char		*word;

	i = 0;
	while (s[*newi] == c && s[*newi] != '\0')
		(*newi)++;
	begin = *newi;
	while (s[*newi] != c && s[*newi] != '\0')
		(*newi)++;
	if (!(word = ft_strnew(*newi - begin)))
		return (NULL);
	while (begin < *newi)
		word[i++] = s[begin++];
	word[i] = '\0';
	return (word);
}

char			**ft_strsplit(char const *s, char c)
{
	char		**strings;
	int			i;
	int			count;
	int			x;

	x = 0;
	count = 0;
	i = 0;
	if (!s)
		return (NULL);
	while (s[i] != '\0')
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
			count++;
		i++;
	}
	i = 0;
	if (!(strings = (char **)malloc((count + 1) * sizeof(char *))))
		return (NULL);
	while (i < count)
		strings[i++] = ft_place_words(s, c, &x);
	strings[i] = 0;
	return (strings);
}
