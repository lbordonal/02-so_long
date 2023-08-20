/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbordona <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 23:37:09 by lbordona          #+#    #+#             */
/*   Updated: 2023/08/20 23:37:09 by lbordona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	map_has_empty_lines(char **map)
{
	int	i;

	i = 0;
	if (map[i] == '\n')
	{
		ft_printf("\033[0;31mError → Map has a empty line at the beginning.\n");
		return (1);
	}
	else if(map[ft_strlen(map) - 1] == '\n')
	{
		ft_printf("\033[0;31mError → Map has a empty line at the end.\n");
		return (1);
	}
	while (map[i + 1])
	{
		if (map[i] == '\n' && map[i + 1] == '\n')
		{
			ft_printf("\033[0;31mError → Map has a empty line at the middle.\n");
			return (1);
		}
		i++;
	}
	return (0);
}
