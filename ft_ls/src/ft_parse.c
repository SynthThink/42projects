/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malluin <malluin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 11:37:33 by malluin           #+#    #+#             */
/*   Updated: 2019/01/29 12:27:36 by malluin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_sys		*initialize_sys(void)
{
	t_sys	*sys;

	if (!(sys = (t_sys *)malloc(sizeof(t_sys))))
		exit(-1);
	sys->dirs = NULL;
	sys->files = NULL;
	sys->options = NULL;
	sys->nb_tar = 0;
	sys->title = 0;
	sys->size_pad = 0;
	sys->links_pad = 0;
	sys->login_pad = 0;
	sys->group_pad = 0;
	sys->major_pad = 0;
	sys->minor_pad = 0;
	sys->t = time(0);
	sys->blank = 0;
	return (sys);
}

static char	*parse_opts(int ac, char **av)
{
	char	*opts;
	short	i;

	opts = ft_strdup("");
	if (ac == 1)
		return (opts);
	i = 1;
	while (i < ac)
	{
		if (av[i][0] == '-' && av[i][1] != '\0')
			opts = ft_insert(&opts, opts, &av[i][1]);
		else
			break ;
		i++;
	}
	return (opts);
}

void		insert_to_lst(t_sys *sys, char **tmp, int tsort)
{
	if (is_pres(*tmp) == 1)
	{
		if (is_dir(*tmp) != 1)
		{
			if (ft_strchr(sys->options, 'r') != NULL)
				lst_insert_rsort(*tmp, &sys->files, tsort, "");
			else
				lst_insert_sort(*tmp, &sys->files, tsort, "");
			sys->blank = 5;
		}
		else
		{
			if (ft_strchr(sys->options, 'r') != NULL)
				lst_insert_rsort(*tmp, &sys->dirs, tsort, "");
			else
				lst_insert_sort(*tmp, &sys->dirs, tsort, "");
		}
	}
	else
	{
		ft_error(*tmp);
		sys->blank = sys->blank == 0 ? 1 : sys->blank;
		free(*tmp);
	}
	sys->nb_tar += 1;
}

void		parse(int ac, char **av, t_sys *sys)
{
	short	i;
	char	*tmp;
	int		tsort;

	sys->options = parse_opts(ac, av);
	tsort = ft_strchr(sys->options, 't') != 0 ? 1 : 0;
	i = 1;
	while (i < ac && (av[i][0] == '-' && av[i][1] != '\0'))
		i++;
	while (i < ac)
	{
		tmp = ft_strdup(av[i++]);
		insert_to_lst(sys, &tmp, tsort);
	}
	if (sys->dirs == NULL && sys->files == NULL && sys->nb_tar == 0)
	{
		tmp = ft_strdup(".");
		lst_new_front(tmp, &sys->dirs);
	}
	if (sys->files != NULL)
		set_path_all(sys->files, 0);
}
