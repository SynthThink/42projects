/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_visu.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malluin <malluin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 11:21:47 by malluin           #+#    #+#             */
/*   Updated: 2019/02/01 15:18:15 by malluin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_win	*mlx_initialize(void)
{
	t_win *mlx;

	if (!(mlx = (t_win *)malloc(sizeof(t_win))))
		return (0);
	if (!(mlx->mlx_ptr = mlx_init()))
		return (0);
	if (!(mlx->win_ptr = mlx_new_window(mlx->mlx_ptr, WIDTH, HEIGHT,
			"Checker")))
		return (0);
	mlx->image_ptr = NULL;
	return (mlx);
}

int		ft_visualize(t_stack *stack, t_win *mlx)
{
	if (!(refresh_init(mlx)))
		return (0);
	if (!(refresh_show(mlx, stack)))
		return (0);
	// mlx_key_hook(mlx->win_ptr, deal_key, (void *)mlx);
	// mlx_mouse_hook(mlx->win_ptr, mouse_line, (void *)(mlx));
	// mlx_expose_hook(mlx->win_ptr, refresh_legend, (void *)(mlx));
	return (1);
}
