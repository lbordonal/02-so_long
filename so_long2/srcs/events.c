/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbordona <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 12:46:54 by lbordona          #+#    #+#             */
/*   Updated: 2023/04/27 15:10:13 by lbordona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static int	handle_keypress(int key, t_game *game)
{
	if (key == XK_Escape)
	{
		exit_game(game);
	}
	/* else if (!game->endgame)
	{
		game_events(key, game);
		ft_printf("%s%d\n", "Moves: ", game->moves);
	} */
	return (0);
}

void	game_play(t_game *game)
{
	mlx_hook(game->win, KeyPress, KeyPressMask, handle_keypress, game);
	mlx_hook(game->win, DestroyNotify, ButtonPressMask, exit_game, game);
	mlx_hook(game->win, 9, 1L << 21, draw_map, game);
}
