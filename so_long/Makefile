# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lbordona <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/22 12:24:12 by lbordona          #+#    #+#              #
#    Updated: 2023/03/18 00:17:06 by lbordona         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
EXTRA = -lXext -lX11
LIBFT = ./libft
MLX = libmlx_Linux.a
RM = rm -rf
NAME = so_long

MLXDIR = ./minilibx-linux/

SRCS = srcs/main.c \
	srcs/window_and_images.c \
	srcs/colors.c \
	srcs/forms.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(MLX):
	cd $(MLXDIR) && $(MAKE)

$(NAME): $(OBJS) $(MINILIBX)
	$(MAKE) -C ./libft
	$(CC) $(CFLAGS) $(OBJS) $(MLXDIR)$(MLX) $(EXTRA) -o $(NAME)


bonus: all

clean:
	$(MAKE) clean -C ./libft
#	$(MAKE) clean -C ./minilibx-linux
	$(RM) $(OBJS)

fclean: clean
	$(MAKE) fclean -C ./libft
	cd $(MLXDIR) && $(MAKE) clean
	$(RM) $(NAME)

re: fclean all
