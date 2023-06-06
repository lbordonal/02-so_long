/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_moves.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbordona <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 18:09:15 by lbordona          #+#    #+#             */
/*   Updated: 2023/06/06 19:24:11 by lbordona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

/*Get a random move for the enemy*/
void	random_move(t_stack *stack)
{
	int random_move;

	random_move = rand() % 4;
	enemy_position(stack, random_move);
}

/*Function to check with miscellaneous is next in the window,
to know where to move the enemy*/
int	check_next_window(t_game *game)
{
	if (game->map[game->player_y][game->player_x] == 0)
		return (1);
	if (game->map[game->player_y][game->player_x] == 1)
		return (0);
	if (game->map[game->player_y][game->player_x] == 'C')
		return (0);
	if (game->map[game->player_y][game->player_x] == 'T')
		return (0);
	if (game->map[game->player_y][game->player_x] == 'P')
	{
		you_are_vanished(game);
	}
	return (0);
}

/*Get enemy position*/
int	enemy_position(t_game *game, int random_move)
{
	int	i;
	int	j;

	i = 0;
	while (i < rows)
	{
		j = 0;
		while (j < columns)
		{
			if (game->map[i][j] == 'T')
			{
				enemy_move(stack, j, i, random_move);
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

/*Function to change enemy on the window and the map*/
void	enemy_move(t_stack *stack, int x, int y, int random_move)
{
	if (random_move == 0)
	{
		if (check_next_window(stack, x, y - 1) == 1)
			change_enemy_image_w(stack, x, y);
	}
	else if (random_move == 1)
	{
		if (check_next_window(stack, x - 1, y) == 1)
			change_enemy_image_a(stack, x, y);
	}
	else if (random_move == 2)
	{
		if (check_next_window(stack, x, y + 1) == 1)
			change_enemy_image_s(stack, x, y);
	}
	else if (random_move == 3)
	{
		if (check_next_window(stack, x + 1, y) == 1)
			change_enemy_image_d(stack, x, y);
	}
}

/*Function for the loop hook to keep collectibles and enemy moving*/
int	animations(t_stack *stack)
{
	static int	i;
	int			num;

	num = 20000;
	i++;
	if (i == num * 2)
		collectible_animation(stack, 0);
	if (i == num * 3)
		random_move(stack);
	if (i == num * 4)
	{
		collectible_animation(stack, 1);
		i = 0;
	}
	return (1);
}
