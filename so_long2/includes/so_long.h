/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbordona <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 12:58:08 by lbordona          #+#    #+#             */
/*   Updated: 2023/08/27 12:58:08 by lbordona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

/* Includes: */
# include "../libft/libft.h"
# include "../minilibx-linux/mlx.h"
# include <X11/X.h>
# include <X11/keysym.h>

/* Define parameters: */
# define PLAYER 'P'
# define EXIT 'E'
# define COLLECTIBLE 'C'
# define WALL '1'
# define BACKGROUND '0'

/* Define images: */
# define PLAYER_W "./assets/images/PW.xpm"
# define PLAYER_S "./assets/images/PS.xpm"
# define PLAYER_A "./assets/images/PA.xpm"
# define PLAYER_D "./assets/images/PD.xpm"
# define EXIT_IMG "./assets/images/E.xpm"
# define COLLECT_IMG "./assets/images/C.xpm"
# define WALL_IMG "./assets/images/1.xpm"
# define BACKGROUND_IMG "./assets/images/0.xpm"

/* Define keys: */
# define W 119
# define A 97
# define S 115
# define D 100
# define UP 65362
# define LEFT 65361
# define DOWN 65364
# define RIGHT 65363

/* Game structure: */
typedef struct s_game
{
	void	*mlx;
	void	*win;
	void	*img_player_w;
	void	*img_player_a;
	void	*img_player_s;
	void	*img_player_d;
	void	*img_exit;
	void	*img_collect;
	void	*img_wall;
	void	*img_background;
	char	**map;
	char	**check_map;
	int		img_width;
	int		img_height;
	int		map_rows;
	int		map_cols;
	int		player;
	int		pos_x;
	int		pos_y;
	int		exit;
	int		collect;
	int		n_collect;
	int		wall;
	int		background;
	int		moves;
}	t_game;

/* Functions: */

#endif
