/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbordona <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 13:34:42 by lbordona          #+#    #+#             */
/*   Updated: 2023/05/31 13:40:41 by lbordona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

static void	enemy_update(char key, t_game *game)
{
	mlx_destroy_image(game->mlx, game->img_enemy);
	if (key == XK_w)
		game->img_enemy = mlx_xpm_file_to_image
			(game->mlx, ENEMY_W, &game->img_width, &game->img_height);
	else if (key == XK_s)
		game->img_enemy = mlx_xpm_file_to_image
			(game->mlx, ENEMY_S, &game->img_width, &game->img_height);
	else if (key == XK_a)
		game->img_enemy = mlx_xpm_file_to_image
			(game->mlx, ENEMY_A, &game->img_width, &game->img_height);
	else if (key == XK_d)
		game->img_enemy = mlx_xpm_file_to_image
			(game->mlx, ENEMY_D, &game->img_width, &game->img_height);
}

