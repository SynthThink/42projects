/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_elem2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malluin <malluin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 16:59:28 by malluin           #+#    #+#             */
/*   Updated: 2019/01/29 10:51:39 by malluin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	print_user(t_sys *sys, t_file *file)
{
	char	*fill;
	char	*fillgrp;

	fill = ft_memcset(2 + (int)sys->login_pad -
		ft_strlen(file->user), ' ');
	fillgrp = ft_memcset(0 + (int)sys->group_pad -
		ft_strlen(file->group), ' ');
	if (ft_strchr(sys->options, 'g') == NULL)
		ft_printf("%s%s%s%s", file->user, fill, file->group, fillgrp);
	else
		ft_printf("%s%s", file->group, fillgrp);
	free(file->group);
	free(file->user);
	free(fill);
	free(fillgrp);
}

void	print_symb(t_file *file)
{
	char	buf[256];

	ft_bzero((void *)buf, 256);
	if (is_slnk(file->path) == 1)
	{
		readlink(file->path, buf, 256);
		ft_printf(" -> %s", buf);
	}
}
