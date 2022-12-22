/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbordona <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 12:31:17 by lbordona          #+#    #+#             */
/*   Updated: 2022/12/22 12:40:40 by lbordona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	void	*img;

	mlx = mlx_init(); //iniciar mlx
	mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!"); //criar janela 1920x1080
	mlx_loop(mlx); //iniciar rendering da janela
	img = mlx_new_image(mlx, 1920, 1080); //inicializar imagem 1920x1080
}
