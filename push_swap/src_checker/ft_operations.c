/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_operations.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malluin <malluin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 18:26:07 by malluin           #+#    #+#             */
/*   Updated: 2019/01/30 18:27:25 by malluin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_node **lst)
{
	t_node	*tmp;

	if (lst && *lst && (*lst)->next)
	{
		tmp = (*lst)->next;
		(*lst)->next = tmp->next;
		tmp->next = *lst;
		*lst = tmp;
	}
}

void	rotate(t_node **lst)
{
	t_node	*tmp;
	t_node	*tmp2;

	if (lst && *lst && (*lst)->next)
	{
		tmp = *lst;
		*lst = ((*lst)->next);
		tmp2 = *lst;
		while (tmp2->next)
			tmp2 = tmp2->next;
		tmp2->next = tmp;
		tmp->next = NULL;
	}
}

void	reverse_rotate(t_node **lst)
{
	t_node	*tmp;
	t_node	*tmp2;

	if (lst && *lst && (*lst)->next)
	{
		tmp = *lst;
		tmp2 = NULL;
		while (tmp->next)
		{
			tmp2 = tmp;
			tmp = tmp->next;
		}
		if (tmp2 != NULL)
			tmp2->next = NULL;
		tmp->next = *lst;
		*lst = tmp;
	}
}

void	push_a(t_node **lsta, t_node **lstb)
{
	t_node	*tmp;

	tmp = *lstb;
	if (tmp)
	{
		*lstb = ((*lstb)->next);
		tmp->next = *lsta;
		*lsta = tmp;
	}
}

void	push_b(t_node **lsta, t_node **lstb)
{
	t_node	*tmp;

	tmp = *lsta;
	if (tmp)
	{
		*lsta = ((*lsta)->next);
		tmp->next = *lstb;
		*lstb = tmp;
	}
}
