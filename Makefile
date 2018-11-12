# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pdavid <pdavid@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/05/30 19:50:54 by pdavid            #+#    #+#              #
#    Updated: 2018/11/06 13:45:01 by pdavid           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

libx_flags = -L minilibx -lmlx -framework OpenGL -framework AppKit

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
	@printf "\e[1;31mMaking mlx\e[0m\n"
	@$(make_mlx)
	@printf "\e[1;32mlibmlx.a Created!\e[0m\n"
	@printf "\e[1;31mMaking libft\e[0m\n"
	@$(make_libft)
	@printf "\e[1;31mMaking $(name)\e[0m\n"
	@$(cc) $(libx_flags) $(cflags) -g $(SRC) $(includes) -o $(name)
	@printf "\e[1;32m$(name) Excutable Created!\e[0m\n"

clean:
	@printf "\e[1;32mCleaning!\e[0m\n"
	@make -C minilibx/ clean
	@make -C libft/ fclean
	@/bin/rm -f $(name)

fclean:
	@make -C libft/ fclean
	@make -C minilibx/ clean

re : clean all