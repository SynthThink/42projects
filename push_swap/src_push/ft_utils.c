/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malluin <malluin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/31 15:14:58 by malluin           #+#    #+#             */
/*   Updated: 2019/02/04 19:04:48 by malluin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	do_ope(t_stack *stack, int nb)
{
	lst_new_back(nb, &stack->operations);
	if (nb == 4)
		push_a(&stack->stack_a, &stack->stack_b);
	else if (nb == 5)
		push_b(&stack->stack_a, &stack->stack_b);
	else if (nb == 2)
		swap(&stack->stack_b);
	else if (nb == 1)
		swap(&stack->stack_a);
	else if (nb == 6)
		rotate(&stack->stack_a);
	else if (nb == 7)
		rotate(&stack->stack_b);
	else if (nb == 9)
		reverse_rotate(&stack->stack_a);
	else if (nb == 10)
		reverse_rotate(&stack->stack_b);
	stack->count++;
}

t_node	*get_end(t_node *stack)
{
	if (!stack)
		return (0);
	while (stack->next)
		stack = stack->next;
	return (stack);
}

int		is_sort(t_node *stack)
{
	t_node	*node;
	int		i;

	node = stack;
	if (node)
	{
		i = node->value;
		node = node->next;
	}
	else
		return (-1);
	while (node)
	{
		if (i > node->value)
			return (0);
		i = node->value;
		node = node->next;
	}
	return (1);
}

int		has_duplicates(t_node *stack)
{
	t_node	*node;
	t_node	*cmp;
	int		i;

	node = stack;
	if (node)
		i = node->value;
	node = node->next;
	while (node)
	{
		cmp = node;
		while (cmp)
		{
			if (i == cmp->value)
				return (0);
			cmp = cmp->next;
		}
		i = node->value;
		node = node->next;
	}
	return (1);
}
