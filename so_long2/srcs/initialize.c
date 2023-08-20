/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbordona <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 21:47:25 by lbordona          #+#    #+#             */
/*   Updated: 2023/08/20 21:47:25 by lbordona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	initialize_tgame(t_game *game)
{
	game->mlx = 0;
	game->win = 0;
	game->map = 0;
	game->last_side = 0;
	game->lines = 0;
	game->columns = 0;
	game->n_collect = 0;
	game->p_collect = 0;
	game->n_exit = 0;
	game->x = 0;
	game->y = 0;
	game->player = 0;
	game->p_x = 0;
	game->p_y = 0;
	game->moves = 0;
}

void	imgs_init(t_game *game)
{
	game->img_background = mlx_xpm_file_to_image
		(game->mlx, BACKGROUND, &game->x, &game->y);
	game->img_wall = mlx_xpm_file_to_image
		(game->mlx, WALL, &game->x, &game->y);
	game->img_player_w = mlx_xpm_file_to_image
		(game->mlx, PLAYER_W, &game->x, &game->y);
	game->img_player_a = mlx_xpm_file_to_image
		(game->mlx, PLAYER_A, &game->x, &game->y);
	game->img_player_s = mlx_xpm_file_to_image
		(game->mlx, PLAYER_S, &game->x, &game->y);
	game->img_player_d = mlx_xpm_file_to_image
		(game->mlx, PLAYER_D, &game->x, &game->y);
	game->img_collect = mlx_xpm_file_to_image
		(game->mlx, COLLECT, &game->x, &game->y);
	game->img_exit = mlx_xpm_file_to_image
		(game->mlx, EXIT_IMG, &game->x, &game->y);
}

void	size_window_init(t_game *game)
{
	int	i;

	i = 0;
	game->columns = ft_strlen(game->map[0]) * 32;
	while (game->map[i])
		i++;
	game->lines = i * 32;
}

void	game_init(t_game *game)
{
	game->mlx = mlx_init();
	imgs_init(game);
	size_window_init(game);
	game->win = mlx_new_window(game->mlx, game->columns,
			game->lines, "so_long - miranha em busca do miojinho");
	draw_map(game);
}
