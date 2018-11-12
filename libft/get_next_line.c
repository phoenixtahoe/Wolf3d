/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdavid <pdavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/04 16:32:48 by pdavid            #+#    #+#             */
/*   Updated: 2018/11/26 14:23:31 by pdavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	ft_fnl(int fd, char **str, char **line)
{
	char		*cur;
	char		*tmp;

	while ((cur = ft_strchr(str[fd], '\n')))
	{
		tmp = str[fd];
		*cur = '\0';
		*line = ft_strsub(str[fd], 0, ft_strlen(str[fd]) - ft_strlen(cur));
		str[fd] = ft_strdup(cur + 1);
		free(tmp);
		return (1);
	}
	while (*str[fd])
	{
		*line = ft_strnew(ft_strlen(str[fd]));
		ft_strcpy(*line, str[fd]);
		free(str[fd]);
		str[fd] = ft_memalloc(BUFF_SIZE + 1);
		return (1);
	}
	return (0);
}

static	int	ft_read(int fd, char **str)
{
	char		*newstr;
	char		*tmp;
	int			ret;

	newstr = ft_memalloc(BUFF_SIZE + 1);
	while ((ret = (read(fd, newstr, BUFF_SIZE))) && (ret > 0))
	{
		if (!str[fd])
		{
			str[fd] = ft_strnew(ft_strlen(newstr));
			ft_strcpy(str[fd], newstr);
		}
		else
		{
			tmp = str[fd];
			str[fd] = ft_strjoin(str[fd], newstr);
			free(tmp);
		}
		ft_memset(newstr, 0, BUFF_SIZE);
	}
	free(newstr);
	return (ret);
}

int			get_next_line(const int fd, char **line)
{
	static	char	*str[4864];

	if (!line || fd < 0 || BUFF_SIZE < 0 || (ft_read(fd, &str[fd]) < 0))
		return (-1);
	if (ft_fnl(fd, &str[fd], line) == 1)
		return (1);
	return (0);
}
