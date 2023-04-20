/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbordona <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 16:22:50 by lbordona          #+#    #+#             */
/*   Updated: 2023/04/20 19:01:13 by lbordona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	draw_img(t_game *game, void *img, int x, int y)
{
	x *= 32;
	y *= 32;
	mlx_put_image_to_window(game->mlx, game->win, img, x, y);
}

void	draw_player(t_game *game, void *img, int x, int y)
{
	game->player_x = x;
	game->player_y = y;
	draw_img(game, img, x, y);
}

void	draw_exit(t_game *game, int x, int y)
{
	if (game->n_collect == 0)
	{
		mlx_destroy_image(game->mlx, game->img_exit);
		game->img_exit = mlx_xpm_file_to_image(game->mlx,
			EXIT, &game->img_width, &game->img_height);
	}
	draw_img(game, game->img_exit, x, y);
}

int	draw_map(t_game *game)
{
	int	x;
	int	y;

	x = 0;
	while (game->map[x])
	{
		y = 0;
		while (game->map[x][y])
		{
			if (game->map[x][y] == '0')
				draw_img(game, game->img_background, x, y);
			else if (game->map[x][y] == '1')
				draw_img(game, game->img_wall, x, y);
			else if (game->map[x][y] == 'P')
				draw_player(game, game->img_player, x, y);
			else if (game->map[x][y] == 'C')
				draw_img(game, game->img_collect, x, y);
			else if (game->map[x][y] == 'E')
				draw_exit(game->img_exit, x, y);
			x++;
		}
		y++;
	}
	return (0);
}

