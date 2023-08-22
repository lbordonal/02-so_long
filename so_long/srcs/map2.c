/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbordona <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 23:37:09 by lbordona          #+#    #+#             */
/*   Updated: 2023/08/22 12:01:35 by lbordona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

//CORRIGIR FUNCAO DO EMPTY LINES
/* int	map_has_empty_lines(t_game *game)
{
	int	i;

	i = 0;
	if (game->map[i][0] == '\n')
	{
		ft_printf("\033[0;31mError → Map has a empty line at the beginning.\n");
		return (1);
	}
	else if(game->map[ft_strlen(game->map[i]) - 1] == '\n')
	{
		ft_printf("\033[0;31mError → Map has a empty line at the end.\n");
		return (1);
	}
	while (game->map[i + 1][0])
	{
		if (game->map[i][0] == '\n' && game->map[i + 1][0] == '\n')
		{
			ft_printf("\033[0;31mError → Map has a empty line at the middle.\n");
			return (1);
		}
		i++;
	}
	return (0);
} */

void	fill_temp_map(t_game *game, char *path)
{
	char	*line;
	int		i;
	int		fd;

	i = 0;
	line = 0;
	game->temp_map = (char **)malloc(sizeof(char *) * (game->map_height + 1));
	fd = open(path, O_RDONLY);
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
		{
			free(line);
			break ;
		}
		game->temp_map[i] = ft_strtrim(line, "\n");
		free(line);
		i++;
	}
	game->temp_map[i] = 0;
	close(fd);
}

void	player_position(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->map_height)
	{
		j = 0;
		while (j < game->map_width)
		{
			if (game->map[i][j] == 'P')
			{
				game->player_x = j;
				game->player_y = i;
				break ;
			}
			j++;
		}
		i++;
	}
}

int		flood_fill(t_game *game, char **map, int x, int y)
{
	static int	collectibles;
	static int	exits;

	if (y < 0 || x < 0 || y > game->map_height || x > game->map_width
		|| map[y][x] == '1' || map[y][x] == 'X')
		return (0);
	if (map[y][x] == 'E')
	{
		exits++;
		map[y][x] = 'X';
		return (0);
	}
	if (map[y][x] == 'C')
		collectibles++;
	map[y][x] = 'X';
	flood_fill(game, map, x + 1, y);
	flood_fill(game, map, x - 1, y);
	flood_fill(game, map, x, y + 1);
	flood_fill(game, map, x, y - 1);
	if (exits == 1 && collectibles == game->n_collect)
		return (1);
	else
		return (0);
}

void	map_has_valid_path(t_game *game, char *path)
{
	fill_temp_map(game, path);
	player_position(game);
	if (flood_fill(game, game->temp_map, game->player_x, game->player_y) == 0)
	{
		ft_printf("\033[0;31mError → Map doesn't have a valid path.\n");
		exit_game(game);
	}
}
