/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdavid <pdavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/30 20:15:53 by pdavid            #+#    #+#             */
/*   Updated: 2018/11/12 13:10:47 by pdavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int		*parse(char *str, int x)
{
	int *arr;
	int k;

	k = 0;
	arr = (int *)malloc(sizeof(int) * x);
	while (*str)
	{
		if (ft_isdigit(str[0]) && k <= x)
		{
			arr[k] = str[0] - '0';
			k++;
		}
		str++;
	}
	return (arr);
}

int		init_read(char *str, t_env *e)
{
	int		fd;
	char	*line;
	int		index;
	
	index = 0;
	line = NULL;
	if (!(fd = open(str, O_RDONLY)))
	{
		ft_putendl("ERROR");
		exit(1);
	}
	e->map = (int **)malloc(sizeof(int **) * HEIGHT_MAP);
	while (get_next_line(fd, &line) != 0)
	{
		e->map[index] = parse(line, WIDTH_MAP);
		free(line);
		index++;
	}
	close(fd);
	return (0);
}
