/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbordona <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 17:35:29 by lbordona          #+#    #+#             */
/*   Updated: 2023/08/27 17:35:29 by lbordona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	free_map(char **map)
{
	int	i;

	i = 0;
	while (i < game->map_rows)
	{
		free(game->map[i]);
		i++;
	}
	free(game->map);
}

void	exit_game(t_game *game)
{
	free_map(game->map);
	free_map(game->temp_map);
	mlx_destroy_image(game->mlx, game->img_player_w);
	mlx_destroy_image(game->mlx, game->img_player_a);
	mlx_destroy_image(game->mlx, game->img_player_s);
	mlx_destroy_image(game->mlx, game->img_player_d);
	mlx_destroy_image(game->mlx, game->img_exit);
	mlx_destroy_image(game->mlx, game->img_collect);
	mlx_destroy_image(game->mlx, game->img_background);
	mlx_destroy_image(game->mlx, game->wall);
	mlx_destroy_window(game->mlx, game->win);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
	exit
}

