/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_elem.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malluin <malluin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 18:05:24 by malluin           #+#    #+#             */
/*   Updated: 2019/01/29 18:05:14 by malluin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	print_permissions(mode_t st_mode)
{
	char	*str;

	if (!(str = ft_memalloc(sizeof(char) * 10)))
		exit(-1);
	str[0] = S_IRUSR & st_mode ? 'r' : '-';
	str[1] = S_IWUSR & st_mode ? 'w' : '-';
	str[2] = S_IXUSR & st_mode ? 'x' : '-';
	if (S_ISUID & st_mode)
		str[2] = str[2] == 'x' ? 's' : 'S';
	str[3] = S_IRGRP & st_mode ? 'r' : '-';
	str[4] = S_IWGRP & st_mode ? 'w' : '-';
	str[5] = S_IXGRP & st_mode ? 'x' : '-';
	if (S_ISGID & st_mode)
		str[5] = str[5] == 'x' ? 's' : 'S';
	str[6] = S_IROTH & st_mode ? 'r' : '-';
	str[7] = S_IWOTH & st_mode ? 'w' : '-';
	str[8] = S_IXOTH & st_mode ? 'x' : '-';
	if (S_ISVTX & st_mode)
		str[8] = str[8] == 'x' ? 't' : 'T';
	str[9] = '\0';
	ft_printf("%s", str);
	free(str);
}

void	print_type(mode_t st_mode)
{
	if (S_ISREG(st_mode))
		ft_printf("-");
	else if (S_ISDIR(st_mode))
		ft_printf("d");
	else if (S_ISLNK(st_mode))
		ft_printf("l");
	else if (S_ISSOCK(st_mode))
		ft_printf("s");
	else if (S_ISFIFO(st_mode))
		ft_printf("p");
	else if (S_ISCHR(st_mode))
		ft_printf("c");
	else if (S_ISBLK(st_mode))
		ft_printf("b");
	else
		ft_printf("-");
	print_permissions(st_mode);
}

void	print_size(t_sys *sys, struct stat buf)
{
	char	*fill;
	char	*fil;
	int		minor;
	int		major;
	off_t	st_size;

	if (buf.st_rdev != 0)
	{
		major = buf.st_rdev >> 24;
		minor = (buf.st_rdev << 8) >> 8;
		fill = ft_memcset(1 + (int)sys->minor_pad - ft_numlen((int)minor), ' ');
		fil = ft_memcset(3 + (int)sys->major_pad - ft_numlen((int)major), ' ');
		ft_printf("%s%d,%s%d ", fil, major, fill, minor);
		free(fil);
	}
	else
	{
		major = (sys->major_pad != 1 || sys->minor_pad != 1)
			? sys->major_pad + sys->minor_pad + 3 : 0;
		st_size = buf.st_size;
		major = ft_imax(sys->size_pad, major);
		fill = ft_memcset(2 + major - ft_numlen(st_size), ' ');
		ft_printf("%s%lld ", fill, st_size);
	}
	free(fill);
}

void	print_links(t_sys *sys, nlink_t st_nlink)
{
	char	*fill;

	fill = ft_memcset(2 + (int)sys->links_pad - ft_numlen((int)st_nlink), ' ');
	ft_printf("%s%d ", fill, st_nlink);
	free(fill);
}

void	print_time(t_sys *sys, time_t st_time)
{
	char	*time_var;
	int		i;
	int		j;

	i = 0;
	time_var = ctime(&st_time);
	while (time_var[i] != ' ')
		i++;
	i++;
	j = i;
	while (time_var[j])
		j++;
	if (sys->t < st_time || st_time + 15724800 < sys->t)
		ft_memmove(time_var + j - 14, time_var + j - 6, 5);
	time_var[j - 9] = '\0';
	ft_printf("%s ", &time_var[i]);
}
