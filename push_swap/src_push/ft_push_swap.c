/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malluin <malluin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 18:51:08 by malluin           #+#    #+#             */
/*   Updated: 2019/02/22 14:35:33 by malluin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_free(t_stack *stack, t_node *node)
{
	t_node	*tmp;

	while (node)
	{
		tmp = node->next;
		free(node);
		node = tmp;
	}
	node = stack->stack_b;
	while (node)
	{
		tmp = node->next;
		free(node);
		node = tmp;
	}
	node = stack->operations;
	while (node)
	{
		tmp = node->next;
		free(node);
		node = tmp;
	}
	free(stack->options);
	free(stack);
}

void	ft_custom_sort_3(t_stack *stack, int size)
{
	if (size == 2)
	{
		if (stack->stack_a->value > stack->stack_a->next->value)
			do_ope(stack, 1);
	}
	else if (size == 3)
	{
		if (stack->stack_a->value > stack->stack_a->next->value &&
			stack->stack_a->value > stack->stack_a->next->next->value &&
			stack->stack_a->next->value < stack->stack_a->next->next->value)
			do_ope(stack, 6);
		if (stack->stack_a->value > stack->stack_a->next->value)
			do_ope(stack, 1);
		if (stack->stack_a->next->next->value < stack->stack_a->value)
			do_ope(stack, 9);
		else if (stack->stack_a->next->next->value <
			stack->stack_a->next->value)
		{
			do_ope(stack, 9);
			do_ope(stack, 1);
		}
	}
}

void	ft_custom_sort_5(t_stack *stack, int size)
{
	long	*maxs;
	int		i;

	i = size - 3;
	maxs = find_n_max(stack->stack_a, size - 3);
	while (i > 0)
	{
		while (is_in_array(maxs, size - 3, stack->stack_a->value) != 1)
			do_ope(stack, 6);
		while (is_in_array(maxs, size - 3, stack->stack_a->value) == 1)
		{
			do_ope(stack, 5);
			i--;
		}
	}
	ft_custom_sort_3(stack, 3);
	if (size == 5)
		if (stack->stack_b->value > stack->stack_b->next->value)
			do_ope(stack, 2);
	while (size-- - 3 > 0)
	{
		do_ope(stack, 4);
		do_ope(stack, 6);
	}
	free(maxs);
}

void	choose_sort(t_stack *stack)
{
	if (stack->size <= 3 && stack->size > 0)
		ft_custom_sort_3(stack, stack->size);
	else if (stack->size <= 5 && stack->size > 0)
		ft_custom_sort_5(stack, stack->size);
	else if (stack->size <= 50)
		ft_selection_sort(stack, stack->size, 1);
	else if (stack->size <= 100)
		ft_selection_sort(stack, stack->size, 4);
	else if (stack->size <= 300)
		ft_selection_sort(stack, stack->size, 6);
	else
		ft_selection_sort(stack, stack->size, stack->size / 40);
	if (is_sort(stack->stack_a) == 0)
		ft_selection_sort(stack, stack->size, 1);
	if (ft_strchr(stack->options, 's') == NULL && stack->operations != NULL)
		ft_print_ope(stack->operations);
}

int		main(int ac, char **av)
{
	t_stack	*stack;

	if (ac == 1)
		return (0);
	stack = initialize_stack();
	ft_parse(stack, av, ac);
	if (stack->stack_a && is_sort(stack->stack_a) == 0 && !stack->stack_b)
		choose_sort(stack);
	ft_free(stack, stack->stack_a);
	return (0);
}
