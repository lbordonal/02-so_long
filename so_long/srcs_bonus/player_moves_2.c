/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_moves_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbordona <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 14:39:15 by lbordona          #+#    #+#             */
/*   Updated: 2023/05/31 17:09:58 by lbordona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

void	show_moves(t_game *game)
{
	char	*moves;

	moves = ft_itoa(game->moves);
	mlx_string_put(game->mlx, game->win, 25, 20, 0xFFFFFF, "Moves: ");
	mlx_string_put(game->mlx, game->win, 70, 20, 0xFFFFFF, moves);
	free(moves);
}

void	you_are_vanished(t_game *game)
{
	ft_printf("\033[0;31m😵 YOU GOT INFECTED 😵 \n");
	exit_game(game);
}

int	animation(t_game *game)
{
	if (game->loop < 1000)
	{
		game->loop++;
		return (0);
	}
	game->loop = 0;
	mlx_destroy_image(game->mlx, game->img_enemy);
	if (game->pos_enemies == 1)
		game->img_enemy = mlx_xpm_file_to_image
			(game->mlx, ENEMY_W, &game->img_width, &game->img_height);
	else if (game->pos_enemies == 2)
		game->img_enemy = mlx_xpm_file_to_image
			(game->mlx, ENEMY_S, &game->img_width, &game->img_height);
	else if (game->pos_enemies == 3)
		game->img_enemy = mlx_xpm_file_to_image
			(game->mlx, ENEMY_A, &game->img_width, &game->img_height);
	else if (game->pos_enemies == 4)
	{
		game->img_enemy = mlx_xpm_file_to_image
			(game->mlx, ENEMY_D, &game->img_width, &game->img_height);
		game->pos_enemies = 0;
	}
	draw_map(game);
	game->pos_enemies++;
	return (0);
}
