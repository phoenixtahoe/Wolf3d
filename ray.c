/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdavid <pdavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/31 23:11:44 by pdavid            #+#    #+#             */
/*   Updated: 2018/06/02 00:25:39 by pdavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void draw_all(t_env *all)
{
    t_env *current;
    t_ray *ray;
    int x;

    current = all;
    ray = current->ray;
    x = -1;
    while (x++ != WIDTH)
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
            if (current->x_max < ray->mapx || ray->mapx < 0 || ray->mapy < 0 || current->y_max < ray->mapy)
            {
                ray->hit = 1;
                break;
            }
            if (current->map[ray->mapx][ray->mapy] > 0)
                ray->hit = 1;
        }
        if (ray->side == 0)
            ray->perpwalldist = (ray->mapx - ray->posx + (1 - ray->stepx) / 2) / ray->raydirx;
        else
            ray->perpwalldist = (ray->mapy - ray->posy + (1 - ray->stepy) / 2) / ray->raydiry;
        printf("mapy = %d posy = %f stepy = %d raydiry = %f\n", ray->mapy, ray->posy, ray->stepy, ray->raydiry);
        ray->lineheight = (int)(HEIGHT / ray->perpwalldist);
        ray->drawstart = -ray->lineheight / 2 + HEIGHT / 2;
        if (ray->drawstart < 0)
            ray->drawstart = 0;
        ray->drawend = ray->lineheight / 2 + HEIGHT / 2;
        if (ray->drawend >= HEIGHT)
            ray->drawend = HEIGHT - 1;
        ray->color = 0xFF7B7B;
        draw_vert(x, ray->drawstart, ray->drawend, current);
    }
}

void    ft_sky(t_env *all)
{
    int x;
    t_env *current;

    x = 0;
    current = all;
    while (x != WIDTH)
    {
		all->ray->color = 0x000b7E;
        draw_vert(x, HEIGHT / 2, HEIGHT, current);
		all->ray->color = 0xBD7BFF;
        draw_vert(x, 0, HEIGHT / 2, current);
        x++;
    }
}

int		draw(t_env *current)
{
	mlx_clear_window(current->mlx->mlx, current->mlx->window);
	ft_sky(current);
	draw_all(current);
	mlx_put_image_to_window(current->mlx->mlx,
		current->mlx->window, current->mlx->image, 0, 0);
	return (1);
}