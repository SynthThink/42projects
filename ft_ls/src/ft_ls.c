/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malluin <malluin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/11 11:24:52 by malluin           #+#    #+#             */
/*   Updated: 2019/01/29 17:33:20 by malluin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	pre_read(t_sys *sys)
{
	if (sys->nb_tar > 1)
		sys->title = 1;
	if (sys->files)
	{
		print_files(sys, 0);
		free_files(&sys->files, 1);
	}
	sys->total = 1;
}

void	ft_ls(t_sys *sys)
{
	t_file	*tmp;
	t_file	*new_dirs;

	tmp = sys->dirs;
	pre_read(sys);
	while (tmp)
	{
		new_dirs = read_dir(sys, tmp->name);
		lst_insert_dirs(&new_dirs, &tmp);
		set_path_all(sys->files, tmp->name);
		if (sys->title)
			ft_printf("%s:\n", tmp->name);
		sys->title = tmp->next != NULL ? 1 : 0;
		if (sys->files != NULL && (sys->l == 1))
			print_files(sys, tmp);
		else if (sys->files != NULL)
			col_print(sys, tmp);
		else
			ft_printf("\n");
		tmp = tmp->next;
		free_files(&sys->files, 1);
	}
}

int		main(int ac, char **av)
{
	t_sys	*sys;

	sys = initialize_sys();
	parse(ac, av, sys);
	check_options(sys);
	sys->l = ft_strchr(sys->options, 'l') != NULL ||
		ft_strchr(sys->options, '1') != NULL ? 1 : 0;
	ft_ls(sys);
	free_sys(sys);
	return (0);
}
