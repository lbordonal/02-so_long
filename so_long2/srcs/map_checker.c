/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbordona <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 16:28:05 by lbordona          #+#    #+#             */
/*   Updated: 2023/08/27 21:29:30 by lbordona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	check_map_struct(t_game *game)
{
	if (map_is_rectangular(game->map) == 0)
	{
		free_map(game->map, game);
		exit(1);
	}
	if (map_wall_is_valid(game->map) == 0)
	{
		ft_printf("\033[0;31mError → Map isn't surrounded by walls.\n");
		free_map(game->map, game);
		exit(1);
	}
	if (map_is_correct(game->map) == 0)
	{
		free_map(game->map, game);
		exit(1);
	}
	if (map_is_functional(game) == 0)
	{
		ft_printf("\033[0;31mError → Map has invalid number of Collectible, Exit or Player.\n");
		free_map(game->map, game);
		exit(1);
	}
}

/* void	check_map_empty_lines(t_game *game)
{
	int	i;

	i = 0;
	if (game->map[0] == '\n')
	{
		ft_printf("\033[0;31mError → Map has a empty line at the beginning.\n");
		free_map(game->map, game);
		exit (1);
	}
	else if(game->map_cols - 1 == '\n')
	{
		ft_printf("\033[0;31mError → Map has a empty line at the end.\n");
		free_map(game->map, game);
		exit (1);
	}
	while (game->map[i + 1])
	{
		if (game->map[i] == '\n' && game->map[i + 1] == '\n')
		{
			ft_printf("\033[0;31mError → Map has a empty line at the middle.\n");
			free_map(game->map, game);
			exit (1);
		}
		i++;
	}
} */

void	check_map_path(char *av, t_game *game)
{
	init_temp_map(av, game);
	player_position(game);
	if (flood_fill(game, game->temp_map, game->pos_x, game->pos_y) == 0)
	{
		ft_printf("\033[0;31mError → Map doesn't have any valid path.\n");
		free_map(game->temp_map, game);
		free_map(game->map, game);
		exit (1);
	}
}

/*--------------------------------------------------------------------------------------------------*/
void	full_map_checker(char *av, t_game *game)
{
	game->map_rows = count_lines(av);
	init_map(av, game);
	game->map_cols = count_cols(game->map[0]);
	check_map_struct(game);
	//check_map_empty_lines(game);
	check_map_path(av, game);
}
