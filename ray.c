/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdavid <pdavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/31 23:11:44 by pdavid            #+#    #+#             */
/*   Updated: 2018/06/24 21:06:43 by pdavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

#include "wolf3d.h"

// void draw_all(t_env *all)
// {
// 	t_env *current;
// 	t_ray *ray;
// 	int x;
// 	int y;
// 
// 	current = all;
// 	ray = current->ray;
// 	x = -1;
// 	while (++x < WIDTH)
// 	{
		// ray->camerax = 2 * x / (double)(WIDTH) - 1;
		// ray->raydirx = ray->dirx + ray->planex * ray->camerax;
		// ray->raydiry = ray->diry + ray->planey * ray->camerax;
		// ray->mapx = (int)ray->posx;
		// ray->mapy = (int)ray->posy;
		// ray->deltadistx = fabs(1 / ray->raydirx);
		// ray->deltadisty = fabs(1 / ray->raydiry);
		// ray->hit = 0;
		// if (ray->raydirx < 0)
		// {
		// 	ray->stepx = -1;
		// 	ray->sidedistx = (ray->posx - ray->mapx) * ray->deltadistx;
		// }
		// else
		// {
		// 	ray->stepx = 1;
		// 	ray->sidedistx = (ray->mapx + 1.0 - ray->posx) * ray->deltadistx;
		// }
		// if (ray->raydiry < 0)
		// {
		// 	ray->stepy = -1;
		// 	ray->sidedisty = (ray->posy - ray->mapy) * ray->deltadisty;
		// }
		// else
		// {
		// 	ray->stepy = 1;
		// 	ray->sidedisty = (ray->mapy + 1.0 - ray->posy) * ray->deltadisty;
		// }
		// while (ray->hit == 0)
		// {
		// 	if (ray->sidedistx < ray->sidedisty)
		// 	{
		// 		ray->sidedistx += ray->deltadistx;
		// 		ray->mapx += ray->stepx;
		// 		ray->side = 0;
		// 	}
		// 	else
		// 	{
		// 		ray->sidedisty += ray->deltadisty;
		// 		ray->mapy += ray->stepy;
		// 		ray->side = 1;
		// 	}
		// 	if (WIDTH_MAP <= ray->mapx || ray->mapx <= 0 || ray->mapy <= 0 || HEIGHT_MAP < ray->mapy)
		// 	{
		// 		ray->hit = 1;
		// 		break ;
		// 	}
		// 	if (current->map[ray->mapy][ray->mapx] != 0)
		// 		ray->hit = 1;
		// }
		// if (ray->side == 0)
		// 	ray->perpwalldist = (ray->mapx - ray->posx + (1 - ray->stepx) / 2) / ray->raydirx;
		// else
		// 	ray->perpwalldist = (ray->mapy - ray->posy + (1 - ray->stepy) / 2) / ray->raydiry;
		// //printf("mapy = %d posy = %f stepy = %d raydiry = %f\n", ray->mapy, ray->posy, ray->stepy, ray->raydiry);
		// ray->lineheight = (int)(HEIGHT / ray->perpwalldist);
		// ray->drawstart = -(ray->lineheight) / 2 + HEIGHT / 2;
		// if (ray->drawstart < 0)
		// 	ray->drawstart = 0;
		// ray->drawend = ray->lineheight / 2 + HEIGHT / 2;
		// if (ray->drawend >= HEIGHT)
		// 	ray->drawend = HEIGHT - 1;
		// if (ray->side == 0)
		// 	ray->wallx = ray->posy + ray->perpwalldist * ray->raydiry;
		// else
		// 	ray->wallx = ray->posx + ray->perpwalldist * ray->raydirx;
		// ray->wallx -= floor(ray->wallx);
		// ray->texx = (int)(ray->wallx * (double)TEXT);
		// if (ray->side == 0 && ray->raydirx > 0)
		// 	ray->texx = TEXT - ray->texx - 1;
		// if (ray->side == 1 && ray->raydiry < 0)
		// 	ray->texx = TEXT - ray->texx - 1;
		// y = ray->drawstart - 1;
		// while (++y < ray->drawend)
		// {
		// 	ray->d = y * 256 - HEIGHT * 128 + ray->lineheight * 128;
		// 	ray->texy = ((ray->d * TEXT) / ray->lineheight) / 256;
		// 	ray->color = current->text[0][(int)(TEXT * ray->texy + ray->texx)];
		// 	if (ray->side == 1)
		// 		ray->color = (ray->color >> 1) & 8355711;
		// 	current->mlx->image_ptr[y * ((int)HEIGHT) + x] = ray->color;
		// }
		// if (!ray->side && ray->raydirx > 0)
		// {
		// 	ray->floorx = ray->mapx;
		// 	ray->floory = ray->mapy + ray->wallx;
		// }
		// else if (!ray->side && ray->raydirx < 0)
		// {
		// 	ray->floorx = ray->mapx + 1.0;
		// 	ray->floory = ray->mapy + ray->wallx;
		// }
		// else if (ray->side == 1 && ray->raydiry > 0)
		// {
		// 	ray->floorx = ray->mapx + ray->wallx;
		// 	ray->floory = ray->mapy;
		// }
		// else
		// {
		// 	ray->floorx = ray->mapx + ray->wallx;
		// 	ray->floory = ray->mapy + 1.0;
		// }
		// ray->distwall = ray->perpwalldist;
		// ray->distpos = 0.0;
		// if (ray->drawend < 0)
		// 	ray->drawend = HEIGHT;
		// y = ray->drawend;
		// while (++y < HEIGHT)
		// {
		// 	ray->distcurr = HEIGHT / (2.0 * y - HEIGHT);
		// 	ray->weight = (ray->distcurr - ray->distpos) / (ray->distwall - ray->distpos);
		// 	ray->currfloorx = ray->weight * ray->floorx + (1.0 - ray->weight) * ray->posx;
		// 	ray->currfloory = ray->weight * ray->floory + (1.0 - ray->weight) * ray->posy;
		// 	ray->floortextx = (int)(ray->currfloorx * TEXT) % (int)TEXT;
		// 	ray->floortexty = (int)(ray->currfloory * TEXT) % (int)TEXT;
		// 	current->mlx->image_ptr[y * (int)HEIGHT + x] = ((current->text[2][(int)(TEXT * ray->floortexty + ray->floortextx)]) >> 1) & 8355711;
		// 	current->mlx->image_ptr[(int)(HEIGHT - y) * HEIGHT + x] = current->text[3][(int)(TEXT * ray->floortexty + ray->floortextx)];
// 		}
// 	}
// }

void	ray_init(t_env *e, int x)
{
	e->ray->camerax = 2 * x / (double)(WIDTH) - 1;
	e->ray->raydirx = e->ray->dirx + e->ray->planex * e->ray->camerax;
	e->ray->raydiry = e->ray->diry + e->ray->planey * e->ray->camerax;
	e->ray->mapx = (int)e->ray->posx;
	e->ray->mapy = (int)e->ray->posy;
	e->ray->deltadistx = fabs(1 / e->ray->raydirx);
	e->ray->deltadisty = fabs(1 / e->ray->raydiry);
	e->ray->hit = 0;
	if (e->ray->raydirx < 0)
	{
		e->ray->stepx = -1;
		e->ray->sidedistx = (e->ray->posx - e->ray->mapx) * e->ray->deltadistx;
	}
	else
	{
		e->ray->stepx = 1;
		e->ray->sidedistx = (e->ray->mapx + 1.0 - e->ray->posx) * e->ray->deltadistx;
	}
	if (e->ray->raydiry < 0)
	{
		e->ray->stepy = -1;
		e->ray->sidedisty = (e->ray->posy - e->ray->mapy) * e->ray->deltadisty;
	}
	else
	{
		e->ray->stepy = 1;
		e->ray->sidedisty = (e->ray->mapy + 1.0 - e->ray->posy) * e->ray->deltadisty;
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
		if (18 <= e->ray->mapx || e->ray->mapx <= 0 || e->ray->mapy <= 0 || 18 < e->ray->mapy)
		{
			e->ray->hit = 1;
			break ;
		}
		if (e->map[e->ray->mapy][e->ray->mapx] != 0)
			e->ray->hit = 1;
	}
}

void	ray_wall(t_env *e)
{
	if (e->ray->side == 0)
		e->ray->perpwalldist = (e->ray->mapx - e->ray->posx + (1 - e->ray->stepx) / 2) / e->ray->raydirx;
	else
		e->ray->perpwalldist = (e->ray->mapy - e->ray->posy + (1 - e->ray->stepy) / 2) / e->ray->raydiry;
	//printf("mapy = %d posy = %f stepy = %d raydiry = %f\n", ray->mapy, ray->posy, ray->stepy, ray->raydiry);
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

void	text_floor(t_env *e, int x)
{
	int y;

	e->ray->distwall = e->ray->perpwalldist;
	e->ray->distpos = 0.0;
	if (e->ray->drawend < 0)
		e->ray->drawend = HEIGHT;
	y = e->ray->drawend;
	while (++y < HEIGHT)
	{
		e->ray->distcurr = HEIGHT / (2.0 * y - HEIGHT);
		e->ray->weight = (e->ray->distcurr - e->ray->distpos) / (e->ray->distwall - e->ray->distpos);
		e->ray->currfloorx = e->ray->weight * e->ray->floorx + (1.0 - e->ray->weight) * e->ray->posx;
		e->ray->currfloory = e->ray->weight * e->ray->floory + (1.0 - e->ray->weight) * e->ray->posy;
		e->ray->floortextx = (int)(e->ray->currfloorx * TEXT) % (int)TEXT;
		e->ray->floortexty = (int)(e->ray->currfloory * TEXT) % (int)TEXT;
		e->mlx->image_ptr[y * (int)HEIGHT + x] = ((e->text[0][(int)(TEXT * e->ray->floortexty + e->ray->floortextx)]) >> 1) & 8355711;
		e->mlx->image_ptr[(int)(HEIGHT - y) * HEIGHT + x] = e->text[3][(int)(TEXT * e->ray->floortexty + e->ray->floortextx)];
	}
}

void	text_wall(t_env *e, int x)
{
	int y;
	
	e->ray->texx = (int)(e->ray->wallx * (double)TEXT);
	if (e->ray->side == 0 && e->ray->raydirx > 0)
		e->ray->texx = TEXT - e->ray->texx - 1;
	if (e->ray->side == 1 && e->ray->raydiry < 0)
		e->ray->texx = TEXT - e->ray->texx - 1;
	y = e->ray->drawstart - 1;
	while (++y < e->ray->drawend)
	{
		e->ray->d = y * 256 - HEIGHT * 128 + e->ray->lineheight * 128;
		e->ray->texy = ((e->ray->d * TEXT) / e->ray->lineheight) / 256;
		e->mlx->image_ptr[y * (int)HEIGHT + x] = ((e->text[0][(int)(TEXT * e->ray->texx + e->ray->texy)]) >> 1) & 8355711;
	}
}

void		draw(t_env *e)
{
	int x;
	
	x = -1;
	mlx_clear_window(e->mlx->mlx, e->mlx->window);
	while (++x != HEIGHT)
	{
		ray_init(e, x);
		ray_dda(e);
		ray_wall(e);
		text_wall(e, x);
		ray_floor(e);
		text_floor(e, x);
	}
}