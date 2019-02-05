/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap_intra.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malluin <malluin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 15:27:19 by malluin           #+#    #+#             */
/*   Updated: 2019/02/04 15:36:10 by malluin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_to(t_stack *stack, int *i, int *j, t_node *node)
{
	if (*i <= stack->size - *i)
		while (stack->stack_a->value != node->value)
			do_ope(stack, 6 + (*j)-- * 0);
	else
		while (stack->stack_a->value != node->value)
			do_ope(stack, 9 + (*j)++ * 0);
}

void	push_imin(t_node *node_a, t_node *node_b, t_stack *stack, t_tuple cp)
{
	int		c;

	c = 0;
	rotate_to(stack, &(cp.i), &(cp.j), node_a);
	do_ope(stack, 5);
	rotate_to(stack, &(cp.j), &c, node_b);
	do_ope(stack, 5);
	do_ope(stack, 2);
	do_ope(stack, 4);
	while (c < 0)
		do_ope(stack, 9 + c++ * 0);
	while (c-- > 0)
		do_ope(stack, 6);
	do_ope(stack, 4);
	if (cp.i <= stack->size / 2)
		while (cp.i-- > 0)
			do_ope(stack, 9);
	else if (cp.i >= stack->size)
		while (cp.i >= stack->size)
			do_ope(stack, 6 + cp.i-- * 0);
	else
		while (cp.i < stack->size)
			do_ope(stack, 6 + cp.i++ * 0);
}

void	push_to_b(t_node *node_a, t_node *node_b, t_stack *stack, t_tuple cp)
{
	int		c;

	c = 0;
	if (ft_imin(cp.i, stack->size - cp.i) <= ft_imin(cp.j, stack->size - cp.j))
		push_imin(node_a, node_b, stack, cp);
	else
	{
		ft_swap(&cp.i, &cp.j);
		push_imin(node_b, node_a, stack, cp);
	}
	// {
	// 	rotate_to(stack, &(cp.j), &(cp.i), node_b);
	// 	do_ope(stack, 5);
	// 	rotate_to(stack, &(cp.i), &c, node_a);
	// 	do_ope(stack, 5);
	// 	do_ope(stack, 2);
	// 	do_ope(stack, 4);
	// 	while (c < 0)
	// 		do_ope(stack, 9 + c++ * 0);
	// 	while (c-- > 0)
	// 		do_ope(stack, 6);
	// 	do_ope(stack, 4);
	// 	if (cp.j <= stack->size / 2)
	// 		while (cp.j-- > 0)
	// 			do_ope(stack, 9);
	// 	else if (cp.j >= stack->size)
	// 		do_ope(stack, 6 + cp.j-- * 0);
	// 	else
	// 		while (cp.j < stack->size)
	// 			do_ope(stack, 6 + cp.j++ * 0);
	// 	}
}

void	swap_nodes_intra_a(t_node *node_a, t_node *node_b, t_node *stack_top,
			t_stack *stack)
{
	t_tuple	cp;
	int		c;
	t_node	*tmp;

	cp.i = 0;
	cp.j = 0;
	if ((stack_top->value == node_a->value && stack_top->next->value == node_b->value)
		|| (stack_top->value == node_b->value && stack_top->next->value == node_a->value))
		do_ope(stack, 1);
	else if (node_a->value == node_b->value)
		return ;
	else
	{
		tmp = stack_top;
		c = 0;
		while (tmp)
		{
			cp.i = tmp->value == node_a->value ? c : cp.i;
			cp.j = tmp->value == node_b->value ? c : cp.j;
			c++;
			tmp = tmp->next;
		}
		push_to_b(node_a, node_b, stack, cp);
	}
}
