/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malluin <malluin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 18:22:25 by malluin           #+#    #+#             */
/*   Updated: 2018/12/06 17:01:19 by malluin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# define WIDTH 1920
# define HEIGHT 1080
# define XOFF (WIDTH / 2)
# define YOFF (HEIGHT / 10)

# include "mlx.h"
# include "libft.h"

typedef struct	s_point
{
	int			x;
	int			y;
	int			z;
	int			color;
}				t_point;

typedef	struct	s_win {
	void		*mlx_ptr;
	void		*win_ptr;
	void		*image_ptr;
	char		*image_str;
	int			*palette;
	float		scale;
}				t_win;

int				refresh_init(t_win *mlx);
int				refresh_show(t_win *mlx);
void			place_pixel(t_win *mlx, int x, int y, int color);
int				deal_key(int key, void *param);
int				mouse(int button, int x, int y, void *param);
#endif
