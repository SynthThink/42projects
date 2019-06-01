/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_visu_events.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malluin <malluin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/01 13:44:18 by malluin           #+#    #+#             */
/*   Updated: 2019/02/08 13:43:56 by malluin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		deal_key(int key, void *param)
{
	t_stack			*stack;
	t_win			*mlx;
	static	int		start = 0;

	mlx = (t_win *)param;
	stack = (t_stack *)mlx->stack;
	if (key >= 123 && key <= 126)
		ft_process(stack, mlx, 1);
	else if (key == 36)
		stack->stop = stack->stop == 1 ? 0 : 1;
	else if (key == 49 && start == 0)
	{
		ft_process(stack, mlx, 0);
		ft_check(stack);
		start = 1;
	}
	else if (key == 53)
		exit(1);
	return (1);
}
