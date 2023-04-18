/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbordona <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 12:31:17 by lbordona          #+#    #+#             */
/*   Updated: 2023/04/18 10:10:08 by lbordona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include <stdio.h>

int	main(void)
{
	t_window	*win;
	t_img		*img;
	t_square	square;

	/* criar janela: */
	win = new_window(400, 400, "Teste");
	if (!win)
		return (-1);

	/* criar imagem: */
	img = new_image(win, 400, 400);
	if (!img)
		return (-1);
	printf("Created an image with [%d x %d]\n", img->w, img->h);


	/* criar quadrado: */
	square = (t_square){0, 0, 200, create_trgb(0, 153, 51, 255)};
	draw_square(square, img);

	/* colocar quadrado dentro da imagem: */
	mlx_put_image_to_window(win->mlx_ptr, win->win_ptr, img->img_ptr, 100, 100);
	printf("Created an square inside the image with [%d x %d]\n", square.size, square.size);

	/* loop para não fechar a janela--: */
	mlx_loop(win->mlx_ptr);

	/* free: */
	free(win);
	free(img);
	return (0);
}
