/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_col.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malluin <malluin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 16:49:19 by malluin           #+#    #+#             */
/*   Updated: 2019/01/29 17:24:15 by malluin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include <sys/ioctl.h>

void	print_tab(char **tab)
{
	int		i;

	i = 0;
	while (tab[i])
		printf("%s\n", tab[i++]);
}

void	fill(int pad, int size, t_file *file)
{
	char	**tab;
	int		i;
	char	*fill;

	i = 0;
	if (!(tab = (char **)malloc(sizeof(char *) * (size + 1))))
		exit(-1);
	while (i < size)
		if (!(tab[i++] = (char *)ft_memalloc(sizeof(char) * (1))))
			exit(-1);
	tab[i] = 0;
	while (file)
	{
		i = i >= size - 1 ? 0 : i + 1;
		fill = ft_memcset(1 + pad - ft_strlen(file->name), ' ');
		tab[i] = ft_insert(&tab[i], tab[i] + ft_strlen(tab[i]), file->name);
		tab[i] = ft_insert(&tab[i], tab[i] + ft_strlen(tab[i]), fill);
		free(fill);
		file = file->next;
	}
	i = 0;
	print_tab(tab);
	while (tab[i])
		free(tab[i++]);
	free(tab);
}

int		count_lines(t_file *file, int pad, int width)
{
	int		cumul;
	int		line;

	cumul = 0;
	line = 1;
	while (file)
	{
		cumul += pad;
		if (cumul >= width)
		{
			cumul = pad;
			line++;
		}
		file = file->next;
	}
	return (line);
}

void	col_print(t_sys *sys, t_file *dir)
{
	t_file			*file;
	int				pad;
	int				count;
	int				temp;
	struct winsize	w;

	ioctl(0, TIOCGWINSZ, &w);
	file = sys->files;
	pad = 0;
	count = 0;
	while (file)
	{
		count++;
		temp = ft_strlen(file->name);
		pad = temp > pad ? temp : pad;
		file = file->next;
	}
	pad = pad > w.ws_col ? w.ws_col - 2 : pad;
	file = sys->files;
	fill(pad, count_lines(file, pad, w.ws_col), file);
	if (dir->next != NULL)
		ft_printf("\n");
}
