# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lbordona <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/22 12:24:12 by lbordona          #+#    #+#              #
#    Updated: 2023/08/28 10:04:47 by lbordona         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
NAME_BONUS = so_long_bonus

CC = cc -g
CFLAGS = -Wall -Wextra -Werror
EXTRA = -lXext -lX11
RM = rm -rf
LIBFT = ./libft/libft.a
MINILIBX = ./minilibx-linux/libmlx.a

SRCS = srcs/draw.c \
	srcs/free.c \
	srcs/game_and_events.c \
	srcs/initialize.c \
	srcs/main.c \
	srcs/map_checker.c \
	srcs/map_checker_structs.c \
	srcs/player_moves.c \
	srcs/player_moves_2.c \
	srcs/utils.c

SRCS_BONUS = srcs/draw_bonus.c \
	srcs/free_bonus.c \
	srcs/game_and_events_bonus.c \
	srcs/initialize_bonus.c \
	srcs/main_bonus.c \
	srcs/map_checker_bonus.c \
	srcs/map_checker_structs_bonus.c \
	srcs/player_moves_bonus.c \
	srcs/player_moves_2_bonus.c \
	srcs/utils_bonus.c

OBJS = $(SRCS:%.c=%.o)
OBJS_BONUS = $(SRCS_BONUS:%.c=%.o)

all: $(NAME)

$(LIBFT):
	@$(MAKE) -C ./libft

$(MINILIBX):
	@$(MAKE) -C ./minilibx-linux

$(NAME): $(OBJS) $(LIBFT) $(MINILIBX)
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(MINILIBX) $(EXTRA) -o $(NAME)

bonus: $(OBJS_BONUS) $(LIBFT) $(MINILIBX)
	@$(CC) $(CFLAGS) $(OBJS_BONUS) $(LIBFT) $(MINILIBX) $(EXTRA) -o $(NAME_BONUS)

clean:
	@$(MAKE) clean -C ./libft
	@$(MAKE) clean -C ./minilibx-linux
	@$(RM) $(OBJS) $(OBJS_BONUS)

fclean: clean
	@$(MAKE) fclean -C ./libft
#	@$(MAKE) fclean -C ./minilibx-linux
	$(RM) $(NAME) $(NAME_BONUS)

re: fclean all
