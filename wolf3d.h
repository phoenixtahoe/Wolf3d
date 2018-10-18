/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdavid <pdavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/30 20:08:10 by pdavid            #+#    #+#             */
/*   Updated: 2018/10/18 15:33:42 by pdavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H

# define HEIGHT 800
# define WIDTH 800
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

typedef struct		s_events
{
	int				w;
	int				a;
	int				s;
	int				d;
}					t_events;

typedef struct		s_xpm
{
	void		*xpm_floor;
	int			xpm_f_x;
	int			xpm_f_y;
	int			*xpm_f_addr;
	int			xpm_f_b;
	int			xpm_f_s;
	int			xpm_f_e;
	void		*xpm_ceiling;
	int			xpm_c_x;
	int			xpm_c_y;
	int			*xpm_c_addr;
	int			xpm_c_b;
	int			xpm_c_s;
	int			xpm_c_e;
	void		*xpm_wall;
	int			xpm_w_x;
	int			xpm_w_y;
	int			*xpm_w_addr;
	int			xpm_w_b;
	int			xpm_w_s;
	int			xpm_w_e;
}					t_xpm;

typedef struct      s_mlx
{
    void            *mlx;
    void            *image;
    int            *image_ptr;
    void            *window;
    int             endian;
    int             sl;
    int             bpp;
}                   t_mlx;

typedef struct      s_player
{
    double          x;
    double          y;
    double          viewangle;
}                   t_player;

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
	double			time;
	double			oldtime;
	int				lineheight;
	int				drawstart;
	int				drawend;
	int				color;
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
	int				floortexty;
	int				floortextx;
	double			frametime;
}					t_ray;

typedef struct      s_env
{
    t_player        *player;
	t_events		*events;
    t_ray           *ray;
    t_mlx           *mlx;
	t_xpm			xpm;
	int				bytes_read;
    int             **map;
	int				*text[5];
    int             x_max;
    int             y_max;    
}                   t_env;


int 				keydown(int keycode, t_env *all);
int                 ft_initread(char *str, t_env *all);
int                 *parse(char *str, int x);
void				draw(t_env *e);
t_env 				*init_env(void);
t_ray				*init_ray(void);
void 				init_text(t_env *e);
void				sky(t_env *e, int x);
void				wall(t_env *e, int x);
void 				init_mlx(t_env *e);

#endif