/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malluin <malluin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 11:18:34 by malluin           #+#    #+#             */
/*   Updated: 2019/02/22 14:46:43 by malluin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libftprintf.h"
# include "get_next_line.h"
# include "visu.h"

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
	int				op_count;
}					t_stack;

typedef struct		s_min {
	int				pmax;
	int				pmin;
	long			*mins;
	long			*maxs;
	char			minmax;
}					t_min;

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
void				ft_parse_checker(t_stack *stack, char **av, int ac, int i);
void				ft_parse(t_stack *stack, char **av, int ac);
void				ft_check(t_stack *stack);

void				ft_error();
void				ft_ko();

t_stack				*initialize_stack(void);
void				ft_process_inf(t_stack *stack, char val);
void				ft_process_sup(t_stack *stack, char val);
void				ft_process(t_stack *stack, t_win *mlx, int mode);

void				ft_selection_sort(t_stack *stack, int size, char minmax);

void				do_ope(t_stack *stack, int nb);
int					has_duplicates(t_node *stack);
int					is_sort(t_node *stack);
t_node				*get_end(t_node *stack);
long				is_in_array(long *arr, int size, int value);

int					has_non_sorted(t_node *node);
int					get_lst_len(t_node *tmp);
void				set_pivot_sorted(t_node *node, int pvalue);
int					find_min_int(t_node *node, long threshold);
int					find_max_int(t_node *node, long threshold);
int					find_median(t_node *node, int size);
int					find_min(t_node *stack_a, int *index);
int					find_max(t_node *stack_a, int *index);
long				*find_n_min(t_node *stack_a, int size);
long				*find_n_max(t_node *stack_a, int size);

void				ft_print_ope(t_node *operations);
void				ft_usage(void);

int					ft_visualize(t_stack *stack, t_win *mlx);
int					ft_process_reel(t_win *mlx);
t_win				*mlx_initialize();
int					rgb(unsigned char red, unsigned char green,
					unsigned char blue);
void				place_pixel(t_win *mlx, int x, int y, int color);
int					image_init(t_win *mlx);
int					refresh_init(t_win *mlx);
int					refresh_show(t_win *mlx, t_stack *stack);
int					deal_key(int key, void *param);

#endif
