/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbordona <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 12:31:51 by lbordona          #+#    #+#             */
/*   Updated: 2023/06/10 11:44:12 by lbordona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

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
	void	*img_player_w; //new
	void	*img_player_a; //new
	void	*img_player_s; //new
	void	*img_player_d; //new
	void	*img_collect;
	void	*img_exit;
	char	last_side; //new
	int		lines; //new
	int		columns; //new
	int		n_collect;
	int		p_collect; //new
	int		n_exit;
	int		x; //new
	int		y; //new
	int		player; //new
	int		p_x;
	int		p_y;
	int		moves;
}	t_game;

/* main.c: */
char	**read_map(char *path);

/* map.c: */
int		map_checker(t_game *game);

/* initialize.c: */
void	initialize_tgame(t_game *game)
void	game_init(t_game *game);
void	size_window_init(t_game *game);
void	imgs_init(t_game *game);

/* player_moves.c: -- DONE */
void	player_move_w(t_game *game);
void	player_move_a(t_game *game);
void	player_move_s(t_game *game);
void	player_move_d(t_game *game);
int		make_move(t_game *game, char key);

/* draw.c: */
void	draw_img(t_game *game, void *img, int x, int y);
int		draw_map(t_game *game);

/* events.c: */
void	game_play(t_game *game);

/* exit_and_free.c: */
void	free_map(char **map);
int		exit_game(t_game *game);

#endif
