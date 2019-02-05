/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bubble_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malluin <malluin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 19:59:44 by malluin           #+#    #+#             */
/*   Updated: 2019/01/31 16:58:27 by malluin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_stacks(t_stack *stack)
{
	do_ope(stack, 5);
	do_ope(stack, 2);
	do_ope(stack, 4);
}

int		do_swaps(t_stack *stack)
{
	t_node	*stack_a;

	stack_a = stack->stack_a;
	if (stack_a && stack_a->next && stack_a->value > stack_a->next->value)
	{
		swap(&stack->stack_a);
		lst_new_back(1, &stack->operations);
		stack->count++;
		return (1);
	}
	return (0);
}

void	do_rotate(t_stack *stack)
{
	t_node	*end;
	short	opt;

	opt = 1;
	while (opt == 1)
	{
		end = get_end(stack->stack_a);
		if (end && end->value < stack->stack_a->value)
		{
			rotate(&stack->stack_a);
			if (ft_strchr(stack->options, 'd') != NULL)
				print_list(stack->stack_a, "rotate a|");
			lst_new_back(6, &stack->operations);
			stack->count++;
		}
		else if (do_swaps(stack))
			;
		else
			break ;
	}
}

void	ft_bubble_sort(t_stack *stack)
{
	int		i;

	i = 0;
	while (i < stack->size)
	{
		// if (ft_strchr(stack->options, 'd') != NULL)
		// 	print_list(stack->stack_a, "debut stack a|");
		do_swaps(stack);
		do_rotate(stack);
		// if (ft_strchr(stack->options, 'd') != NULL)
		// {
		// 	print_list(stack->stack_a, "debut stack a|");
		// 	print_list(stack->stack_b, "debut stack b|");
		// }
		if (is_sort(stack->stack_a) == 1 && stack->stack_b == NULL)
			break ;
		else
			i = 0;
		while (stack->stack_b == NULL || (stack->stack_a &&
			stack->stack_a->value > stack->stack_b->value))
			do_ope(stack, 5);
		if (stack->stack_a && stack->stack_a->value < stack->stack_b->value)
			swap_stacks(stack);
		if (stack->stack_a == NULL)
		{
			while (stack->stack_b)
			{
				do_ope(stack, 4);
				do_rotate(stack);
			}
		}
		i++;
	}
}
