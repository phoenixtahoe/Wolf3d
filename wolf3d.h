/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdavid <pdavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/30 20:08:10 by pdavid            #+#    #+#             */
/*   Updated: 2018/06/01 23:59:35 by pdavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H

# define HEIGHT 800
# define WIDTH 800
# define HEIGHT_MAP 18
# define WIDTH_MAP 20
# define pink 0xFF7B7B
# define green 0x7BFF7F
# define purple 0xBD7BFF
# define blue 0x000b7E

# include <time.h>
# include <stdio.h>
# include <unistd.h>
# include <pthread.h>
# include "libft/libft.h"
# include "minilibx/mlx.h"
# include <stdlib.h>
# include <fcntl.h>
# include "math.h"

typedef struct		s_events
{
	int				w;
	int				a;
	int				s;
	int				d;
}					t_events;

typedef struct      s_mlx
{
    void            *mlx;
    void            *image;
    void            *image_ptr;
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
	double			frametime;
}					t_ray;

typedef struct      s_env
{
    t_player        *player;
    t_ray           *ray;
    t_mlx           *mlx;
	t_events		*events;
    int             **map;
    int             x_max;
    int             y_max;    
}                   t_env;


int 				keydown(int keycode, t_env *all);
int                 ft_initread(char *str, t_env *all);
int                 ft_reopen(char *str, int y, t_env *all);
int                 ft_countnum(char *str);
int                 *parse(char *str, int x);
int                 draw(t_env *all); 
void                ft_exit(t_env *all);
void				draw_vert(int x, int start, int end, t_env *all);
t_env				*init_env(void);
t_events			*init_events(void);
t_ray				*init_ray(void);

#endif