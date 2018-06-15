/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdavid <pdavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/30 20:15:53 by pdavid            #+#    #+#             */
/*   Updated: 2018/06/14 19:04:56 by pdavid           ###   ########.fr       */
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
	arr[17] = 1;
	arr[0] = 1;
	return (arr);
}

int	ft_initread(char *str, t_env *current)
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
	current->map = (int **)malloc(sizeof(int **) * HEIGHT_MAP);
	while (get_next_line(fd, &line) == 1)
	{
		current->map[index] = parse(line, WIDTH_MAP);
		free(line);
		index++;
	}
	close(fd);
	return (0);
}