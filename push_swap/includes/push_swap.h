/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malluin <malluin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 11:18:34 by malluin           #+#    #+#             */
/*   Updated: 2019/02/05 18:03:28 by malluin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H
# include "libftprintf.h"
# include "get_next_line.h"
/*# include "visu.h"*/

typedef struct		s_tuple {
	int				i;
	int				j;
}					t_tuple;

typedef struct		s_node {
	int				value;
	char			sorted;
	struct s_node	*next;
}					t_node;

typedef	struct		s_stack {
	t_node			*stack_a;
	t_node			*stack_b;
	t_node			*operations;
	char			*options;
	int				size;
	int				count;
	int				min;
	int				max;
	int				stop;
}					t_stack;

//int					ft_visualize(t_stack *stack, t_win *mlx);
//int					ft_process_reel(t_win *mlx);
t_node				*lst_new_node(int content);
void				swap(t_node **lst);
void				rotate(t_node **lst);
void				reverse_rotate(t_node **lst);
void				push_a(t_node **lsta, t_node **lstb);
void				push_b(t_node **lsta, t_node **lstb);
void				lst_new_front(int content, t_node **lst);
void				lst_new_back(int content, t_node **lst);
void				lst_insert_sort(char *content, t_node **lst, int tsort,
					char *path);
void				lst_insert_rsort(char *content, t_node **lst, int tsort,
					char *path);
void				print_list(t_node *lst, char *str);
void				ft_parse(t_stack *stack, char **av, int ac);
void				ft_check(t_stack *stack);

void				ft_error();
void				ft_ko();

void				ft_process_inf(t_stack *stack, char val);
void				ft_process_sup(t_stack *stack, char val);
//void				ft_process(t_stack *stack, t_win *mlx, int mode);

void				swap_nodes_intra_a(t_node *node_a, t_node *node_b,
					t_node *stack_top, t_stack *stack);

void				ft_quick_sort(t_stack *stack);
void				ft_bubble_sort(t_stack *stack);
void				ft_selection_sort(t_stack *stack, int size);

void				do_ope(t_stack *stack, int nb);
int					has_duplicates(t_node *stack);
int					is_sort(t_node *stack);
t_node			*get_end(t_node *stack);
long				is_in_array(long *arr, int size, int value);

int					get_lst_len(t_node *tmp);
void				set_pivot_sorted(t_node *node, int pvalue);
int					find_min_int(t_node *node, int threshold);
int					find_median(t_node *node, int size);

/*t_win			*mlx_initialize();

int				map_to_proj(t_win *mlx);
int				proj_to_screen(t_win *mlx);

int				rgb(unsigned char red, unsigned char green, unsigned char blue);

void			xline(t_win *mlx, t_pix px1, t_pix px2);
void			yline(t_win *mlx, t_pix px1, t_pix px2);
int				mouse_line(int button, int x, int y, void *param);
void			place_line(t_win *param, t_pix px1, t_pix px2);
void			place_pixel(t_win *mlx, int x, int y, int color);

int				refresh_legend(void *param);
void			legend_text(t_win *mlx);
void			legend_box(t_win *mlx);
void			boxes(t_win *mlx);
void			draw_grid(t_win	*mlx);

int				image_init(t_win *mlx);
int				refresh_init(t_win *mlx);
int				refresh_show(t_win *mlx, t_stack *stack);

int				deal_key(int key, void *param);

void			color_init(t_win *mlx);
int				*palette_init(char *av);*/

#endif
