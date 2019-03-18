/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malluin <malluin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 16:24:17 by malluin           #+#    #+#             */
/*   Updated: 2018/12/06 17:50:27 by malluin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		image_init(t_win *mlx)
{
	int bpp;
	int s_l;
	int end;

	if (!(mlx->image_ptr = mlx_new_image(mlx->mlx_ptr, WIDTH, HEIGHT)))
		return (0);
	if (!(mlx->image_str = mlx_get_data_addr(mlx->image_ptr, &bpp, &s_l, &end)))
		return (0);
	return (1);
}

int		refresh_init(t_win *mlx)
{
	if (mlx->mlx_ptr && mlx->image_ptr)
		mlx_destroy_image(mlx->mlx_ptr, mlx->image_ptr);
	if (!(image_init(mlx)))
		return (0);
	return (1);
}

int		refresh_show(t_win *mlx)
{
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->image_ptr, 0, 0);
	return (1);
}

int		refresh_legend(void *param)
{
	t_win *mlx;

	mlx = (t_win *)param;
	legend_text(mlx);
	return (1);
}
