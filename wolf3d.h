/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdavid <pdavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/30 20:08:10 by pdavid            #+#    #+#             */
/*   Updated: 2018/11/26 13:42:08 by pdavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H

# define HEIGHT 1000
# define WIDTH 1000
# define HEIGHT_MAP 18
# define WIDTH_MAP 18
# define TEXT 256

# include <time.h>
# include <stdio.h>
# include <unistd.h>
# include "libft/libft.h"
# include "minilibx/mlx.h"
# include <stdlib.h>
# include <fcntl.h>
# include <math.h>

typedef struct		s_xpm
{
	void			*xpm_floor;
	int				xpm_f_x;
	int				xpm_f_y;
	int				*xpm_f_addr;
	int				xpm_f_b;
	int				xpm_f_s;
	int				xpm_f_e;
}					t_xpm;

typedef struct		s_mlx
{
	void			*mlx;
	void			*image;
	int				*image_ptr;
	void			*window;
	int				endian;
	int				sl;
	int				bpp;
}					t_mlx;

typedef struct		s_ray
{
	double			planex;
	double			planey;
	double			posx;
	double			posy;
	int				mapx;
	int				mapy;
	double			sidedistx;
	double			sidedisty;
	double			dirx;
	double			diry;
	double			olddirx;
	double			oldplanex;
	double			camerax;
	double			raydirx;
	double			raydiry;
	double			deltadistx;
	double			deltadisty;
	double			perpwalldist;
	int				stepx;
	int				stepy;
	int				side;
	int				hit;
	int				lineheight;
	int				drawstart;
	int				drawend;
	double			wallx;
	double			distwall;
	double			distpos;
	double			distcurr;
	double			weight;
	double			currfloorx;
	double			currfloory;
	double			floorx;
	double			floory;
	int				texy;
	int				texx;
	int				textnum;
	int				d;
	int				color;
	int				floortexty;
	int				floortextx;
}					t_ray;

typedef struct		s_env
{
	t_ray			*ray;
	t_mlx			*mlx;
	t_xpm			xpm;
	int				**map;
	int				mapx;
	int				mapy;
	int				*text[5];
	int				x_max;
	int				y_max;
}					t_env;

void				draw(t_env *e);
void				init_xpm(t_env *e);
int					init_read(char *str, t_env *current);
t_env				*init_env(void);
t_ray				*init_ray(void);
void				ray_pre(t_env *e, int x);
void				ray_dir(t_env *e);
void				ray_dda(t_env *e);
void				ray_wall(t_env *e);
void				ray_floor(t_env *e);
void				init_text(t_env *e);
void				text_wall(t_env *e, int x);
void				text_floor(t_env *e, int x);
void				init_mlx(t_env *e);
int					keydown(int keycode, t_env *e);
int					up(int keycode, t_env *e);
int					down(int keycode, t_env *e);
int					left(int keycode, t_env *e);
int					right(int keycode, t_env *e);

#endif
