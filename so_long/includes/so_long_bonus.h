/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbordona <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 12:31:51 by lbordona          #+#    #+#             */
/*   Updated: 2023/05/31 13:38:34 by lbordona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include "../libft/libft.h"
# include "../minilibx-linux/mlx.h"
# include <X11/X.h>
# include <X11/keysym.h>

# define BACKGROUND "./assets/images/0.xpm"
# define WALL "./assets/images/1.xpm"
# define PLAYER_W "./assets/images/PW.xpm"
# define PLAYER_S "./assets/images/PS.xpm"
# define PLAYER_A "./assets/images/PA.xpm"
# define PLAYER_D "./assets/images/PD.xpm"
# define COLLECT "./assets/images/C.xpm"
# define EXIT_IMG "./assets/images/E.xpm"
# define EXIT_IMG2 "./assets/images/E2.xpm"
# define ENEMY_W "./assets/images/ENW.xpm"
# define ENEMY_S "./assets/images/ENS.xpm"
# define ENEMY_A "./assets/images/ENA.xpm"
# define ENEMY_D "./assets/images/END.xpm"
# define W 119
# define A 97
# define S 115
# define D 100
# define UP 65362
# define LEFT 65361
# define DOWN 65364
# define RIGHT 65363

typedef struct s_game
{
	void	*mlx;
	void	*win;
	char	**map;
	void	*img_background;
	void	*img_wall;
	void	*img_player;
	void	*img_enemy;
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
char	**read_map(char *path);

/* map.c: */
int		map_checker(t_game *game);

/* initialize.c: */
void	game_init(t_game *game);

/* player_moves.c: */
void	player_move_w(t_game *game);
void	player_move_a(t_game *game);
void	player_move_s(t_game *game);
void	player_move_d(t_game *game);

/* draw.c: */
void	draw_img(t_game *game, void *img, int x, int y);
int		draw_map(t_game *game);

/* events.c: */
void	imgs_init(t_game *game);
void	size_window_init(t_game *game);
void	game_play(t_game *game);

/* exit_and_free.c: */
void	free_map(char **map);
int		exit_game(t_game *game);

#endif
