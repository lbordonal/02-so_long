/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbordona <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 12:31:51 by lbordona          #+#    #+#             */
/*   Updated: 2023/04/20 19:07:02 by lbordona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/libft.h"
# include "../minilibx-linux/mlx.h"
# include <X11/X.h>
# include <X11/keysym.h>

# ifndef RED_PIXEL
#  define RED_PIXEL 0xFF0000
# endif

# ifndef GREEN_PIXEL
#  define GREEN_PIXEL 0x00FF00
# endif

# ifndef BLUE_PIXEL
#  define BLUE_PIXEL 0x0000FF
# endif

# define BACKGROUND "./assets/images/0.xpm"
# define WALL "./assets/images/1.xpm"
# define PLAYER_W "./assets/images/PW.xpm"
# define PLAYER_S "./assets/images/PS.xpm"
# define PLAYER_A "./assets/images/PA.xpm"
# define PLAYER_D "./assets/images/PD.xpm"
# define COLLECT "./assets/images/C.xpm"
# define EXIT "./assets/images/E.xpm"

typedef struct s_game
{
	void	*mlx;
	void	*win;
	char	**map;
	void	*img_background;
	void	*img_wall;
	void	*img_player;
	void	*img_collect;
	void	*img_exit;
	int		map_width;
	int		map_height;
	int		img_width;
	int		img_height;
	int		n_collect;
	int		n_player;
	int		n_exit;
	int		player_x;
	int		player_y;
	int		moves;
	int		endgame;
}	t_game;

/* main.c: */
int		map_extension_checker(char *map);
char	**read_map(char *path);

/* map.c: */
int		map_is_retangular(char **map);
int		map_wall_is_valid(char **map);
int		map_is_correct(char **map);
int		map_is_functional(t_game *game);
int		map_checker(t_game *game);

/* initialize.c: */
void	imgs_init(t_game *game);
void	size_window_init(t_game *game);
void	game_init(t_game *game);

/* player_moves.c: */
void	player_move_w(t_game *game);
void	player_move_a(t_game *game);
void	player_move_s(t_game *game);
void	player_move_d(t_game *game);
void	player_update(char key, t_game *game);

/* draw.c: */
void	draw_img(t_game *game, void *img, int x, int y);
void	draw_player(t_game *game, void *img, int x, int y);
void	draw_exit(t_game *game, int x, int y);
int		draw_map(t_game *game);

/* events.c: */
void	game_events(int key, t_game *game);
int		handle_keypress(int key, t_game *game);
void	game_play(t_game *game);

/* exit_and_free.c: */
void	free_map(char **map);
int		exit_game(t_game *game);

#endif
