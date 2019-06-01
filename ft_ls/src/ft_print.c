/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malluin <malluin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/15 18:15:29 by malluin           #+#    #+#             */
/*   Updated: 2019/01/29 17:23:15 by malluin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	long_print(t_sys *sys, t_file *file)
{
	struct stat	buf;

	if ((lstat(file->path, &buf)) != -1)
	{
		print_type(buf.st_mode);
		print_links(sys, buf.st_nlink);
		print_user(sys, file);
		print_size(sys, buf);
		if (ft_strchr(sys->options, 'u') != NULL)
			print_time(sys, buf.st_atime);
		else
			print_time(sys, buf.st_mtime);
	}
}

void	save_max(t_sys *sys, struct stat buf, t_file *file)
{
	struct passwd	*pwd;
	struct group	*grp;
	int				i;

	if (!(pwd = getpwuid(buf.st_uid)))
		ft_error(file->name);
	if (!(grp = getgrgid(buf.st_gid)))
		ft_error(file->name);
	file->user = ft_strdup(pwd->pw_name);
	file->group = ft_strdup(grp->gr_name);
	if (buf.st_size > sys->size_pad)
		sys->size_pad = buf.st_size;
	if (buf.st_nlink > sys->links_pad)
		sys->links_pad = buf.st_nlink;
	i = ft_strlen(file->user);
	if (i > sys->login_pad)
		sys->login_pad = i;
	i = ft_strlen(file->group);
	if (i > sys->group_pad)
		sys->group_pad = i;
	if ((buf.st_rdev << 8) >> 8 > sys->minor_pad)
		sys->minor_pad = (buf.st_rdev << 8) >> 8;
	if (buf.st_rdev >> 24 > sys->major_pad)
		sys->major_pad = buf.st_rdev >> 24;
}

void	save_padding(t_sys *sys, t_file *file)
{
	struct stat	buf;
	int			total;

	total = 0;
	sys->login_pad = 0;
	while (file)
	{
		if ((lstat(file->path, &buf)) != -1)
		{
			save_max(sys, buf, file);
			total += buf.st_blocks;
		}
		file = file->next;
	}
	sys->size_pad = ft_numlen(sys->size_pad);
	sys->links_pad = ft_numlen(sys->links_pad);
	sys->major_pad = ft_numlen(sys->major_pad);
	sys->minor_pad = ft_numlen(sys->minor_pad);
	if (sys->total == 1)
		ft_printf("total %d\n", total);
}

void	print_files(t_sys *sys, t_file *dir)
{
	t_file	*file;
	short	opt;

	opt = ft_strchr(sys->options, 'l') != NULL ? 1 : 0;
	if (dir == NULL)
		dir = lst_new_node(ft_strdup("./"));
	file = sys->files;
	if (opt == 1 && sys->files != NULL)
		save_padding(sys, file);
	while (file)
	{
		if (opt == 1)
			long_print(sys, file);
		ft_printf("%s", file->name);
		if (opt == 1)
			print_symb(file);
		ft_printf("\n");
		file = file->next;
	}
	if ((dir && dir->next != NULL) || (sys->total == 0 && sys->dirs != NULL))
		ft_printf("\n");
	sys->size_pad = 0;
	sys->links_pad = 0;
	sys->major_pad = 0;
	sys->minor_pad = 0;
}

void	print_list(t_file *lst)
{
	short i;

	i = 0;
	while (lst)
	{
		ft_printf("lst %d |%s|\n", i, lst->name);
		lst = lst->next;
		i++;
	}
}
