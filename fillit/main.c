/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malluin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 12:28:13 by malluin           #+#    #+#             */
/*   Updated: 2018/11/26 17:05:36 by malluin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

/* Remplit char ** avec le fichier lu */
char	**fill_table(char *av1, int *j)
{
	int		fd;
	char	**tab;
	char	*line;
	int		i;

	i = 0;
	fd = open(av1, O_RDONLY);
	if (fd == -1 || !(tab = (char **)malloc(sizeof(char *) * 135)))
		return (NULL);
	while (get_next_line(fd, &line) > 0)
	{
		tab[i++] = ft_strdup(line);
		free(line);
		if (i > 129)
			return (NULL);
	}
	tab[i] = 0;
	*j = i;
	return (tab);
}

/*
** Remplit la liste de pieces a partir de char et Check si chaque 5e
**ligne est strlen 0 et chaque ligne de piece strlen 4 sinon NULL
*/

t_tri	**fill_lst(char **tab, int i)
{
	t_tri	**pieces;

	if (!(pieces = (t_tri **)malloc(sizeof(t_tri*) * (1 + i / 5))))
		return (NULL);
	i = -1;
	while (tab[++i])
	{
		if (i % 5 == 0)
			if (!(pieces[i / 5] = (t_tri *)malloc(sizeof(t_tri))) ||
			(!(pieces[i / 5]->piece = (char **)malloc(sizeof(char *) * 4))))
				return (NULL);
		if ((i + 1) % 5)
		{
			if (ft_strlen(tab[i]) != 4)
				return (NULL);
			pieces[i / 5]->name = 65 + i / 5;
			pieces[i / 5]->piece[i % 5] = ft_strdup(tab[i]);
		}
		if (!((i + 1) % 5))
			if (ft_strlen(tab[i]) != 0)
				return (NULL);
	}
	return (pieces);
}

t_map	*prel_check(char *av1)
{
	t_map	*map;
	char	**tab;
	int		i;

	if (!(map = (t_map *)malloc(sizeof(t_map))))    // malloc map
		return (NULL);
	if (!(tab = fill_table(av1, &i)))				// remplit tab avec read
		return (NULL);
	if (((i - 4) % 5) != 0)
		return (NULL);
	if (!((map->pieces) = fill_lst(tab, i))) // malloc + remplissage pieces
		return (NULL);
	map->nbr_pieces = (i + 1) / 5;
	map->min_size = min_grid_size(map->nbr_pieces * 4);
	if ((format_pieces(&map)) == 0)
		return (NULL);
	convert_to_line(&map); // convertir tab** en un char * pour chaque piece
	print_list(map);  // print a enlever
	free(tab); // free le char ** qui a lu le fichier
	return (map);
}

int		main(int ac, char **av)
{
	t_map	*map;

	if (ac != 2)
	{
		usage(av[0]);
		return (0);
	}
	if ((map = prel_check(av[1])) == NULL)
	{
		error();
		return (0);
	}
	return (0);
}
