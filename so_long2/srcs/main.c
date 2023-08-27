/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbordona <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 13:08:51 by lbordona          #+#    #+#             */
/*   Updated: 2023/08/27 13:08:51 by lbordona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static int	map_extension_checker(char *map)
{
	int	i;

	if (!map)
		return (0);
	i = ft_strlen(map) - 1;
	if (map[i] == 'r' && map[i - 1] == 'e'
		&& map[i - 2] == 'b' && map[i - 3] == '.')
		return (1);
	return (0);
}

int	verify(int ac, char **av)
{
	int	fd;

	if (ac != 2)
	{
		ft_printf("\033[0;31mError → Entry should be: ./so_long mapXYZ.ber.\n");
		exit (1);
	}
	fd = open(av[1], O_RDONLY);
	if (map_extension_checker(av[1]))
	{
		ft_printf("\033[0;31mError → Invalid map extension.\n");
		exit (1);
	}
	else if (fd < 0)
	{
		ft_printf("\033[0;31mError → Invalid map file.\n");
		exit (1);
	}
	return (1);
}

void	init_struct(t_game *game)
{
	mlx = 0;
	win = 0;
	img_player_w = 0;
	img_player_a = 0;
	img_player_s = 0;
	img_player_d = 0;
	img_exit = 0;
	img_collect = 0;
	img_wall = 0;
	img_background = 0;
	map = 0;
	temp_map = 0;
	img_width = 32;
	img_height = 32;
	map_rows = 0;
	map_cols = 0;
	player = 0;
	pos_x = 0;
	pos_y = 0;
	exit = 0;
	collect = 0;
	n_collect = 0;
	wall = 0;
	background = 0;
	moves = 0;
}

int	main(int ac, char **av)
{
	t_game	game;

	verify(ac, av);
	init_struct(&game);
	full_map_checker(av[1], &game);
	start_game(&game);
	exit_game(game);
}
