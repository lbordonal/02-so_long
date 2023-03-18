/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_and_images.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbordona <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 23:15:38 by lbordona          #+#    #+#             */
/*   Updated: 2023/03/17 23:39:53 by lbordona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	put_pixel_img(t_img *img, int x, int y, int color)
{
	char	*dest;

	dest = img->addr + (y * img->line_len + x * (img->bpp / 8));
	*(unsigned int *) dest = color;
}

t_img	*new_image(t_window *win, int height, int width)
{
	t_img	*img;

	img = (t_img *)malloc(sizeof(t_img));
	if (!img)
		return (NULL);
	img->win = win;
	img->w = width;
	img->h = height;
	img->img_ptr = mlx_new_image (win->mlx_ptr, width, height);
	img->addr = mlx_get_data_addr(img->img_ptr, &(img->bpp),
			&(img->line_len), &(img->endian));
	return (img);
}

t_window	*new_window(int height, int width, char *str)
{
	t_window	*win;
	void		*mlx_ptr;
	void		*win_ptr;

	mlx_ptr = mlx_init();
	if (!mlx_ptr)
		return (NULL);
	win_ptr = mlx_new_window (mlx_ptr, width, height, str);
	if (!win_ptr)
		return (NULL);
	win = (t_window *)malloc(sizeof(t_window));
	win->mlx_ptr = mlx_ptr;
	win->win_ptr = win_ptr;
	win->height = height;
	win->width = width;
	return (win);
}
