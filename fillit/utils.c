/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malluin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 17:39:05 by malluin           #+#    #+#             */
/*   Updated: 2018/11/21 12:24:44 by malluin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		min_grid_size(int nb)
{
	int i;

	i = 1;
	if (nb <= 0)
		return (0);
	while ((i * i) < nb)
	{
		i++;
		if (i > 50)
			return (0);
	}
	return (i);
}

void	convert_to_line(t_map **bmap)
{
	int		i;
	int		j;
	t_map	*map;

	map = *bmap;
	i = 0;
	j = 0;
	while (i < map->nbr_pieces)
	{
		map->pieces[i]->line = (char *)malloc(sizeof(char) * 17);
		while (j < 16)
		{
			map->pieces[i]->line[j] = map->pieces[i]->piece[j / 4][j % 4];
			j++;
		}
		map->pieces[i]->line[16] = '\0';
		i++;
		j = 0;
	}
}
