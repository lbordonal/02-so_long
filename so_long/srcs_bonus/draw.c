/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbordona <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 16:22:50 by lbordona          #+#    #+#             */
/*   Updated: 2023/06/05 15:00:17 by lbordona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

void	draw_img(t_game *game, void *img, int x, int y)
{
	x *= 32;
	y = y * 32 + 32;
	mlx_put_image_to_window(game->mlx, game->win, img, x, y);
}

static void	draw_player(t_game *game, void *img, int x, int y)
{
	game->player_x = x;
	game->player_y = y;
	draw_img(game, img, x, y);
}

int	draw_map(t_game *game)
{
	int	x;
	int	y;

	y = -1;
	while (game->map[++y])
	{
		x = -1;
		while (game->map[y][++x])
		{
			if (game->map[y][x] == '0')
				draw_img(game, game->img_background, x, y);
			else if (game->map[y][x] == '1')
				draw_img(game, game->img_wall, x, y);
			else if (game->map[y][x] == 'P')
				draw_player(game, game->img_player, x, y);
			else if (game->map[y][x] == 'C')
				draw_img(game, game->img_collect, x, y);
			else if (game->map[y][x] == 'E')
				draw_img(game, game->img_exit, x, y);
			else if (game->map[y][x] == 'T')
				draw_img(game, game->img_enemy, x, y);
		}
	}
	show_moves(game);
	return (0);
}
