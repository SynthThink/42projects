/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_visu_image.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malluin <malluin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 16:24:17 by malluin           #+#    #+#             */
/*   Updated: 2019/02/01 16:20:41 by malluin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_show_b(t_win *mlx, t_stack *stack, t_node *node, int nb_size)
{
	int		i;
	int		j;
	int		width;
	int		height;
	int		color;

	height = 0;
	while (node)
	{
		color = node->value > 0 ? rgb(0, 255, 0) : rgb(255, 0, 0);
		width = node->value > 0 ? WIDTH / 2 * node->value / stack->max : WIDTH / 2
			* node->value / stack->min;
		width += WIDTH / 2;
		i = height;
		while (i < height + nb_size)
		{
			j = WIDTH / 2;
			while (j < width)
				place_pixel(mlx, j++, i, color);
			i++;
		}
		height += nb_size;
		node = node->next;
	}
}

void	ft_show_a(t_win *mlx, t_stack *stack, t_node *node, int nb_size)
{
	int		i;
	int		j;
	int		width;
	int		height;
	int		color;

	height = 0;
	while (node)
	{
		color = node->value > 0 ? rgb(0, 255, 0) : rgb(255, 0, 0);
		width = node->value > 0 ? WIDTH / 2 * node->value / stack->max : WIDTH
			/ 2 * node->value / stack->min;
		i = height;
		while (i < height + nb_size)
		{
			j = 0;
			while (j < width)
				place_pixel(mlx, j++, i, color);
			j = 0;
			i++;
		}
		height += nb_size;
		node = node->next;
	}
}

int		refresh_show(t_win *mlx, t_stack *stack)
{
	static int		nb_size = 0;

	if (nb_size == 0)
		nb_size = ((HEIGHT - 60) / stack->size) > 0 ? ((HEIGHT - 60) / stack->size) : 1;
	ft_show_a(mlx, stack, stack->stack_a, nb_size);
	ft_show_b(mlx, stack, stack->stack_b, nb_size);
	// legend_box(mlx);

	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->image_ptr, 0, 0);
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 250, HEIGHT - 50,
		0x0000FF00, "Stack A");
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 700, HEIGHT - 50,
		0x0000FF00, "Stack B");
	// legend_text(mlx);
	return (1);
}

//
// int		refresh_legend(void *param)
// {
// 	t_win *mlx;
//
// 	mlx = (t_win *)param;
// 	legend_text(mlx);
// 	return (1);
// }
