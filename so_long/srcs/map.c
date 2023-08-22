/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbordona <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 13:23:57 by lbordona          #+#    #+#             */
/*   Updated: 2023/08/22 12:21:06 by lbordona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static int	map_is_rectangular(char **map)
{
	int	i;

	i = 1;
	if (!map)
		return (0);
	while (map[i])
	{
		if (ft_strlen(map[i]) != ft_strlen(map[0]))
		{
			ft_printf("\033[0;31mError → Map isn't rectangular.\n");
			return (0);
		}
		i++;
	}
	return (1);
}

static int	map_wall_is_valid(char **map)
{
	int	i;
	int	j;
	int	len;

	i = 0;
	j = 0;
	while (map[i])
		i++;
	while (map[0][j] != '\0' && map[i -1][j] != '\0')
	{
		if (map[0][j] != '1' || map[i - 1][j] != '1')
		{
			ft_printf("\033[0;31mError → Map isn't surrounded by walls.\n");
			return (0);
		}
		j++;
	}
	i = 1;
	len = ft_strlen(map[i]);
	while (map[i])
	{
		if (map[i][0] != '1' || map[i][len - 1] != '1')
		{
			ft_printf("\033[0;31mError → Map isn't surrounded by walls.\n");
			return (0);
		}
		i++;
	}
	return (1);
}

static int	map_is_correct(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j] != '\0')
		{
			if (map[i][j] != 'P' && map[i][j] != 'E' && map[i][j] != 'C'
					&& map[i][j] != '0' && map[i][j] != '1')
			{
				ft_printf("\033[0;31mError → Map has invalid char.\n");
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

static int	map_is_functional(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	game->n_collect = 0;
	game->n_player = 0;
	game->n_exit = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j] != '\0')
		{
			if (game->map[i][j] == 'C')
				game->n_collect++;
			else if (game->map[i][j] == 'P')
				game->n_player++;
			else if (game->map[i][j] == 'E')
				game->n_exit++;
			j++;
		}
		i++;
	}
	if (game->n_collect == 0 || game->n_player != 1 || game->n_exit != 1)
	{
		ft_printf("\033[0;31mError → Map has invalid number of Collectible, Exit or Player.\n");
		return (0);
	}
	return (1);
}

int	map_checker(t_game *game)
{
	if (map_is_rectangular(game->map) && map_wall_is_valid(game->map)
		&& map_is_correct(game->map) && map_is_functional(game))
		/* && map_has_empty_lines (game))*/
		return (1);
	return (0);
}
