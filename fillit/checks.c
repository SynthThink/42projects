/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malluin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 11:54:55 by malluin           #+#    #+#             */
/*   Updated: 2018/11/21 17:06:59 by malluin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

int		check_touch(t_tri *pc, int ok)
{
	int i;
	int j;

	i = -1;
	while (++i < 4)
	{
		j = -1;
		while (++j < 4)
			if (pc->piece[i][j] == '#')
			{
				if (j > 0)
					ok = pc->piece[i][j - 1] == '#' ? ok + 1 : ok;
				if (i > 0)
					ok = pc->piece[i - 1][j] == '#' ? ok + 1 : ok;
				if (i < 3)
					ok = pc->piece[i + 1][j] == '#' ? ok + 1 : ok;
				if (j < 3)
					ok = pc->piece[i][j + 1] == '#' ? ok + 1 : ok;
			}
	}
	if (ok < 6)
		return (0);
	return (1);
}

int		check_pieces(t_tri **pieces, int nb)
{
	int i;
	int j;
	int nbd;
	int nbp;

	i = 0;
	j = 0;
	while (i < nb)
	{
		nbp = 0;
		nbd = 0;
		while (j < 16)
		{
			if (pieces[i]->piece[j / 4][j % 4] == '#')
				nbd++;
			else if (pieces[i]->piece[j / 4][j % 4] == '.')
				nbp++;
			j++;
		}
		j = 0;
		if (nbp != 12 || nbd != 4 || check_touch(pieces[i], 0) == 0)
			return (0);
		i++;
	}
	return (1);
}

char	**move(char **tab, int ecol, int erow)
{
	int i;
	int j;

	i = -1;
	j = -1;
	while (++i < 4)
	{
		while (++j < 4)
			if (tab[i][j] == '#')
			{
				tab[i - erow][j - ecol] = '#';
				tab[i][j] = '.';
			}
		j = -1;
	}
	return (tab);
}

char	**move_piece(char **tab, int ecol, int erow)
{
	int i;

	i = -1;
	while (++i < 4)
	{
		if (tab[i][0] == '.' && tab[i][1] == '.' &&
				tab[i][2] == '.' && tab[i][3] == '.')
			erow++;
		else
			break ;
	}
	i = -1;
	while (++i < 4)
	{
		if (tab[0][i] == '.' && tab[1][i] == '.' &&
				tab[2][i] == '.' && tab[3][i] == '.')
			ecol++;
		else
			break ;
	}
	if (erow > 0 || ecol > 0)
		tab = move(tab, ecol, erow);
	return (tab);
}

t_tri	*set_coord(t_tri *pc)
{
	int i;
	int j;
	int k;

	i = -1;
	j = -1;
	k = 0;
	while (++i < 4)
	{
		while (++j < 4)
		{
			if (pc->piece[i][j] == '#')
			{
				pc->coord[k].x = i;
				pc->coord[k].y = j;
				k++;
			}
		}
		j = -1;
	}
	return (pc);
}

int		format_pieces(t_map **bmap)
{
	t_map	*map;
	int		i;

	i = 0;
	map = *bmap;
	if (check_pieces(map->pieces, map->nbr_pieces) == 0)
		return (0);
	while (i < map->nbr_pieces)
	{
		map->pieces[i]->piece = move_piece(map->pieces[i]->piece, 0, 0);
		map->pieces[i] = set_coord(map->pieces[i]);
		i++;
	}
	return (1);
}
