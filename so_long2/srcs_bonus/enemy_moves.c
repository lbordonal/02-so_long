/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_moves.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbordona <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 11:24:45 by lbordona          #+#    #+#             */
/*   Updated: 2023/08/28 12:08:04 by lbordona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

int	check_next_position_2(t_game *game, int x, int y)
{
	if (game->map[y][x] == BACKGROUND)
		return (1);
	if (game->map[y][x] == WALL)
		return (0);
	if (game->map[y][x] == COLLECTIBLE)
		return (0);
	if (game->map[y][x] == ENEMY)
		return (0);
	if (game->map[y][x] == PLAYER)
	{
		ft_printf("\033[0;32mYOU WERE VANISHED BY THANOS!\n");
		exit_game(game);
	}
	return (0);
}

void	enemy_random_move(t_game *game)
{
	int	random_move;

	random_move = rand() % 4;
	enemy_position(game, random_move);
}

int	enemy_position(t_game *game, int random_move)
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
			{
				enemy_move(game, i, j, random_move);
				if (random_move == 3)
					j++;
				if (random_move == 2)
					i++;
			}
			j++;
		}
		i++;
	}
	return (1);
}

void	enemy_move(t_game *game, int x, int y, int random_move)
{
	if (random_move == 0)
		if (check_next_position_2(game, x, (y - 1)) == 1)
			enemy_move_w(game, x, y);
	else if(random_move == 1)
		if (check_next_position_2(game, (x - 1), y) == 1)
			enemy_move_a(game, x, y);
	else if (random_move == 2)
		if (check_next_position_2(game, x, (y + 1)) == 1)
			enemy_move_s(game, x, y);
	else if(random_move == 3)
		if (check_next_position_2(game, (x + 1), y) == 1)
			enemy_move_d(game, x, y);
}
