/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbordona <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 10:52:14 by lbordona          #+#    #+#             */
/*   Updated: 2023/08/28 17:52:57 by lbordona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

void	change_collect_img(t_game *game, int x, int y, int flag)
{
	x *= SIZE;
	y *= SIZE;
	if (flag == 0)
	{
		mlx_put_image_to_window(game->mlx, game->win,
		game->img_collect, x, y);
	}
	if (flag == 1)
	{
		mlx_put_image_to_window(game->mlx, game->win,
		game->img_collect2, x, y);
	}
}

void	collect_animation(t_game *game, int flag)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->map_rows)
	{
		j = 0;
		while (j < game->map_cols)
		{
			if (game->map[i][j] == COLLECTIBLE)
				change_collect_img(game, j, i, flag);
			j++;
		}
		i++;
	}
}
