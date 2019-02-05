/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_quick_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malluin <malluin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/31 17:03:30 by malluin           #+#    #+#             */
/*   Updated: 2019/02/05 18:15:41 by malluin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_sort_pivot_a(t_stack *stack, char nb)
{
	int				c;
	int				pvalue;
	static int		start = 0;

	c = 0;
	if (start == 0)
	{
		pvalue = find_median(stack->stack_a, stack->size);
		while (stack->stack_a && stack->stack_a->value != pvalue)
		{
			if (stack->stack_a && stack->stack_a->value < pvalue)
				do_ope(stack, 5);
			do_ope(stack, 6);
		}
		do_ope(stack, 5);
		do_ope(stack, 7);
		start = 1;
	}
	else
	{
		if (stack->stack_a)
			do_ope(stack, 5);
		pvalue = stack->stack_b != 0 ? stack->stack_b->value : -2147483648;
	}
	// print_list(stack->stack_a, "stack a debut");
	// print_list(stack->stack_b, "stack b debut");
	// ft_printf("|PIVOT IS %d|\n", pvalue);
	c = get_lst_len(stack->stack_a);
	while (c > 0)
	{
		if (stack->stack_a && stack->stack_a->value < pvalue)
			do_ope(stack, 5);
		else
			do_ope(stack, 6);
		c--;
		// optimiser en cherchant a lavance ceux inferieur et en fesant le moins de mvt necessaire
	}
	set_pivot_sorted(stack->stack_b, pvalue);
	// print_list(stack->stack_a, "stack a end");
	// print_list(stack->stack_b, "stack b end");

	return (stack->stack_a == NULL);
}

int		has_non_sorted(t_node *node)
{
	while (node)
	{
		if (node->sorted == 0)
			return (1);
		node = node->next;
	}
	return (0);
}

int		ft_sort_pivot_b(t_stack *stack, char nb)
{
	int c;
	int d;
	int		pvalue;

	// print_list(stack->stack_a, "stack a debut");
	// print_list(stack->stack_b, "stack b debut");
	c = 0;
	while (stack->stack_b && stack->stack_b->sorted == 1)
		do_ope(stack, 4);
	if (has_non_sorted(stack->stack_b))
		while (stack->stack_b && stack->stack_b->sorted != 1)
		{
			do_ope(stack, 7);
			c++;
		}
	if (stack->stack_b)
		do_ope(stack, 4);
	d = c - 1;
	// ft_printf("|D IS %d|\n", d);
	if (stack->stack_b)
		do_ope(stack, 10);
	pvalue = stack->stack_b != 0 ? stack->stack_b->value : -2147483648;
	// print_list(stack->stack_a, "stack a plus grand pivot");
	// print_list(stack->stack_b, "stack b plus grand pivot");
	while (d-- > 0)
	{
		if (stack->stack_b && stack->stack_b->value > pvalue)
			do_ope(stack, 4);
		else
		{
			do_ope(stack, 10);
			if (stack->stack_b && stack->stack_b->value > pvalue)
				do_ope(stack, 4);
		}

		// print_list(stack->stack_b, "stack b boucle");
	}
	// if (stack->stack_b)
	// 	do_ope(stack, 4);
	// ft_printf("|PIVOT IS %d C IS %d|\n", pvalue, c);
	// print_list(stack->stack_a, "stack a selec pivot");
	// print_list(stack->stack_b, "stack b selec pivot");
	while (stack->stack_b->value != pvalue)
	{
		if (stack->stack_b && stack->stack_b->value < pvalue)
			do_ope(stack, 4);
		else
			do_ope(stack, 7);
		// optimiser en cherchant a lavance ceux inferieur et en fesant le moins de mvt necessaire
	}
	do_ope(stack, 4);
	set_pivot_sorted(stack->stack_a, pvalue);
	// print_list(stack->stack_a, "stack a end");
	// print_list(stack->stack_b, "stack b end");

	return (stack->stack_b == NULL);
}

void	ft_quick_sort(t_stack *stack)
{
	if (!stack->stack_a)
		return ;
	while (!(is_sort(stack->stack_a) && stack->stack_b == 0))
	{
		while(ft_sort_pivot_a(stack, 0) == 0)
			;
		while (stack->stack_a)
			do_ope(stack, 5);
		while(ft_sort_pivot_b(stack, 0) == 0)
			;
		ft_selection_sort(stack, stack->size);
		break;
	}
}
