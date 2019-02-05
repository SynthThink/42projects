/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_selection_sort.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malluin <malluin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/31 17:03:30 by malluin           #+#    #+#             */
/*   Updated: 2019/02/05 18:34:34 by malluin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*find_min(t_node *stack_a, int *index)
{
	int		i;
	int		j;
	t_node	*min;

	if (!stack_a)
		return (0);
	i = stack_a->value;
	j = 0;
	*index = 0;
	min = stack_a;
	stack_a = stack_a->next;
	while (stack_a)
	{
		j++;
		if (i > stack_a->value)
		{
			i = stack_a->value;
			*index = j;
			min = stack_a;
		}
		stack_a = stack_a->next;
	}
	return (min);
}

t_node	*find_max(t_node *stack_a, int *index)
{
	int		i;
	int		j;
	t_node	*max;

	if (!stack_a)
		return (0);
	i = stack_a->value;
	j = 0;
	*index = 0;
	max = stack_a;
	stack_a = stack_a->next;
	while (stack_a)
	{
		j++;
		if (i < stack_a->value)
		{
			i = stack_a->value;
			*index = j;
			max = stack_a;
		}
		stack_a = stack_a->next;
	}
	return (max);
}

long	*find_three_min(t_node *stack_a)
{
	int		i;
	long	*nb;

	if (!stack_a)
		return (0);
	if (!(nb = (long *)malloc(sizeof(long) * (3))))
		exit (-1);
	nb[0] = 2147483648;
	nb[1] = 2147483648;
	nb[2] = 2147483648;
	i = 0;
	while (stack_a)
	{
		if (nb[0] > stack_a->value)
		{
			if (nb[1] > nb[0])
				nb[1] = nb[0];
			nb[0] = stack_a->value;
		}
		else if (nb[1] > stack_a->value)
		{
			if (nb[2] > nb[1])
				nb[2] = nb[1];
			nb[1] = stack_a->value;
		}
		else if (nb[2] > stack_a->value)
		{
			if (nb[0] > nb[2])
				nb[0] = nb[2];
			nb[2] = stack_a->value;
		}
		stack_a = stack_a->next;

	}
	return (nb);
}

long	*find_three_max(t_node *stack_a)
{
	int		i;
	long	*nb;

	if (!stack_a)
		return (0);
	if (!(nb = (long *)malloc(sizeof(long) * (3))))
		exit (-1);
	nb[0] = -2147483649;
	nb[1] = -2147483649;
	nb[2] = -2147483649;
	nb[3] = -2147483649;
	nb[4] = -2147483649;
	nb[5] = -2147483649;
	i = 0;
	while (stack_a)
	{
		if (nb[0] < stack_a->value)
		{
			if (nb[1] < nb[0])
				nb[1] = nb[0];
			nb[0] = stack_a->value;
		}
		else if (nb[1] < stack_a->value)
		{
			if (nb[2] < nb[1])
				nb[2] = nb[1];
			nb[1] = stack_a->value;
		}
		else if (nb[2] < stack_a->value)
		{
			if (nb[3] < nb[2])
				nb[3] = nb[2];
			nb[2] = stack_a->value;
		}
		else if (nb[3] < stack_a->value)
		{
			if (nb[4] < nb[3])
				nb[4] = nb[3];
			nb[3] = stack_a->value;
		}
		else if (nb[4] < stack_a->value)
		{
			if (nb[5] < nb[4])
				nb[5] = nb[4];
			nb[4] = stack_a->value;
		}
		else if (nb[5] < stack_a->value)
		{
			if (nb[0] < nb[5])
				nb[0] = nb[5];
			nb[5] = stack_a->value;
		}
		stack_a = stack_a->next;
	}
	return (nb);
}

long	is_in_array(long *arr, int size, int value)
{
	int		i;

	i = 0;
	while (i < size)
	{
		if (arr[i++] == value)
			return (1);
	}
	return (0);
}

void	ft_selection_sort_from_b(t_stack *stack, int size)
{
	int		posmax;
	t_node	*max;

	max = find_max(stack->stack_b, &posmax);
	while (stack->stack_b)
	{
		if (stack->stack_b && stack->stack_b->value == max->value)
		{
			do_ope(stack, 4);
			size--;
			max = find_max(stack->stack_b, &posmax);
		}
		while (stack->stack_b && stack->stack_b->value != max->value)
		{
			if (posmax <= size / 2)
			{
				do_ope(stack, 7);
				posmax--;
			}
			else
			{
				do_ope(stack, 10);
				posmax++;
			}
		}
	}
}

void	ft_selection_sort(t_stack *stack, int size)
{
	int		posmax;
	int		posmin;
	int		c;
	long	*mins;
	long	*maxs;
	t_node	*min;
	t_node	*max;
	int		size2;

	size2 = size;

	c = 0;
	mins = find_three_min(stack->stack_a);
	maxs = find_three_max(stack->stack_a);

	// printf("%d %d %d\n\n", mins[0], mins[1], mins[2]);
	min = find_min(stack->stack_a, &posmin);
	max = find_max(stack->stack_a, &posmax);
	printf("%d %d %d %d %d %d\n", maxs[0], maxs[1], maxs[2], maxs[3], maxs[4], maxs[5]);
	printf("%d\n", stack->stack_a->value);
	while (stack->stack_a)
	{

		if (stack->stack_a && is_in_array(mins, 6, stack->stack_a->value))
		{
			do_ope(stack, 5);
			posmax--;
			size--;
			mins = find_three_min(stack->stack_a);
			min = find_min(stack->stack_a, &posmin);
		}
		if (stack->stack_a && is_in_array(maxs, 6, stack->stack_a->value))
		{
			do_ope(stack, 5);
			do_ope(stack, 7);
			posmin--;
			c++;
			size--;
			maxs = find_three_max(stack->stack_a);
			max = find_max(stack->stack_a, &posmax);
		}
		if (ft_imin(posmin, size - posmin) <= ft_imin(posmax, size - posmax))
			while (stack->stack_a && is_in_array(mins, 6, stack->stack_a->value) != 1)
			{
				if (posmin <= size / 2)
				{
					do_ope(stack, 6);
					posmin--;
					posmax--;
				}
				else
				{
					do_ope(stack, 9);
					posmin++;
					posmax++;
				}
			}
		else
			while (stack->stack_a && is_in_array(maxs, 6,
					stack->stack_a->value) != 1 && size != 1)
			{
				if (posmax <= size / 2)
				{
					do_ope(stack, 6);
					posmin--;
					posmax--;
				}
				else
				{
					do_ope(stack, 9);
					posmin++;
					posmax++;
				}
			}
	}
	while (c-- > 0)
		do_ope(stack, 10);
	ft_selection_sort_from_b(stack, size2);
	// while (stack->stack_b)
	// 	do_ope(stack, 4);
}


// void	ft_selection_sort_from_b(t_stack *stack)
// {
// 	int		posmax;
// 	int		posmin;
// 	int		c;
// 	t_node	*min;
// 	t_node	*max;
//
// 	min = find_min(stack->stack_a, &posmin);
// 	max = find_max(stack->stack_a, &posmax);
// 	while (stack->stack_a)
// 	{
// 		if (stack->stack_a && stack->stack_a->value == min->value)
// 		{
// 			do_ope(stack, 5);
// 			posmax--;
// 			stack->size--;
// 			min = find_min(stack->stack_a, &posmin);
// 		}
// 		if (stack->stack_a && stack->stack_a->value == max->value)
// 		{
// 			do_ope(stack, 5);
// 			do_ope(stack, 7);
// 			posmin--;
// 			c++;
// 			stack->size--;
// 			max = find_max(stack->stack_a, &posmax);
// 		}
// 		if (ft_imin(posmin, stack->size - posmin) <= ft_imin(posmax, stack->size - posmax))
// 			while (stack->stack_a && stack->stack_a->value != min->value)
// 			{
// 				if (posmin <= stack->size / 2)
// 				{
// 					do_ope(stack, 6);
// 					posmin--;
// 					posmax--;
// 				}
// 				else
// 				{
// 					do_ope(stack, 9);
// 					posmin++;
// 					posmax++;
// 				}
// 			}
// 		else
// 			while (stack->stack_a && stack->stack_a->value != max->value)
// 			{
// 				if (posmax <= stack->size / 2)
// 				{
// 					do_ope(stack, 6);
// 					posmin--;
// 					posmax--;
// 				}
// 				else
// 				{
// 					do_ope(stack, 9);
// 					posmin++;
// 					posmax++;
// 				}
// 			}
// 	}
// 	while (c-- > 0)
// 		do_ope(stack, 10);
// 	while (stack->stack_b)
// 		do_ope(stack, 4);
// }
