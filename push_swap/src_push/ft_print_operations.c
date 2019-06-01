/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_operations.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malluin <malluin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 17:12:27 by malluin           #+#    #+#             */
/*   Updated: 2019/02/07 17:50:41 by malluin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_debug(t_stack *stack)
{
	print_list(stack->stack_a, "stack a");
	print_list(stack->stack_b, "stack b");
	ft_printf("\n%d instructions\n", stack->count);
}

void	ft_print_sp(int nb)
{
	if (nb == 1)
		write(1, "sa\n", 3);
	else if (nb == 2)
		write(1, "sb\n", 3);
	else if (nb == 3)
		write(1, "ss\n", 3);
	else if (nb == 4)
		write(1, "pa\n", 3);
	else if (nb == 5)
		write(1, "pb\n", 3);
}

t_node	*ft_print_r(t_node *operations)
{
	if (operations->value == 8 || (operations->next
		&& ((operations->value == 6 && operations->next->value == 7)
		|| (operations->value == 7 && operations->next->value == 6))))
	{
		write(1, "rr\n", 3);
		return (operations->next);
	}
	else if (operations->value == 6)
		write(1, "ra\n", 3);
	else if (operations->value == 7)
		write(1, "rb\n", 3);
	return (operations);
}

t_node	*ft_print_rr(t_node *operations)
{
	if (operations->value == 11 || (operations->next
		&& ((operations->value == 9 && operations->next->value == 10)
		|| (operations->value == 10 && operations->next->value == 9))))
	{
		write(1, "rrr\n", 4);
		return (operations->next);
	}
	else if (operations->value == 9)
		write(1, "rra\n", 4);
	else if (operations->value == 10)
		write(1, "rrb\n", 4);
	return (operations);
}

void	ft_print_ope(t_node *operations)
{
	while (operations)
	{
		if (operations->value <= 5)
			ft_print_sp(operations->value);
		else if (operations->value <= 7)
			operations = ft_print_r(operations);
		else if (operations->value <= 11)
			operations = ft_print_rr(operations);
		operations = operations->next;
	}
}
