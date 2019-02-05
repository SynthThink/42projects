/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_visu_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malluin <malluin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/01 13:41:28 by malluin           #+#    #+#             */
/*   Updated: 2019/02/01 16:11:37 by malluin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		rgb(unsigned char red, unsigned char green, unsigned char blue)
{
	int	r;
	int	g;
	int	b;

	r = (red << 16) & 0xFF0000;
	g = (green << 8) & 0x00FF00;
	b = blue & 0x000FF;
	return (0x000000 | r | g | b);
}

void	place_pixel(t_win *mlx, int u, int v, int color)
{
	int	coord;
	int	red;
	int	blue;
	int	green;

	if (color == 0)
		color = rgb(255, 255, 255);
	red = (color >> 16) & 0xFF;
	green = (color >> 8) & 0xFF;
	blue = (color) & 0xFF;
	u = ft_imax(u, 0);
	coord = u * 4 + v * WIDTH * 4;
	if (coord < WIDTH * 4 * HEIGHT && coord >= 0 && u < WIDTH)
	{
		(mlx->image_str)[coord] = blue;
		(mlx->image_str)[coord + 1] = green;
		(mlx->image_str)[coord + 2] = red;
	}
}

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
