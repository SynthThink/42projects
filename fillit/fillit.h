/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malluin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 15:24:22 by malluin           #+#    #+#             */
/*   Updated: 2018/11/21 16:59:48 by malluin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include "libft.h"

typedef struct		s_point
{
	short x;
	short y;
}					t_point;

typedef struct		s_tri
{
	char			name;
	char			**piece;
	t_point			coord[4];
	char			*line;
	struct s_tri	*next;
}					t_tri;

typedef struct		s_map
{
	t_tri			**pieces;
	char			**grid;
	short			min_size;
	char			nbr_pieces;
}					t_map;

void				error(void);
void				usage(char *str);
void				print_list(t_map *map);
int					min_grid_size(int nb);
void				convert_to_line(t_map **bmap);
int					format_pieces(t_map **bmap);
#endif
