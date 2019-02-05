/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_action.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnussbau <fnussbau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 17:09:36 by fnussbau          #+#    #+#             */
/*   Updated: 2018/12/14 10:58:18 by malluin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "libftprintf.h"

t_keys	*lst_new_elem(int size)
{
	t_keys *tmp;

	if (!(tmp = (t_keys *)malloc(sizeof(t_keys))))
		return (0);
	if (!(tmp->options = (char *)malloc(sizeof(char) * (size + 1))))
		return (0);
	if (!(tmp->size = (char *)malloc(sizeof(char) * (size + 1))))
		return (0);
	tmp->length = 0;
	tmp->prec = ft_strdup("0");
	tmp->size = ft_strdup("");
	tmp->next = NULL;
	return (tmp);
}

t_keys	*lst_add_end(t_keys *alst, t_keys *new)
{
	t_keys *tmp;

	if (new)
	{
		if (alst == NULL)
			alst = new;
		else
		{
			tmp = alst;
			while (tmp->next)
				tmp = tmp->next;
			tmp->next = new;
		}
		return (alst);
	}
	return (alst);
}
