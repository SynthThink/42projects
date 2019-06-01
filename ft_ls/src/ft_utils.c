/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malluin <malluin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 17:44:11 by malluin           #+#    #+#             */
/*   Updated: 2019/01/29 14:27:48 by malluin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	set_path_all(t_file *file, char *path)
{
	int		i;

	while (file)
	{
		if (path)
		{
			if (!(file->path = (char *)malloc(sizeof(char) * (ft_strlen(path) +
				ft_strlen(file->name) + 2))))
				exit(-1);
			i = ft_strlen(path);
			ft_memcpy(file->path, path, i);
			file->path[i] = '/';
			ft_memcpyeol(file->path + i + 1, file->name, ft_strlen(file->name));
		}
		else
			file->path = ft_strdup(file->name);
		file = file->next;
	}
}

void	set_path(t_file *file, char *path)
{
	int		i;

	if (path)
	{
		if (!(file->path = (char *)malloc(sizeof(char) * (ft_strlen(path) +
			ft_strlen(file->name) + 2))))
			exit(-1);
		i = ft_strlen(path);
		ft_memcpy(file->path, path, i);
		file->path[i] = '/';
		ft_memcpyeol(file->path + i + 1, file->name, ft_strlen(file->name));
	}
	else
		file->path = ft_strdup(file->name);
}

int		is_hidden(t_sys *sys, char *str)
{
	if (ft_strchr(sys->options, 'a') == NULL && str[0] == '.')
		return (0);
	return (1);
}

void	check_options(t_sys *sys)
{
	int		i;
	char	*s;

	i = 0;
	if (ft_strchr(sys->options, 'g') != NULL)
		if (ft_strchr(sys->options, 'l') == NULL)
			sys->options = ft_insert(&sys->options, sys->options, "l");
	s = sys->options;
	while (s[i])
	{
		if (ft_strchr("Raglrtu1", s[i]) == NULL)
		{
			usage(s[i]);
			exit(-1);
		}
		i++;
	}
}
