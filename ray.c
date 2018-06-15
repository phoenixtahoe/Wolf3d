/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdavid <pdavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/31 23:11:44 by pdavid            #+#    #+#             */
/*   Updated: 2018/06/18 19:08:55 by pdavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

#include "wolf3d.h"

void draw_all(t_env *all)
{
	t_env *current;
	t_ray *ray;
	int x;
	int y;

	current = all;
	ray = current->ray;
	x = -1;
	while (++x < WIDTH)
	{
		ray->camerax = 2 * x / (double)(WIDTH) - 1;
		ray->raydirx = ray->dirx + ray->planex * ray->camerax;
		ray->raydiry = ray->diry + ray->planey * ray->camerax;
		ray->mapx = (int)ray->posx;
		ray->mapy = (int)ray->posy;
		ray->deltadistx = fabs(1 / ray->raydirx);
		ray->deltadisty = fabs(1 / ray->raydiry);
		ray->hit = 0;
		if (ray->raydirx < 0)
		{
			ray->stepx = -1;
			ray->sidedistx = (ray->posx - ray->mapx) * ray->deltadistx;
		}
		else
		{
			ray->stepx = 1;
			ray->sidedistx = (ray->mapx + 1.0 - ray->posx) * ray->deltadistx;
		}
		if (ray->raydiry < 0)
		{
			ray->stepy = -1;
			ray->sidedisty = (ray->posy - ray->mapy) * ray->deltadisty;
		}
		else
		{
			ray->stepy = 1;
			ray->sidedisty = (ray->mapy + 1.0 - ray->posy) * ray->deltadisty;
		}
		while (ray->hit == 0)
		{
			if (ray->sidedistx < ray->sidedisty)
			{
				ray->sidedistx += ray->deltadistx;
				ray->mapx += ray->stepx;
				ray->side = 0;
			}
			else
			{
				ray->sidedisty += ray->deltadisty;
				ray->mapy += ray->stepy;
				ray->side = 1;
			}
			/*if (current->x_max < ray->mapx || ray->mapx < 0 || ray->mapy < 0 || current->y_max < ray->mapy)
			{
				ray->hit = 1;
				break;
			}*/
			if (current->map[ray->mapy][ray->mapx] > 0)
				ray->hit = 1;
		}
		if (ray->side == 0)
			ray->perpwalldist = (ray->mapx - ray->posx + (1 - ray->stepx) / 2) / ray->raydirx;
		else
			ray->perpwalldist = (ray->mapy - ray->posy + (1 - ray->stepy) / 2) / ray->raydiry;
		//printf("mapy = %d posy = %f stepy = %d raydiry = %f\n", ray->mapy, ray->posy, ray->stepy, ray->raydiry);
		ray->lineheight = (int)(HEIGHT / ray->perpwalldist);
		ray->drawstart = -(ray->lineheight) / 2 + HEIGHT / 2;
		if (ray->drawstart < 0)
			ray->drawstart = 0;
		ray->drawend = ray->lineheight / 2 + HEIGHT / 2;
		if (ray->drawend >= HEIGHT)
			ray->drawend = HEIGHT - 1;
		if (ray->side == 0)
			ray->wallx = ray->posy + ray->perpwalldist * ray->raydiry;
		else
			ray->wallx = ray->posx + ray->perpwalldist * ray->raydirx;
		ray->wallx -= floor(ray->wallx);
		ray->texx = (int)(ray->wallx * (double)TEXT);
		if (ray->side == 0 && ray->raydirx > 0)
			ray->texx = TEXT - ray->texx - 1;
		if (ray->side == 1 && ray->raydiry < 0)
			ray->texx = TEXT - ray->texx - 1;
		y = ray->drawstart - 1;
		while (++y < ray->drawend)
		{
			ray->d = y * 256 - HEIGHT * 128 + ray->lineheight * 128;
			ray->texy = ((ray->d * TEXT) / ray->lineheight) / 256;
			ray->color = current->text[0][(int)(TEXT * ray->texy + ray->texx)];
			if (ray->side == 1)
				ray->color = (ray->color >> 1) & 8355711;
			current->mlx->image_ptr[y * ((int)HEIGHT) + x] = ray->color;
		}
		if (!ray->side && ray->raydirx > 0)
		{
			ray->floorx = ray->mapx;
			ray->floory = ray->mapy + ray->wallx;
		}
		else if (!ray->side && ray->raydirx < 0)
		{
			ray->floorx = ray->mapx + 1.0;
			ray->floory = ray->mapy + ray->wallx;
		}
		else if (ray->side== 1 && ray->raydiry > 0)
		{
			ray->floorx = ray->mapx + ray->wallx;
			ray->floory = ray->mapy;
		}
		else
		{
			ray->floorx = ray->mapx + ray->wallx;
			ray->floory = ray->mapy + 1.0;
		}
		ray->distwall = ray->perpwalldist;
		ray->distpos = 0.0;
		if (ray->drawend < 0)
			ray->drawend = HEIGHT;
		y = ray->drawend;
		while (++y < HEIGHT)
		{
			ray->distcurr = HEIGHT / (2.0 * y - HEIGHT);
			ray->weight = (ray->distcurr - ray->distpos) / (ray->distwall - ray->distpos);
			ray->currfloorx = ray->weight * ray->floorx + (1.0 - ray->weight) * ray->posx;
			ray->currfloory = ray->weight * ray->floory + (1.0 - ray->weight) * ray->posy;
			ray->floortextx = (int)(ray->currfloorx * TEXT) % (int)TEXT;
			ray->floortexty = (int)(ray->currfloory * TEXT) % (int)TEXT;
			current->mlx->image_ptr[y * (int)HEIGHT + x] = ((current->text[2][(int)(TEXT * ray->floortexty + ray->floortextx)]) >> 1) & 8355711;
			current->mlx->image_ptr[(int)(HEIGHT - y) * HEIGHT + x] = current->text[3][(int)(TEXT * ray->floortexty + ray->floortextx)];
		}
	}
}

int		draw(t_env *current)
{
	mlx_clear_window(current->mlx->mlx, current->mlx->window);
	draw_all(current);
	mlx_put_image_to_window(current->mlx->mlx,
			current->mlx->window, current->mlx->image, 0, 0);
	return (1);
}