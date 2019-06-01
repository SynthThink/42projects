/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malluin <malluin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 15:57:36 by malluin           #+#    #+#             */
/*   Updated: 2019/01/29 10:57:57 by malluin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	free_node(t_file *file)
{
	if (file != NULL)
	{
		free(file->name);
		free(file);
		file = NULL;
	}
}

void	free_files(t_file **file, int opt)
{
	t_file	*tmp;
	t_file	*node;

	node = *file;
	while (node)
	{
		tmp = node;
		node = node->next;
		if (opt == 1)
			free(tmp->path);
		free_node(tmp);
	}
	*file = NULL;
}

void	free_sys(t_sys *sys)
{
	t_file	*tmp;
	t_file	*node;

	tmp = sys->dirs;
	while (tmp)
	{
		node = tmp;
		tmp = tmp->next;
		free(node->name);
		free(node);
	}
	free(sys->options);
	free(sys);
}
