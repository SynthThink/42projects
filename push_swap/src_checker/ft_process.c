/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malluin <malluin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 18:22:49 by malluin           #+#    #+#             */
/*   Updated: 2019/02/01 17:34:30 by malluin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "visu.h"

void	ft_process_inf(t_stack *stack, char val)
{
	if (val == 1)
		swap(&stack->stack_a);
	else if (val == 2)
		swap(&stack->stack_b);
	else if (val == 3)
	{
		swap(&stack->stack_a);
		swap(&stack->stack_b);
	}
	else if (val == 4)
		push_a(&stack->stack_a, &stack->stack_b);
	else if (val == 5)
		push_b(&stack->stack_a, &stack->stack_b);
	else if (val == 6)
		rotate(&stack->stack_a);
}

void	ft_process_sup(t_stack *stack, char val)
{
	if (val == 7)
		rotate(&stack->stack_b);
	else if (val == 8)
	{
		rotate(&stack->stack_a);
		rotate(&stack->stack_b);
	}
	else if (val == 9)
		reverse_rotate(&stack->stack_a);
	else if (val == 10)
		reverse_rotate(&stack->stack_b);
	else if (val == 11)
	{
		reverse_rotate(&stack->stack_a);
		reverse_rotate(&stack->stack_b);
	}
}

int		ft_process_reel(t_win *mlx)
{
	t_node	*operation;
	t_node	*tmp;
	t_stack *stack;

	stack = (t_stack *)mlx->stack;
	if (stack->stop == 1)
		return (1);
	operation = stack->operations;
	if (operation)
	{
		if (operation->value < 7)
			ft_process_inf(stack, operation->value);
		else
			ft_process_sup(stack, operation->value);
		tmp = operation;
		operation = operation->next;
		free(tmp);
		stack->operations = operation;
	}
	if (ft_strchr(stack->options, 'v') != NULL)
		ft_visualize(stack, mlx);
	return (1);
}

void	ft_process(t_stack *stack, t_win *mlx, int mode)
{
	t_node	*operation;
	t_node	*tmp;

	// if (mlx && ft_strchr(stack->options, 'v') != NULL)
	// 	ft_visualize(stack, mlx);
	operation = stack->operations;
	while (operation)
	{
		if (operation->value < 7)
			ft_process_inf(stack, operation->value);
		else
			ft_process_sup(stack, operation->value);
		tmp = operation;
		operation = operation->next;
		free(tmp);
		stack->operations = operation;
		if (mode == 1)
			break;
	}
	if (ft_strchr(stack->options, 'v') != NULL)
		ft_visualize(stack, mlx);
}
