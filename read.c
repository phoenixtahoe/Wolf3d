/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdavid <pdavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/30 20:15:53 by pdavid            #+#    #+#             */
/*   Updated: 2018/11/26 14:38:41 by pdavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	parse(char *str, int x, t_env **e, int index)
{
	int k;

	k = 0;
	if (!((*e)->map[index] = (int *)malloc(sizeof(int) * x)))
		exit(1);
	while (*str)
	{
		if (ft_isdigit(str[0]) && k <= x)
		{
			(*e)->map[index][k] = str[0] - '0';
			k++;
		}
		str++;
	}
}

int		init_read(char *str, t_env *e)
{
	int		fd;
	char	*line;
	int		index;

	index = 0;
	line = NULL;
	if ((fd = open(str, O_RDONLY)) == -1)
	{
		ft_putendl("ERROR");
		exit(1);
	}
	if (!(e->map = (int **)malloc(sizeof(int *) * HEIGHT_MAP)))
		exit(1);
	while (get_next_line(fd, &line) == 1)
	{
		parse(line, WIDTH_MAP, &e, index);
		free(line);
		index++;
	}
	close(fd);
	return (0);
}
