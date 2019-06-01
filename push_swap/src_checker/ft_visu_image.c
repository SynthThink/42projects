/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_visu_image.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malluin <malluin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 16:24:17 by malluin           #+#    #+#             */
/*   Updated: 2019/02/22 15:02:35 by malluin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_show_b(t_win *mlx, t_stack *sk, t_node *nd, int nb_size)
{
	int		i;
	int		j;
	int		width;
	int		height;
	int		color;

	height = HEIGHT * 0.02;
	while (nd)
	{
		color = nd->value > 0 ? rgb(1 - nd->value * 255 / sk->max,
			nd->value * 255 / sk->max, 0) : rgb(1 - nd->value * 255 /
			sk->min, 0, nd->value * 255 / sk->min);
		width = nd->value > 0 ? WIDTH / 2 * nd->value /
			sk->max : WIDTH / 2 * nd->value / sk->min;
		i = height;
		while (i < height + nb_size)
		{
			j = WIDTH * 3 / 4 - (width / 2) - 5;
			while (j < WIDTH * 3 / 4 + width / 2)
				place_pixel(mlx, j++, i, color);
			i++;
		}
		height += nb_size;
		nd = nd->next;
	}
}

void	ft_show_a(t_win *mlx, t_stack *sk, t_node *nd, int nb_size)
{
	int		i;
	int		j;
	int		width;
	int		height;
	int		color;

	height = HEIGHT * 0.02;
	while (nd)
	{
		color = nd->value > 0 ? rgb(1 - nd->value * 255 / sk->max,
			nd->value * 255 / sk->max, 0) : rgb(1 - nd->value * 255 /
			sk->min, 0, nd->value * 255 / sk->min);
		width = nd->value > 0 ? WIDTH / 2 * nd->value / sk->max : WIDTH
			/ 2 * nd->value / sk->min;
		i = height;
		while (i < height + nb_size)
		{
			j = WIDTH / 4 - width / 2 + 5;
			while (j < WIDTH / 4 + width / 2)
				place_pixel(mlx, j++, i, color);
			i++;
		}
		height += nb_size;
		nd = nd->next;
	}
}

int		refresh_show(t_win *mlx, t_stack *stack)
{
	static int	nb_size = 0;
	char		*tmp;

	if (nb_size == 0)
		nb_size = ((HEIGHT - 60) / stack->size) > 0 ? ((HEIGHT - 60)
			/ stack->size) : 1;
	stack->max = stack->max == 0 ? -1 : stack->max;
	stack->min = stack->min == 0 ? 1 : stack->min;
	ft_show_a(mlx, stack, stack->stack_a, nb_size);
	ft_show_b(mlx, stack, stack->stack_b, nb_size);
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->image_ptr, 0, 0);
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, WIDTH / 4, HEIGHT - 55,
		0x0000FF00, "Stack A");
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, WIDTH * 3 / 4, HEIGHT - 55,
		0x0000FF00, "Stack B");
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, WIDTH / 2 - 90, HEIGHT - 55,
		0x00FFFFFF, "Instructions:");
	tmp = ft_itoa(stack->op_count);
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, WIDTH / 2 + 60, HEIGHT - 55,
		0x00FFFFFF, tmp);
	ft_memdel((void**)&tmp);
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 300, HEIGHT - 25, 0x00FFFFFF,
		"Commands:     Pause: Return      Forward: Arrows      Finish:  Space");
	return (1);
}
