/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdavid <pdavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/01 00:31:51 by pdavid            #+#    #+#             */
/*   Updated: 2018/06/01 23:40:13 by pdavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void		pixel_put_img(t_env *j, int x, int y, int color)
{
	t_env	*e;
	int		hex;

	e = j;
	if (y < 0)
		y = 0;
	if (x < 0)
		x = 0;
	if (x < WIDTH && y < HEIGHT)
	{
		hex = mlx_get_color_value(e->mlx->mlx, color);
		ft_memcpy(e->mlx->image_ptr + 4 * WIDTH * y + x * 4, &color, sizeof(int));
	}
}

void	draw_vert(int x, int start, int end, t_env *all)
{
	// printf("start = %d\nEnd = %d\n", start, end);
	if (start < end)
	{
		while (start != end)
		{
			pixel_put_img(all, x, start, all->ray->color);
			start++;
		}
	}
	else
	{
		while (start != end)
		{
			pixel_put_img(all, x, start, all->ray->color);
			start--;
		}
	}
}