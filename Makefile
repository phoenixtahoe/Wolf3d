# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pdavid <pdavid@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/05/30 19:50:54 by pdavid            #+#    #+#              #
#    Updated: 2018/12/16 11:45:10 by pdavid           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

libx_flags = -L ./includes/minilibx -lmlx -framework OpenGL -framework AppKit

cflags = -Wall -Wextra -Werror

make_libft = @make -C ./includes/libft/

make_mlx = @make -C ./includes/minilibx

header = ./includes/wolf3d.h

SRCDIR = src

SRCS	= $(addprefix $(SRCDIR)/, $(SRC))

includes = ./includes/libft/libft.a ./includes/minilibx/libmlx.a

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
	@$(cc) $(libx_flags) $(cflags) -g $(SRCS) $(includes) -o $(name)
	@printf "\e[1;32m$(name) Excutable Created!\e[0m\n"

clean:
	@printf "\e[1;32mCleaning!\e[0m\n"
	@make -C ./includes/minilibx/ clean
	@make -C ./includes/libft/ fclean
	@/bin/rm -f $(name)

fclean:
	@make -C ./includes/libft/ fclean
	@make -C ./includes/minilibx/ clean

re : fclean clean all