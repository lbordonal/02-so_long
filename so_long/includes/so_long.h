/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbordona <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 12:31:51 by lbordona          #+#    #+#             */
/*   Updated: 2023/04/19 18:19:07 by lbordona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/libft.h"
# include "../minilibx-linux/mlx.h"
# include <X11/X.h>
# include <X11/keysym.h>

# ifndef RED_PIXEL
#  define RED_PIXEL 0xFF0000
# endif

# ifndef GREEN_PIXEL
#  define GREEN_PIXEL 0x00FF00
# endif

# ifndef BLUE_PIXEL
#  define BLUE_PIXEL 0x0000FF
# endif

# ifndef MLX_ERROR
#  define MLX_ERROR 1
# endif

# ifndef WIDTH
#  define WIDTH 600
# endif

# ifndef HEIGHT
#  define HEIGHT 300
# endif

typedef struct s_img
{
	void	*mlx_img;
	char	*addr;
	int		bpp;/* bits per pixel */
	int		line_len;
	int		endian;
}	t_img;

typedef struct s_data
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_img	img;
}	t_data;

typedef struct s_rectangle
{
	int		x;
	int		y;
	int		width;
	int		height;
	int		color;
}	t_rectangle;

/* main.c: */

/* events.c: */
int		handle_no_event(void *data);
int		handle_keypress(int key, t_data *data); //what is done when I press a key
int		render(t_data *data); //draw a pixel
int		render_rectangle(t_img *img, t_rectangle rectangle); //draw a rectangle
void	render_background(t_img *img, int color); //coloring background
void	img_pix_put(t_img *img, int x, int y, int color); //img pix put

#endif
