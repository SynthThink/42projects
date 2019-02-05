/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malluin <malluin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 10:26:56 by malluin           #+#    #+#             */
/*   Updated: 2019/02/04 18:41:27 by malluin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*lst_new_node(int content)
{
	t_node *tmp;

	if (!(tmp = (t_node *)malloc(sizeof(t_node))))
		return (NULL);
	tmp->value = content;
	tmp->sorted = 0;
	tmp->next = NULL;
	return (tmp);
}

void	lst_new_front(int content, t_node **lst)
{
	t_node	*tmp;

	tmp = lst_new_node(content);
	tmp->next = *lst;
	*lst = tmp;
}

void	lst_new_back(int content, t_node **lst)
{
	t_node	*tmp;
	t_node	*node;

	node = *lst;
	tmp = lst_new_node(content);
	if (!*lst)
		*lst = tmp;
	else
	{
		while (node->next)
			node = node->next;
		node->next = tmp;
	}
}

void	print_list(t_node *lst, char *str)
{
	int		i;

	i = 0;
	while (lst)
	{
		ft_printf("|%-6s lst %-2d: %5d %5d\n", str, i++, lst->value, lst->sorted);
		lst = lst->next;
	}
	ft_printf("\n");
}
