/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malluin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 15:16:43 by malluin           #+#    #+#             */
/*   Updated: 2018/11/21 17:09:46 by malluin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	error(void)
{
	ft_putstr("error\n");
}

void	usage(char *str)
{
	ft_putstr("usage: ");
	ft_putstr(str);
	ft_putstr(" descriptor file\n");
}

void	print_list(t_map *map)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < map->nbr_pieces)
	{
		while (j < 4)
		{
			ft_putstr(map->pieces[i]->piece[j]);
			ft_putchar(' ');
			ft_putchar(map->pieces[i]->name);
			ft_putchar('\n');
			j++;
		}
		ft_putstr(map->pieces[i]->line);
		ft_putnbr( map->pieces[i]->coord[0].x);
		ft_putnbr(map->pieces[i]->coord[0].y);
		ft_putchar('\n');
		ft_putchar('\n');
		i++;
		j = 0;
	}
	ft_putnbr(map->nbr_pieces);
	ft_putchar('\n');
	ft_putnbr(map->min_size);
}
