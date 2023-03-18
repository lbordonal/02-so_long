/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forms.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbordona <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 23:37:26 by lbordona          #+#    #+#             */
/*   Updated: 2023/03/17 23:40:00 by lbordona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	draw_square(t_square square, t_img *img)
{
	unsigned short int	i;
	unsigned short int	j;

	i = 0;
	while (i < square.size && i < img->h)
	{
		j = 0;
		while (j < square.size && j < img->w)
		{
			put_pixel_img(img, j + square.x, i + square.y, square.color);
			j++;
		}
		i++;
	}
}
