/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_selection_sort.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malluin <malluin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/31 17:03:30 by malluin           #+#    #+#             */
/*   Updated: 2019/02/07 17:10:15 by malluin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	do_ope_increment(t_stack *stack, int ope, int *posmax, int *posmin)
{
	int		signe;

	signe = ope > 0 ? 1 : -1;
	ope = ft_iabs(ope);
	do_ope(stack, ope);
	if (posmin != NULL)
		*posmin += signe;
	if (posmax != NULL)
		*posmax += signe;
}

void	ft_selection_sort_from_b(t_stack *stack, int size)
{
	int		posmax;
	int		max;

	max = find_max(stack->stack_b, &posmax);
	while (stack->stack_b)
	{
		if (stack->stack_b && stack->stack_b->value == max)
		{
			do_ope(stack, 4);
			size--;
			max = find_max(stack->stack_b, &posmax);
		}
		while (stack->stack_b && stack->stack_b->value != max)
		{
			if (posmax <= size / 2)
				do_ope_increment(stack, -7, &posmax, NULL);
			else
				do_ope_increment(stack, 10, &posmax, NULL);
		}
	}
}

void	push_if_array(t_stack *stack, t_min *t_m, int *c, int *size)
{
	if (stack->stack_a && is_in_array(t_m->mins,
		t_m->minmax, stack->stack_a->value))
	{
		do_ope_increment(stack, -5, size, &t_m->pmax);
		free(t_m->mins);
		t_m->mins = find_n_min(stack->stack_a, t_m->minmax);
		find_min(stack->stack_a, &t_m->pmin);
	}
	if (stack->stack_a && is_in_array(t_m->maxs, t_m->minmax,
		stack->stack_a->value))
	{
		do_ope(stack, 5);
		do_ope_increment(stack, -7, size, &t_m->pmin);
		(*c)++;
		free(t_m->maxs);
		t_m->maxs = find_n_max(stack->stack_a, t_m->minmax);
		find_max(stack->stack_a, &t_m->pmax);
	}
}

void	rotate_to_target(t_stack *stack, t_min *t_m, int s)
{
	if (ft_imin(t_m->pmin, s - t_m->pmin) <= ft_imin(t_m->pmax, s - t_m->pmax))
	{
		while (stack->stack_a && is_in_array(t_m->mins, t_m->minmax,
				stack->stack_a->value) != 1 && is_in_array(t_m->maxs,
				t_m->minmax, stack->stack_a->value) != 1)
			if (t_m->pmin <= s / 2)
				do_ope_increment(stack, -6, &t_m->pmax, &t_m->pmin);
			else
				do_ope_increment(stack, 9, &t_m->pmax, &t_m->pmin);
	}
	else
	{
		while (stack->stack_a && is_in_array(t_m->maxs, t_m->minmax,
				stack->stack_a->value) != 1 && is_in_array(t_m->mins,
				t_m->minmax, stack->stack_a->value) != 1 && s != 1)
			if (t_m->pmax <= s / 2)
				do_ope_increment(stack, -6, &t_m->pmax, &t_m->pmin);
			else
				do_ope_increment(stack, 9, &t_m->pmax, &t_m->pmin);
	}
}

void	ft_selection_sort(t_stack *stack, int size, char minmax)
{
	t_min	t_m;
	int		c;

	c = 0;
	t_m.minmax = minmax;
	t_m.mins = find_n_min(stack->stack_a, minmax);
	t_m.maxs = find_n_max(stack->stack_a, minmax);
	find_min(stack->stack_a, &t_m.pmin);
	find_max(stack->stack_a, &t_m.pmax);
	while (stack->stack_a)
	{
		push_if_array(stack, &t_m, &c, &size);
		rotate_to_target(stack, &t_m, size);
	}
	while (c-- > 0)
		do_ope(stack, 10);
	ft_selection_sort_from_b(stack, stack->size);
	free(t_m.mins);
	free(t_m.maxs);
}
