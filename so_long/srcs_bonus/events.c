/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbordona <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 12:46:54 by lbordona          #+#    #+#             */
/*   Updated: 2023/05/31 15:19:48 by lbordona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

static void	game_events(int key, t_game *game)
{
	if (key == XK_w || key == XK_Up)
	{
		game->player_y -= 1;
		player_move_w(game);
	}
	else if (key == XK_s || key == XK_Down)
	{
		game->player_y += 1;
		player_move_s(game);
	}
	else if (key == XK_a || key == XK_Left)
	{
		game->player_x -= 1;
		player_move_a(game);
	}
	else if (key == XK_d || key == XK_Right)
	{
		game->player_x += 1;
		player_move_d(game);
	}
}

static int	handle_keypress(int key, t_game *game)
{
	if (key == XK_Escape)
	{
		exit_game(game);
	}
	else if (!game->endgame)
	{
		game_events(key, game);
		ft_printf("%s%d\n", "Moves: ", game->moves);
	}
	return (0);
}

void	game_play(t_game *game)
{
	mlx_hook(game->win, KeyPress, KeyPressMask, handle_keypress, game);
	mlx_hook(game->win, DestroyNotify, ButtonPressMask, exit_game, game);
	mlx_hook(game->win, 9, 1L << 21, draw_map, game);
	mlx_loop_hook(game->mlx, animation, game);
}
