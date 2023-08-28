/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbordona <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 19:00:04 by lbordona          #+#    #+#             */
/*   Updated: 2023/08/28 13:07:40 by lbordona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

/* void	show_moves(t_game *game)
{
	char	*moves;

	moves = ft_itoa(game->moves);
	mlx_string_put(game->mlx, game->win, 25, 20, 0xFFFFFF, "Moves: ");
	mlx_string_put(game->mlx, game->win, 70, 20, 0xFFFFFF, moves);
	free(moves);
} */

void	draw_img(t_game *game, void *img, int x, int y)
{
	x *= SIZE;
	y *= SIZE + SIZE;
	mlx_put_image_to_window(game->mlx, game->win, img, x, y);
}

void	draw_map(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->map_rows)
	{
		x = 0;
		while (x < game->map_cols)
		{
			if (game->map[y][x] == PLAYER)
				draw_img(game, game->img_player_d, x, y);
			else if (game->map[y][x] == EXIT)
				draw_img(game, game->img_exit, x, y);
			else if (game->map[y][x] == COLLECTIBLE)
				draw_img(game, game->img_collect, x, y);
			else if (game->map[y][x] == WALL)
				draw_img(game, game->img_wall, x, y);
			else if (game->map[y][x] == BACKGROUND)
				draw_img(game, game->img_background, x, y);
			else if (game->map[y][x] == ENEMY)
				draw_img(game, game->img_enemy_a, x, y);
			x++;
		}
		y++;
	}
	mlx_string_put(game->mlx, game->win,
		10, 15, 000000, "Moves:  ");
	mlx_string_put(game->mlx, game->win,
		50, 15, 000000,"0");
	//show_moves(game);
}

