/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbordona <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 21:03:27 by lbordona          #+#    #+#             */
/*   Updated: 2023/08/20 21:03:27 by lbordona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	player_move_w(t_game *game)
{
	mlx_put_image_to_window(game->mlx, game->win,
		game->img_background, game->p_x * 32, game->p_y * 32);
	mlx_put_image_to_window(game->mlx, game->win,
		game->img_player_w, game->p_x * 32, (game->p_y - 1) * 32);
	game->p_y--;
	game->moves++;
	ft_printf("%s%d\n", "Moves: ", game->moves);
}

void	player_move_a(t_game *game)
{
	mlx_put_image_to_window(game->mlx, game->win,
		game->img_background, game->p_x * 32, game->p_y * 32);
	mlx_put_image_to_window(game->mlx, game->win,
		game->img_player_a, (game->p_x - 1) * 32, game->p_y * 32);
	game->last_side = 'A';
	game->p_x--;
	game->moves++;
	ft_printf("%s%d\n", "Moves: ", game->moves);
}

void	player_move_s(t_game *game)
{
	mlx_put_image_to_window(game->mlx, game->win,
		game->img_background, game->p_x * 32, game->p_y * 32);
	mlx_put_image_to_window(game->mlx, game->win,
		game->img_player_s, game->p_x * 32, (game->p_y + 1) * 32);
	game->p_y++;
	game->moves++;
	ft_printf("%s%d\n", "Moves: ", game->moves);
}

void	player_move_d(t_game *game)
{
	mlx_put_image_to_window(game->mlx, game->win,
		game->img_background, game->p_x * 32, game->p_y * 32);
	mlx_put_image_to_window(game->mlx, game->win,
		game->img_player_d, (game->p_x + 1) * 32, game->p_y * 32);
	game->last_side = 'D';
	game->p_x++;
	game->moves++;
	ft_printf("%s%d\n", "Moves: ", game->moves);
}

int		make_move(t_game *game, char key)
{
	if ((key == 'W' || key == 'UP') && check_wall(game, 'W'))
		player_move_w(game);
	if ((key == 'A' || key == 'LEFT') && check_wall(game, 'A'))
		player_move_a(game);
	if ((key == 'S' || key == 'DOWN') && check_wall(game, 'S'))
		player_move_s(game);
	if ((key == 'D' || key == 'RIGHT') && check_wall(game, 'D'))
		player_move_d(game);
	if (game->map[game->p_y][game->p_x] == 'C')
	{
		game->p_collect++;
		game->map[game->p_y][game->p_x] == '0'
	}
	if (game->map[game->p_y][game->p_x] == 'E'
		&& game->p_collect == game->n_collect)
	{
		ft_printf("\033[0;32mYOU HELPED THOR TO SAVE THE WORLD FROM THANOS!\n");
		exit_game(game);
	}
	return (0);
}
