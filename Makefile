# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pdavid <pdavid@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/05/30 19:50:54 by pdavid            #+#    #+#              #
#    Updated: 2018/10/30 18:22:20 by pdavid           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

libx_flags = -L minilibx -fsanitize=address -lmlx -framework OpenGL -framework AppKit

cflags = -Wall -Wextra -Werror -lpthread

make_libft = @make -C ./libft/

make_mlx = @make -C ./minilibx/

header = wolf3d.h

includes = ./libft/libft.a ./minilibx/libmlx.a

SRC = main.c read.c ray.c mlx.c init.c tex.c

OBJ = *.o

cc = @gcc

name = wolf3d

all: $(name)

$(name):
	@$(make_mlx)
	@$(make_libft)
	@$(cc) $(libx_flags) $(cflags) -g $(SRC) $(includes) -o $(name)

clean:
	@make -C minilibx/ clean
	@make -C libft/ clean
	@/bin/rm -f $(name)

fclean:
	@make -C libft/ fclean
	@make -C minilibx/ clean

re : clean fclean all