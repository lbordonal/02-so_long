/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbordona <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 18:47:54 by lbordona          #+#    #+#             */
/*   Updated: 2023/08/27 18:47:54 by lbordona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	init_map(char *av, t_game *game)
{
	char	*line;
	int		i;
	int		fd;

	i = 0;
	line = 0;
	game->map = (char **)malloc(sizeof(char *) * (game->map_rows + 1));
	fd = open(av, O_RDONLY);
	if (fd == -1)
		return (NULL);
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
		{
			free(line);
			break ;
		}
		game->map[i] = ft_strtrim(line, "\n");
		free(line);
		i++;
	}
	game->map[i] = 0;
	close(fd);
}

void	init_temp_map(char *av, t_game *game)
{
	char	*line;
	int		i;
	int		fd;

	i = 0;
	line = 0;
	game->temp_map = (char **)malloc(sizeof(char *) * (game->map_rows + 1));
	fd = open(av, O_RDONLY);
	if (fd == -1)
		return (NULL);
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

void	init_imgs(t_game *game)
{
	game->img_player_w = mlx_xpm_file_to_image
		(game->mlx, PLAYER_W, WIDTH, HEIGHT);
	game->img_player_a = mlx_xpm_file_to_image
		(game->mlx, PLAYER_A, WIDTH, HEIGHT);
	game->img_player_s = mlx_xpm_file_to_image
		(game->mlx, PLAYER_S, WIDTH, HEIGHT);
	game->img_player_d = mlx_xpm_file_to_image
		(game->mlx, PLAYER_D, WIDTH, HEIGHT);
	game->img_exit = mlx_xpm_file_to_image
		(game->mlx, EXIT_IMG, WIDTH, HEIGHT);
	game->img_collect = mlx_xpm_file_to_image
		(game->mlx, COLLECT_IMG, WIDTH, HEIGHT);
	game->img_wall = mlx_xpm_file_to_image
		(game->mlx, WALL_IMG, WIDTH, HEIGHT);
	game->img_background = mlx_xpm_file_to_image
		(game->mlx, BACKGROUND_IMG, WIDTH, HEIGHT);
}

