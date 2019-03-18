/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malluin <malluin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 11:21:47 by malluin           #+#    #+#             */
/*   Updated: 2018/12/06 16:58:19 by malluin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_win	*initialize(t_win *mlx, int ac, char **av)
{
	if (!(mlx = (t_win *)malloc(sizeof(t_win))))
		return (0);
	if (!(mlx->mlx_ptr = mlx_init()))
		exit(-1);
	if (!(mlx->win_ptr = mlx_new_window(mlx->mlx_ptr, WIDTH, HEIGHT, "FDF")))
		exit(-1);
	mlx->image_ptr = NULL;
	mlx->image_str = NULL;
	mlx->palette = NULL;
	return (mlx);
}

int	main(int ac, char **av)
{
	t_win	*mlx;

	mlx = initialize();
	if (!(refresh_init(mlx)))
		return (0);
	// if (!(refresh_show(mlx)))
	// 	return (0);
	mlx_key_hook(mlx->win_ptr, deal_key, (void *)mlx);
	mlx_mouse_hook(mlx->win_ptr, mouse_line, (void *)(mlx));
	//mlx_expose_hook(mlx->win_ptr, refresh_legend, (void *)(mlx));
	mlx_loop(mlx->mlx_ptr);
	return (0);
}
