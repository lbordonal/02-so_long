# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lbordona <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/22 12:24:12 by lbordona          #+#    #+#              #
#    Updated: 2023/04/18 13:03:29 by lbordona         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

CC = cc -g
CFLAGS = -Wall -Wextra -Werror
EXTRA = -lXext -lX11
RM = rm -rf
LIBFT = ./libft/libft.a
MINILIBX = ./minilibx-linux/libmlx.a

SRCS = srcs/main.c \
	srcs/events.c

OBJS = $(SRCS:%.c=%.o)

all: $(NAME)

$(LIBFT):
	@$(MAKE) -C ./libft

$(MINILIBX):
	@$(MAKE) -C ./minilibx-linux

$(NAME): $(OBJS) $(LIBFT) $(MINILIBX)
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(MINILIBX) $(EXTRA) -o $(NAME)

clean:
	@$(MAKE) clean -C ./libft
	@$(MAKE) clean -C ./minilibx-linux
	@$(RM) $(OBJS)

fclean: clean
	@$(MAKE) fclean -C ./libft
#	@$(MAKE) fclean -C ./minilibx-linux
	$(RM) $(NAME)

re: fclean all
