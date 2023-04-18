/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbordona <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 12:46:54 by lbordona          #+#    #+#             */
/*   Updated: 2023/04/18 12:57:54 by lbordona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	handle_no_event(void *data)
{
	(void)data;
	return (0);
}

int	handle_input(int key, t_data *data)
{
	if(key == XK_Escape)
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	return (0);
}
