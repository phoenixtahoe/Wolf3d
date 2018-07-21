/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdavid <pdavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/30 20:03:53 by pdavid            #+#    #+#             */
/*   Updated: 2018/07/16 17:30:10 by pdavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void init_xpm(t_env *e)
{
	e->mlx->image = mlx_new_image(e->mlx->mlx, WIDTH, HEIGHT);
	e->mlx->image_ptr = (int*)mlx_get_data_addr(e->mlx->image, &(e->mlx->bpp), &(e->mlx->sl), &(e->mlx->endian));
	e->xpm.xpm_floor = mlx_xpm_file_to_image(e->mlx->mlx, "./xpm/matrix.xpm", &(e->xpm.xpm_f_x), &(e->xpm.xpm_f_y));
	e->xpm.xpm_f_addr = (int*)mlx_get_data_addr(e->xpm.xpm_floor, &(e->xpm.xpm_f_b), &(e->xpm.xpm_f_s), &(e->xpm.xpm_f_e));
}

void		init_text(t_env *e)
{
	int		x;
	int		y;

	y = -1;
	while (++y < TEXT)
	{
		x = -1;
		while (++x < TEXT)
		{
			e->text[0][TEXT * y + x] = e->xpm.xpm_f_addr[TEXT * y + x];
			e->text[1][TEXT * y + x] = e->xpm.xpm_f_addr[TEXT * y + x];
			e->text[2][TEXT * y + x] = e->xpm.xpm_f_addr[TEXT * y + x];
			e->text[3][TEXT * y + x] = e->xpm.xpm_f_addr[TEXT * y + x];
		}
	}
}

t_ray *init_ray(void) 
{
	t_ray *ray;
	
	if (!(ray = malloc(sizeof(t_ray))))
		exit(1);
	ray->dirx = -1.0;
	ray->diry = 0.0;
	ray->planex = 0;
	ray->planey = 2 * (atan(.45 / 1.0));
	return (ray);
}

void init_env(t_env *e)
{
	int i;

	e->mlx->image = mlx_new_image(e->mlx->mlx, WIDTH, HEIGHT);
	e->mlx->image_ptr = (int*)mlx_get_data_addr(e->mlx->image, &(e->mlx->bpp), &(e->mlx->sl), &(e->mlx->endian));
	init_xpm(e);
	e->ray = init_ray();
    e->ray->posx = 5;
    e->ray->posy = 5;
	i = -1;
	while (++i < 4)
		e->text[i] = malloc(4 * (TEXT * TEXT));
}