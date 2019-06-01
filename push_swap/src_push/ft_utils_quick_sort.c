/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_quick_sort.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malluin <malluin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/05 16:13:45 by malluin           #+#    #+#             */
/*   Updated: 2019/02/08 12:15:51 by malluin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		get_lst_len(t_node *tmp)
{
	int len;

	len = 0;
	while (tmp)
	{
		len++;
		tmp = tmp->next;
	}
	return (len);
}

void	set_pivot_sorted(t_node *node, int pvalue)
{
	while (node)
	{
		if (node->value == pvalue)
			node->sorted = 1;
		node = node->next;
	}
}

int		find_min_int(t_node *tmp, long threshold)
{
	int		min;

	min = 2147483647;
	while (tmp)
	{
		if (min > tmp->value && tmp->value > threshold)
			min = tmp->value;
		tmp = tmp->next;
	}
	return (min);
}

int		find_max_int(t_node *tmp, long threshold)
{
	int		max;

	max = -2147483648;
	while (tmp)
	{
		if (max < tmp->value && tmp->value < threshold)
			max = tmp->value;
		tmp = tmp->next;
	}
	return (max);
}

int		find_median(t_node *node, int size)
{
	int		*nb;
	int		med;
	int		i;

	i = 0;
	if (!(nb = (int *)malloc(sizeof(int) * (size / 2 + 3))))
		exit(-1);
	while (i < size / 2)
	{
		if (i > 0)
			nb[i] = find_min_int(node, nb[i - 1]);
		else
			nb[i] = find_min_int(node, -2147483648);
		i++;
	}
	med = 2147483647;
	while (node)
	{
		if (med > node->value && node->value > nb[i - 1])
			med = node->value;
		node = node->next;
	}
	free(nb);
	return (med);
}
