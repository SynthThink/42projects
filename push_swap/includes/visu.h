/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visu.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malluin <malluin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 18:22:25 by malluin           #+#    #+#             */
/*   Updated: 2019/02/01 15:20:15 by malluin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VISU_H
# define VISU_H

# define WIDTH 1024
# define HEIGHT 768
// # define XOFF (WIDTH / 2)
// # define YOFF (HEIGHT / 10)

# include "mlx.h"
# include "libft.h"
# include "push_swap.h"

typedef struct	s_pix
{
	int			x;
	int			y;
	int			color;
}				t_pix;

typedef struct	s_der {
	int			dx;
	int			dy;
	int			e;
	int			signe;
	int			or;
	int			swap;
}				t_der;

typedef	struct	s_win {
	void		*mlx_ptr;
	void		*win_ptr;
	void		*image_ptr;
	char		*image_str;
	t_pix		**map;
	void		*stack;
}				t_win;

#endif
