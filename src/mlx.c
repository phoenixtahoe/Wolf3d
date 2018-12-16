/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdavid <pdavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/01 20:04:41 by pdavid            #+#    #+#             */
/*   Updated: 2018/12/16 11:24:42 by pdavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

int	up(int keycode, t_env *e)
{
	if (keycode == 13)
	{
		if (e->map[(int)(e->ray->posy)]
			[(int)(e->ray->posx + e->ray->dirx * 0.2)] == 0)
			e->ray->posx += e->ray->dirx * 0.2;
		if (e->map[(int)(e->ray->posy + e->ray->diry * 0.2)]
			[(int)e->ray->posx] == 0)
			e->ray->posy += e->ray->diry * 0.2;
	}
	return (0);
}

int	down(int keycode, t_env *e)
{
	if (keycode == 1)
	{
		if (e->map[(int)(e->ray->posy)]
			[(int)(e->ray->posx - e->ray->dirx * 0.2)] == 0)
			e->ray->posx -= e->ray->dirx * 0.2;
		if (e->map[(int)(e->ray->posy - e->ray->diry * 0.2)]
			[(int)e->ray->posx] == 0)
			e->ray->posy -= e->ray->diry * 0.2;
	}
	return (0);
}

int	left(int keycode, t_env *e)
{
	if (keycode == 0)
	{
		e->ray->olddirx = e->ray->dirx;
		e->ray->dirx = e->ray->dirx * cos(0.2) - e->ray->diry * sin(0.2);
		e->ray->diry = e->ray->olddirx * sin(0.2) + e->ray->diry * cos(.2);
		e->ray->oldplanex = e->ray->planex;
		e->ray->planex = e->ray->planex
			* cos(0.2) - e->ray->planey * sin(0.2);
		e->ray->planey = e->ray->oldplanex
			* sin(0.2) + e->ray->planey * cos(0.2);
	}
	return (0);
}

int	right(int keycode, t_env *e)
{
	if (keycode == 2)
	{
		e->ray->olddirx = e->ray->dirx;
		e->ray->dirx = e->ray->dirx * cos(-.2) - e->ray->diry * sin(-.2);
		e->ray->diry = e->ray->olddirx * sin(-.2) + e->ray->diry * cos(-.2);
		e->ray->oldplanex = e->ray->planex;
		e->ray->planex = e->ray->planex
			* cos(-.2) - e->ray->planey * sin(-.2);
		e->ray->planey = e->ray->oldplanex
			* sin(-.2) + e->ray->planey * cos(-.2);
	}
	return (0);
}

int	keydown(int keycode, t_env *e)
{
	if (keycode == 53)
	{
		exit(1);
	}
	up(keycode, e);
	down(keycode, e);
	right(keycode, e);
	left(keycode, e);
	draw(e);
	return (0);
}
