/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdavid <pdavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/31 23:11:44 by pdavid            #+#    #+#             */
/*   Updated: 2018/10/31 14:47:46 by pdavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	ray_pre(t_env *e, int x)
{
	e->ray->camerax = 2 * x / (double)WIDTH - 1;
	e->ray->raydirx = e->ray->dirx + e->ray->planex * e->ray->camerax;
	e->ray->raydiry = e->ray->diry + e->ray->planey * e->ray->camerax;
	e->ray->mapx = (int)e->ray->posx;
	e->ray->mapy = (int)e->ray->posy;
	e->ray->deltadistx = fabs(1 / e->ray->raydirx);
	e->ray->deltadisty = fabs(1 / e->ray->raydiry);
	e->ray->hit = 0;
}

void	ray_dir(t_env *e)
{
	if (e->ray->raydirx < 0)
	{
		e->ray->stepx = -1;
		e->ray->sidedistx = (e->ray->posx - e->ray->mapx)
			* e->ray->deltadistx;
	}
	else
	{
		e->ray->stepx = 1;
		e->ray->sidedistx = (e->ray->mapx + 1.0 - e->ray->posx)
			* e->ray->deltadistx;
	}
	if (e->ray->raydiry < 0)
	{
		e->ray->stepy = -1;
		e->ray->sidedisty = (e->ray->posy - e->ray->mapy)
			* e->ray->deltadisty;
	}
	else
	{
		e->ray->stepy = 1;
		e->ray->sidedisty = (e->ray->mapy + 1.0 - e->ray->posy)
			* e->ray->deltadisty;
	}
}

void	ray_dda(t_env *e)
{
	while (e->ray->hit == 0)
	{
		if (e->ray->sidedistx < e->ray->sidedisty)
		{
			e->ray->sidedistx += e->ray->deltadistx;
			e->ray->mapx += e->ray->stepx;
			e->ray->side = 0;
		}
		else
		{
			e->ray->sidedisty += e->ray->deltadisty;
			e->ray->mapy += e->ray->stepy;
			e->ray->side = 1;
		}
		if ((e->x_max < e->ray->mapx || e->ray->mapx < 0 || e->ray->mapy < 0 ||
			e->y_max < e->ray->mapy) && (e->ray->hit = 1))
		{
			break ;
		}
		if (e->map[e->ray->mapy][e->ray->mapx] > 0)
			e->ray->hit = 1;
	}
}

void	ray_wall(t_env *e)
{
	if (e->ray->side == 0)
		e->ray->perpwalldist = (e->ray->mapx - e->ray->posx +
			(1 - e->ray->stepx) / 2) / e->ray->raydirx;
	else
		e->ray->perpwalldist = (e->ray->mapy - e->ray->posy +
			(1 - e->ray->stepy) / 2) / e->ray->raydiry;
	// printf("mapx = %d posx = %f stepx = %d raydirx = %f\n", e->ray->mapx, e->ray->posx, e->ray->stepx, e->ray->raydirx);
	// printf("mapy = %d posy = %f stepy = %d raydiry = %f\n", e->ray->mapy, e->ray->posy, e->ray->stepy, e->ray->raydiry);
	e->ray->lineheight = (int)(HEIGHT / e->ray->perpwalldist);
	e->ray->drawstart = -(e->ray->lineheight) / 2 + HEIGHT / 2;
	if (e->ray->drawstart < 0)
		e->ray->drawstart = 0;
	e->ray->drawend = e->ray->lineheight / 2 + HEIGHT / 2;
	if (e->ray->drawend >= HEIGHT)
		e->ray->drawend = HEIGHT - 1;
	if (e->ray->side == 0)
		e->ray->wallx = e->ray->posy + e->ray->perpwalldist * e->ray->raydiry;
	else
		e->ray->wallx = e->ray->posx + e->ray->perpwalldist * e->ray->raydirx;
	e->ray->wallx -= floor((e->ray->wallx));
}

void	ray_floor(t_env *e)
{
	if (!e->ray->side && e->ray->raydirx > 0)
	{
		e->ray->floorx = e->ray->mapx;
		e->ray->floory = e->ray->mapy + e->ray->wallx;
	}
	else if (!e->ray->side && e->ray->raydirx < 0)
	{
		e->ray->floorx = e->ray->mapx + 1.0;
		e->ray->floory = e->ray->mapy + e->ray->wallx;
	}
	else if (e->ray->side == 1 && e->ray->raydiry > 0)
	{
		e->ray->floorx = e->ray->mapx + e->ray->wallx;
		e->ray->floory = e->ray->mapy;
	}
	else
	{
		e->ray->floorx = e->ray->mapx + e->ray->wallx;
		e->ray->floory = e->ray->mapy + 1.0;
	}
}
