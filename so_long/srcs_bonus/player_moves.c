/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_moves.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbordona <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 18:15:41 by lbordona          #+#    #+#             */
/*   Updated: 2023/04/21 18:25:07 by lbordona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

static void	player_update(char key, t_game *game)
{
	mlx_destroy_image(game->mlx, game->img_player);
	if (key == XK_w)
		game->img_player = mlx_xpm_file_to_image
			(game->mlx, PLAYER_W, &game->img_width, &game->img_height);
	else if (key == XK_s)
		game->img_player = mlx_xpm_file_to_image
			(game->mlx, PLAYER_S, &game->img_width, &game->img_height);
	else if (key == XK_a)
		game->img_player = mlx_xpm_file_to_image
			(game->mlx, PLAYER_A, &game->img_width, &game->img_height);
	else if (key == XK_d)
		game->img_player = mlx_xpm_file_to_image
			(game->mlx, PLAYER_D, &game->img_width, &game->img_height);
}

void	player_move_w(t_game *game)
{
	player_update(XK_w, game);
	if (game->map[game->player_y][game->player_x] == 'E'
			&& game->n_collect == 0)
	{
		mlx_clear_window(game->mlx, game->win);
		game->map[game->player_y + 1][game->player_x] = '0';
		game->moves++;
		game->endgame = 1;
		draw_map(game);
		exit_game(game);
	}
	else if (game->map[game->player_y][game->player_x] == '1'
				|| game->map[game->player_y][game->player_x] == 'E')
		game->player_y += 1;
	else
	{
		mlx_clear_window(game->mlx, game->win);
		if (game->map[game->player_y][game->player_x] == 'C')
				game->n_collect -= 1;
		game->map[game->player_y][game->player_x] = 'P';
		game->map[game->player_y + 1][game->player_x] = '0';
		game->moves++;
		draw_map(game);
	}
}

void	player_move_s(t_game *game)
{
	player_update(XK_s, game);
	if (game->map[game->player_y][game->player_x] == 'E'
			&& game->n_collect == 0)
	{
		mlx_clear_window(game->mlx, game->win);
		game->map[game->player_y - 1][game->player_x] = '0';
		game->moves++;
		game->endgame = 1;
		draw_map(game);
		exit_game(game);
	}
	else if (game->map[game->player_y][game->player_x] == '1'
				|| game->map[game->player_y][game->player_x] == 'E')
		game->player_y -= 1;
	else
	{
		mlx_clear_window(game->mlx, game->win);
		if (game->map[game->player_y][game->player_x] == 'C')
				game->n_collect -= 1;
		game->map[game->player_y][game->player_x] = 'P';
		game->map[game->player_y - 1][game->player_x] = '0';
		game->moves++;
		draw_map(game);
	}
}

void	player_move_a(t_game *game)
{
	player_update('a', game);
	if (game->map[game->player_y][game->player_x] == 'E'
			&& game->n_collect == 0)
	{
		mlx_clear_window(game->mlx, game->win);
		game->map[game->player_y][game->player_x + 1] = '0';
		game->moves++;
		game->endgame = 1;
		draw_map(game);
		exit_game(game);
	}
	else if (game->map[game->player_y][game->player_x] == '1'
				|| game->map[game->player_y][game->player_x] == 'E')
		game->player_x += 1;
	else
	{
		mlx_clear_window(game->mlx, game->win);
		if (game->map[game->player_y][game->player_x] == 'C')
				game->n_collect -= 1;
		game->map[game->player_y][game->player_x] = 'P';
		game->map[game->player_y][game->player_x + 1] = '0';
		game->moves++;
		draw_map(game);
	}
}

void	player_move_d(t_game *game)
{
	player_update('d', game);
	if (game->map[game->player_y][game->player_x] == 'E'
			&& game->n_collect == 0)
	{
		mlx_clear_window(game->mlx, game->win);
		game->map[game->player_y][game->player_x - 1] = '0';
		game->moves++;
		game->endgame = 1;
		draw_map(game);
		exit_game(game);
	}
	else if (game->map[game->player_y][game->player_x] == '1'
				|| game->map[game->player_y][game->player_x] == 'E')
		game->player_x -= 1;
	else
	{
		mlx_clear_window(game->mlx, game->win);
		if (game->map[game->player_y][game->player_x] == 'C')
			game->n_collect -= 1;
		game->map[game->player_y][game->player_x] = 'P';
		game->map[game->player_y][game->player_x - 1] = '0';
		game->moves++;
		draw_map(game);
	}
}
