/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_readdir.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malluin <malluin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 11:01:46 by malluin           #+#    #+#             */
/*   Updated: 2019/01/29 17:04:00 by malluin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	treat_dir(t_sys *sys, struct dirent *tmp, t_file **dir, char *av)
{
	char			*str;
	int				tsort;

	tsort = ft_strchr(sys->options, 't') != 0 ? 1 : 0;
	if (is_hidden(sys, tmp->d_name))
	{
		str = ft_strdup(tmp->d_name);
		if (ft_strchr(sys->options, 'r') != NULL)
			lst_insert_rsort(str, &sys->files, tsort, av);
		else
			lst_insert_sort(str, &sys->files, tsort, av);
	}
	if (tmp->d_type != 8 && is_ddir(tmp->d_name) == 0 &&
		ft_strchr(sys->options, 'R') != NULL && is_hidden(sys, tmp->d_name))
	{
		str = ft_strjoin(av, "/");
		str = ft_insert(&str, str + ft_strlen(str), tmp->d_name);
		if (is_dir(str) && ft_strchr(sys->options, 'r') != NULL)
			lst_insert_rsort(str, dir, tsort, "");
		else if (is_dir(str))
			lst_insert_sort(str, dir, tsort, "");
		else
			free(str);
	}
}

t_file	*read_dir(t_sys *sys, char *av)
{
	DIR				*dir_ptr;
	struct dirent	*tmp;
	t_file			*dir;

	dir = NULL;
	if (!(dir_ptr = opendir((const char *)av)))
	{
		if (ft_strchr(sys->options, 'R') != NULL)
			ft_printf("%s:\n", av);
		ft_error(av);
		sys->title = 0;
	}
	while (dir_ptr != NULL && (tmp = readdir(dir_ptr)) != NULL)
		treat_dir(sys, tmp, &dir, av);
	if (ft_strstr(av, "/dev/fd") == 0)
		if (dir_ptr != NULL && closedir(dir_ptr) == -1)
			ft_error(av);
	return (dir);
}

void	lst_insert_dirs(t_file **new_dirs, t_file **tmp)
{
	t_file	*tmpchild;

	if (*new_dirs != NULL)
	{
		tmpchild = (*tmp)->next;
		(*tmp)->next = *new_dirs;
		while ((*new_dirs)->next)
			(*new_dirs) = (*new_dirs)->next;
		(*new_dirs)->next = tmpchild;
	}
}
