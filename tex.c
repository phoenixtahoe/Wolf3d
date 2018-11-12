/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tex.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdavid <pdavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/30 18:10:38 by pdavid            #+#    #+#             */
/*   Updated: 2018/11/26 14:13:33 by pdavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	text_floor(t_env *e, int x)
{
	int	y;

	e->ray->distwall = e->ray->perpwalldist;
	e->ray->distpos = 0.0;
	if (e->ray->drawend < 0)
		e->ray->drawend = HEIGHT;
	y = e->ray->drawend;
	while (++y < HEIGHT)
	{
		e->ray->distcurr = HEIGHT / (2.0 * y - HEIGHT);
		e->ray->weight = (e->ray->distcurr - e->ray->distpos)
			/ (e->ray->distwall - e->ray->distpos);
		e->ray->currfloorx = e->ray->weight * e->ray->floorx
			+ (1.0 - e->ray->weight) * e->ray->posx;
		e->ray->currfloory = e->ray->weight * e->ray->floory
			+ (1.0 - e->ray->weight) * e->ray->posy;
		e->ray->floortextx = (int)(e->ray->currfloorx * TEXT) % (int)TEXT;
		e->ray->floortexty = (int)(e->ray->currfloory * TEXT) % (int)TEXT;
		e->mlx->image_ptr[y * (int)HEIGHT + x] = ((e->text[0][(int)
			(TEXT * e->ray->floortexty + e->ray->floortextx)]) >> 1) & 8355711;
		e->mlx->image_ptr[(int)(HEIGHT - y) * HEIGHT + x] = e->text[0]
			[(int)(TEXT * e->ray->floortexty + e->ray->floortextx)];
	}
}

void	text_wall(t_env *e, int x)
{
	int	y;

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
		e->ray->color = e->text[0][(int)(TEXT * e->ray->texy + e->ray->texx)];
		if (e->ray->side == 1)
			e->ray->color = (e->ray->color >> 1) & 8355711;
		e->mlx->image_ptr[y * ((int)HEIGHT) + x] = e->ray->color;
	}
}
