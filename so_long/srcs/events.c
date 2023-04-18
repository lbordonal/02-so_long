/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbordona <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 12:46:54 by lbordona          #+#    #+#             */
/*   Updated: 2023/04/18 18:16:42 by lbordona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	handle_no_event(void *data)
{
	(void)data;
	return (0);
}

int	handle_keypress(int key, t_data *data)
{
	if(key == XK_Escape)
	{
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		data->win_ptr = NULL;
	}
	else if(key == 97)
		render(data);
	return (0);
}

int	render(t_data *data)
{
	render_rectangle(data, (t_rectangle){WIDTH - 100, HEIGHT - 100, 100, 100, GREEN_PIXEL});
	return (0);
}

int	render_rectangle(t_data *data, t_rectangle rectangle)
{
	int	i;
	int	j;

	if(data->win_ptr == NULL)
		return (1);
	i = rectangle.x;
	while (i < rectangle.x + rectangle.width)
	{
		j = rectangle.y;
		while (j < rectangle.y + rectangle.height)
			mlx_pixel_put(data->mlx_ptr, data->win_ptr, j++, i, rectangle.color);
		i++;
	}
	return (0);
}
