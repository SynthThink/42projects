/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malluin <malluin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 18:51:08 by malluin           #+#    #+#             */
/*   Updated: 2019/02/05 18:13:02 by malluin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*initialize_stack(void)
{
	t_stack	*stack;

	if (!(stack = (t_stack *)malloc(sizeof(t_stack))))
		exit(-1);
	stack->stack_a = NULL;
	stack->stack_b = NULL;
	stack->operations = NULL;
	stack->options = ft_strdup("");
	stack->count = 0;
	stack->size = 0;
	return (stack);
}

void	ft_free(t_stack *stack)
{
	t_node	*node;
	t_node	*tmp;

	node = stack->stack_a;
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
}

void	ft_print_ope(t_node *operations)
{
	while (operations)
	{
		if (operations->value == 1)
			write(1, "sa\n", 3);
		else if (operations->value == 2)
			write(1, "sb\n", 3);
		else if (operations->value == 3)
			write(1, "ss\n", 3);
		else if (operations->value == 4)
			write(1, "pa\n", 3);
		else if (operations->value == 5)
			write(1, "pb\n", 3);
		else if (operations->value == 6)
			write(1, "ra\n", 3);
		else if (operations->value == 7)
			write(1, "rb\n", 3);
		else if (operations->value == 8)
			write(1, "rr\n", 3);
		else if (operations->value == 9)
			write(1, "rra\n", 4);
		else if (operations->value == 10)
			write(1, "rrb\n", 4);
		else if (operations->value == 11)
			write(1, "rrr\n", 4);
		operations = operations->next;
	}
}

int		main(int ac, char **av)
{
	t_stack	*stack;

	if (ac == 1)
		return (0);
	stack = initialize_stack();
	ft_parse(stack, av, ac);
	if (has_duplicates(stack->stack_a) == 0)
		ft_error();
	ft_quick_sort(stack);
	if (ft_strchr(stack->options, 'd') != NULL)
	{
		print_list(stack->stack_a, "stack a");
		print_list(stack->stack_b, "stack b");
		ft_printf("\n%d instructions\n", stack->count);
	}
	if (ft_strchr(stack->options, 's') == NULL)
		ft_print_ope(stack->operations);
	ft_free(stack);
	free(stack);
	return (0);
}
