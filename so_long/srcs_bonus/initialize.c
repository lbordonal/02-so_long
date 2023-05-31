/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbordona <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 14:03:41 by lbordona          #+#    #+#             */
/*   Updated: 2023/05/31 14:59:12 by lbordona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

void	imgs_init(t_game *game)
{
	game->img_background = mlx_xpm_file_to_image
		(game->mlx, BACKGROUND, &game->img_width, &game->img_height);
	game->img_wall = mlx_xpm_file_to_image
		(game->mlx, WALL, &game->img_width, &game->img_height);
	game->img_player = mlx_xpm_file_to_image
		(game->mlx, PLAYER_D, &game->img_width, &game->img_height);
	game->img_collect = mlx_xpm_file_to_image
		(game->mlx, COLLECT, &game->img_width, &game->img_height);
	game->img_exit = mlx_xpm_file_to_image
		(game->mlx, EXIT_IMG, &game->img_width, &game->img_height);
	game->img_enemy = mlx_xpm_file_to_image
		(game->mlx, ENEMY_D, &game->img_width, &game->img_height);
}

void	size_window_init(t_game *game)
{
	int	i;

	i = 0;
	game->map_width = ft_strlen(game->map[0]) * 32;
	while (game->map[i])
		i++;
	game->map_height = i * 32 + 32;
}

void	game_init(t_game *game)
{
	game->mlx = mlx_init();
	size_window_init(game);
	game->win = mlx_new_window(game->mlx, game->map_width,
			game->map_height, "so_long - miranha em busca do miojinho");
	game->moves = 0;
	game->endgame = 0;
	game->pos_enemies = 1;
	game->loop = 0;
	imgs_init(game);
	draw_map(game);
}
