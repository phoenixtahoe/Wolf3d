/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdavid <pdavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/01 20:04:41 by pdavid            #+#    #+#             */
/*   Updated: 2018/07/16 17:53:56 by pdavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int keydown(int keycode, t_env *all)
{
    t_env *e;

    e = all;
	ft_bzero(e->mlx->image_ptr, HEIGHT * WIDTH * 4);
    // printf("%d\n", keycode);
    if (keycode == 53)
        exit(1);
    if (keycode == 13)
    {
        if (e->map[(int)(e->ray->posy)][(int)(e->ray->posx + e->ray->dirx * 0.02)] == 0)
            e->ray->posx += e->ray->dirx * 0.2;
        if (e->map[(int)(e->ray->posy + e->ray->diry * 0.2)][(int)e->ray->posx] == 0)
            e->ray->posy += e->ray->diry * 0.2;
    }
    else if (keycode == 1)
    {
        if (e->map[(int)(e->ray->posy)][(int)(e->ray->posx - e->ray->dirx * 0.2)] == 0)
            e->ray->posx -= e->ray->dirx * 0.2;
        if (e->map[(int)(e->ray->posy - e->ray->diry * 0.2)][(int)e->ray->posx] == 0)
            e->ray->posy -= e->ray->diry * 0.2;
    }
    else if (keycode == 2)
    {
        e->ray->olddirx = e->ray->dirx;
        e->ray->dirx = e->ray->dirx * cos(-0.2) - e->ray->diry * sin(-0.2);
        e->ray->diry = e->ray->olddirx * sin(-0.2) + e->ray->diry * cos(-0.2);
        e->ray->oldplanex = e->ray->planex;
        e->ray->planex = e->ray->planex * cos(-0.2) - e->ray->planey * sin(-0.2);
        e->ray->planey = e->ray->oldplanex * sin(-0.2) + e->ray->planey * cos(-0.2);
    }
    else if (keycode == 0)
    {
        e->ray->olddirx = e->ray->dirx;
        e->ray->dirx = e->ray->dirx * cos(0.2) - e->ray->diry * sin(0.2);
        e->ray->diry = e->ray->olddirx * sin(0.2) + e->ray->diry * cos(0.2);
        e->ray->oldplanex = e->ray->planex;
        e->ray->planex = e->ray->planex * cos(0.2) - e->ray->planey * sin(0.2);
        e->ray->planey = e->ray->oldplanex * sin(0.2) + e->ray->planey * cos(0.2);
    }
    draw(e);
    return (0);
}