/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbordona <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 21:40:13 by lbordona          #+#    #+#             */
/*   Updated: 2023/08/20 21:40:13 by lbordona         ###   ########.fr       */
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
	{
		ft_printf("\033[0;31mError → Invalid map extension!\n");
		return (1);
	}
	return (0);
}

char	**read_map(char *path)
{
	int		fd;
	char	*line;
	char	*holder_map;
	char	*holder;
	char	**map;

	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (NULL);
	holder_map = ft_strdup("");
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		holder = holder_map;
		holder_map = ft_strjoin(holder, line);
		free(line);
		free(holder);
	}
	map = ft_split(holder_map, '\n');
	free(holder_map);
	close(fd);
	return (map);
}

int	main(int ac, char **av)
{
	t_game	game;

	if (ac == 2)
	{
		initialize_tgame(&game);
		game.map = read_map(av[1]);
		if (map_extension_checker(av[1]) && map_checker(&game))
		{
			game_init(&game);
			game_play(&game);
			mlx_loop(game.mlx);
		}
		else
		{
			if (game.map)
				free_map(game.map);
			ft_printf("%s\n", "Error → Invalid map!");
			exit(1);
		}
	}
	else
	{
		ft_printf("%s\n", "Error!");
		exit(1);
	}
	return (0);
}
