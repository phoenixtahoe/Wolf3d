/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdavid <pdavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/30 19:59:51 by pdavid            #+#    #+#             */
/*   Updated: 2018/11/26 14:32:14 by pdavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void		draw(t_env *e)
{
	int		x;

	x = -1;
	while (++x != WIDTH)
	{
		ray_pre(e, x);
		ray_dir(e);
		ray_dda(e);
		ray_wall(e);
		text_wall(e, x);
		ray_floor(e);
		text_floor(e, x);
		x++;
	}
	mlx_put_image_to_window(e->mlx->mlx, e->mlx->window, e->mlx->image, 0, 0);
}

int			main(int argc, char **argv)
{
	t_env	*e;

	if (argc != 2)
	{
		exit(1);
	}
	e = init_env();
	init_text(e);
	init_read(argv[1], e);
	draw(e);
	mlx_hook(e->mlx->window, 2, 0, keydown, e);
	mlx_loop(e->mlx->mlx);
	return (0);
}
