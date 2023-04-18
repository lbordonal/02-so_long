/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbordona <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 12:31:51 by lbordona          #+#    #+#             */
/*   Updated: 2023/04/18 12:56:13 by lbordona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/libft.h"
# include "../minilibx-linux/mlx.h"
# include <X11/X.h>
# include <X11/keysym.h>

# ifndef MLX_ERROR
#  define MLX_ERROR 1
# endif

# ifndef WIDTH
#  define WIDTH 600
# endif

# ifndef HEIGHT
#  define HEIGHT 600
# endif

typedef struct s_data
{
	void	*mlx_ptr;
	void	*win_ptr;
}	t_data;

/* main.c: */

/* events.c: */
int		handle_no_event(void *data);
int		handle_input(int key, t_data *data);

#endif
