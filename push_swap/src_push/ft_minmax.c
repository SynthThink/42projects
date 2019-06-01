/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minmax.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malluin <malluin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 16:10:02 by malluin           #+#    #+#             */
/*   Updated: 2019/02/08 12:15:17 by malluin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		find_min(t_node *stack_a, int *index)
{
	int		i;
	int		j;

	if (!stack_a)
		return (0);
	i = stack_a->value;
	j = 0;
	*index = 0;
	stack_a = stack_a->next;
	while (stack_a)
	{
		j++;
		if (i > stack_a->value)
		{
			i = stack_a->value;
			*index = j;
		}
		stack_a = stack_a->next;
	}
	return (i);
}

int		find_max(t_node *stack_a, int *index)
{
	int		i;
	int		j;

	if (!stack_a)
		return (0);
	i = stack_a->value;
	j = 0;
	*index = 0;
	stack_a = stack_a->next;
	while (stack_a)
	{
		j++;
		if (i < stack_a->value)
		{
			i = stack_a->value;
			*index = j;
		}
		stack_a = stack_a->next;
	}
	return (i);
}

long	*find_n_min(t_node *stack_a, int size)
{
	int		i;
	long	*nb;

	if (!stack_a)
		return (0);
	if (!(nb = (long *)malloc(sizeof(long) * (size + 1))))
		exit(-1);
	i = 0;
	while (i < size)
		nb[i++] = 2147483647;
	nb[0] = find_min_int(stack_a, -2147483649);
	i = 1;
	while (i < size)
	{
		nb[i] = find_min_int(stack_a, nb[i - 1]);
		i++;
	}
	return (nb);
}

long	*find_n_max(t_node *stack_a, int size)
{
	int		i;
	long	*nb;

	if (!stack_a)
		return (0);
	if (!(nb = (long *)malloc(sizeof(long) * (size + 1))))
		exit(-1);
	i = 0;
	while (i < size)
		nb[i++] = -2147483648;
	nb[0] = find_max_int(stack_a, 2147483648);
	i = 1;
	while (i < size)
	{
		nb[i] = find_max_int(stack_a, nb[i - 1]);
		i++;
	}
	return (nb);
}
