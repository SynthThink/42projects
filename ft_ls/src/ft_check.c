/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malluin <malluin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/15 18:14:11 by malluin           #+#    #+#             */
/*   Updated: 2019/01/29 10:56:47 by malluin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		is_ddir(char *str)
{
	if ((str[0] == '.' && str[1] == '\0') || (str[0] == '.' && str[1] == '.' &&
		str[2] == '\0'))
		return (1);
	return (0);
}

int		is_dir(char *str)
{
	struct stat	buf;

	if ((lstat(str, &buf)) == -1)
	{
		ft_error(str);
		return (-1);
	}
	if (S_ISDIR(buf.st_mode))
		return (1);
	return (0);
}

int		is_slnk(char *str)
{
	struct stat	buf;

	if ((lstat(str, &buf)) == -1)
	{
		ft_error(str);
		return (-1);
	}
	if (S_ISLNK(buf.st_mode))
		return (1);
	return (0);
}

int		is_pres(char *str)
{
	struct stat	buf;

	if ((lstat(str, &buf)) == -1)
		return (-1);
	return (1);
}

int		is_reg(char *str)
{
	struct stat	buf;

	if ((lstat(str, &buf)) == -1)
	{
		ft_error(str);
		return (-1);
	}
	if (S_ISREG(buf.st_mode))
		return (1);
	return (0);
}
