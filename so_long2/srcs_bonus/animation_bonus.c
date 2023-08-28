/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbordona <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 10:52:14 by lbordona          #+#    #+#             */
/*   Updated: 2023/08/28 12:56:16 by lbordona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

void	change_enemy_img(t_game *game, int x, int y, int flag)
{
	x *= SIZE;
	y *= SIZE;
	if (flag == 0)
	{
		mlx_put_image_to_window(game->mlx, game->win,
		game->img_enemy_a, x, y);
	}
	if (flag == 1)
	{
		mlx_put_image_to_window(game->mlx, game->win,
		game->img_enemy_d, x, y);
	}
}

void	enemy_animation(t_game *game, int flag)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->map_rows)
	{
		j = 0;
		while (j < game->map_cols)
		{
			if (game->map[i][j] == ENEMY)
				change_enemy_img(game, j, i, flag);
			j++;
		}
		i++;
	}
}

int	animations(t_game *game)
{
	static int	i;
	int			num;

	num = 10000;
	i++;
	if (i == num * 2)
		enemy_animation(game, 0);
	if (i == num * 3)
		enemy_random_move(game);
	if (i == num * 4)
	{
		enemy_animation(game, 1);
		i = 0;
	}
	return (1);
}
