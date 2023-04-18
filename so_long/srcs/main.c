/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbordona <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 12:20:47 by lbordona          #+#    #+#             */
/*   Updated: 2023/04/18 19:39:16 by lbordona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	main(void)
{
	t_data	data;

	/* setup window: */
	data.mlx_ptr = mlx_init();
	if (data.mlx_ptr == NULL)
		return (MLX_ERROR);
	data.win_ptr = mlx_new_window(data.mlx_ptr, WIDTH, HEIGHT, "so_long");
	if (data.win_ptr == NULL)
	{
		free(data.win_ptr);
		return (MLX_ERROR);
	}

	/* setup hooks: */
	mlx_loop_hook(data.mlx_ptr, &handle_no_event, &data);

	mlx_hook(data.win_ptr, KeyPress, KeyPressMask, &handle_keypress, &data); //key press

	data.img.mlx_img = mlx_new_image(data.mlx_ptr, WIDTH, HEIGHT); //testar!!!!!!!!

	mlx_loop(data.mlx_ptr);

	mlx_destroy_display(data.mlx_ptr);
	free(data.mlx_ptr);
}
