/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_moves_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbordona <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 11:52:56 by lbordona          #+#    #+#             */
/*   Updated: 2023/08/28 12:59:09 by lbordona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

void	enemy_move_w(t_game *game, int x, int y)
{
	mlx_put_image_to_window(game->mlx, game->win,
		game->img_background, (x * SIZE), (y * SIZE));
	mlx_put_image_to_window(game->mlx, game->win,
		game->img_enemy_w, (x * SIZE), ((y - 1) * SIZE));
	game->map[y][x] = BACKGROUND;
	game->map[y - 1][x] = ENEMY;
}

void	enemy_move_a(t_game *game, int x, int y)
{
	mlx_put_image_to_window(game->mlx, game->win,
		game->img_background, (x * SIZE), (y * SIZE));
	mlx_put_image_to_window(game->mlx, game->win,
		game->img_enemy_a, ((x - 1) * SIZE), (y * SIZE));
	game->map[y][x] = BACKGROUND;
	game->map[y][x - 1] = ENEMY;
}

void	enemy_move_s(t_game *game, int x, int y)
{
	mlx_put_image_to_window(game->mlx, game->win,
		game->img_background, (x * SIZE), (y * SIZE));
	mlx_put_image_to_window(game->mlx, game->win,
		game->img_enemy_s, (x * SIZE), ((y + 1) * SIZE));
	game->map[y][x] = BACKGROUND;
	game->map[y + 1][x] = ENEMY;
}

void	enemy_move_d(t_game *game, int x, int y)
{
	mlx_put_image_to_window(game->mlx, game->win,
		game->img_background, (x * SIZE), (y * SIZE));
	mlx_put_image_to_window(game->mlx, game->win,
		game->img_enemy_d, ((x + 1) * SIZE), (y * SIZE));
	game->map[y][x] = BACKGROUND;
	game->map[y][x + 1] = ENEMY;
}
