/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malluin <malluin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 10:26:56 by malluin           #+#    #+#             */
/*   Updated: 2019/01/29 11:01:18 by malluin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_file	*lst_new_node(char *content)
{
	t_file *tmp;

	if (!(tmp = (t_file *)malloc(sizeof(t_file))))
		return (NULL);
	tmp->name = content;
	tmp->next = NULL;
	return (tmp);
}

void	lst_new_front(char *content, t_file **lst)
{
	t_file	*tmp;

	tmp = lst_new_node(content);
	tmp->next = *lst;
	*lst = tmp;
}

void	lst_new_back(char *content, t_file **lst)
{
	t_file	*tmp;
	t_file	*node;

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

void	lst_insert_sort(char *content, t_file **lst, int tsort, char *path)
{
	t_file	*tmp;
	t_file	*node;
	t_file	*parent;

	if ((*lst && content && ft_cmpjoin(content,
			(*lst)->name, path, tsort) <= 0) || !*lst)
		lst_new_front(content, lst);
	else
	{
		tmp = lst_new_node(content);
		parent = *lst;
		node = *lst;
		while (node && ft_cmpjoin(tmp->name, node->name, path, tsort) > 0)
		{
			parent = node;
			node = node->next;
		}
		parent->next = tmp;
		if (node != NULL && parent != node)
			tmp->next = node;
	}
}

void	lst_insert_rsort(char *content, t_file **lst, int tsort, char *path)
{
	t_file	*tmp;
	t_file	*node;
	t_file	*parent;

	if ((*lst && content && ft_cmpjoin(content,
			(*lst)->name, path, tsort) >= 0) || !*lst)
		lst_new_front(content, lst);
	else
	{
		tmp = lst_new_node(content);
		parent = *lst;
		node = *lst;
		while (node && ft_cmpjoin(tmp->name, node->name, path, tsort) < 0)
		{
			parent = node;
			node = node->next;
		}
		parent->next = tmp;
		if (node != NULL && parent != node)
			tmp->next = node;
	}
}
