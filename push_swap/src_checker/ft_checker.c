/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malluin <malluin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 13:47:48 by malluin           #+#    #+#             */
/*   Updated: 2019/02/01 16:26:24 by malluin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*initialize_stack(void)
{
	t_stack	*stack;

	if (!(stack = (t_stack *)malloc(sizeof(t_stack))))
		exit(-1);
	stack->stack_a = NULL;
	stack->stack_b = NULL;
	stack->operations = NULL;
	stack->options = ft_strdup("");
	stack->size = 0;
	stack->max = -2147483648;
	stack->min = 2147483647;
	stack->stop = 0;
	return (stack);
}

void	ft_check(t_stack *stack)
{
	int		i;
	t_node	*node;

	node = stack->stack_a;
	if (node)
		i = node->value;
	if (stack->stack_b != NULL)
	{
		ft_ko();
		return ;
	}
	if (node)
		node = node->next;
	while (node)
	{
		if (i == node->value)
			ft_error();
		else if (i > node->value)
		{
			ft_ko();
			return ;
		}
		i = node->value;
		node = node->next;
	}
	ft_printf("OK\n");
}

void	ft_free(t_stack *stack)
{
	t_node	*node;
	t_node	*tmp;

	node = stack->stack_a;
	while (node)
	{
		tmp = node->next;
		free(node);
		node = tmp;
	}
	node = stack->stack_b;
	while (node)
	{
		tmp = node->next;
		free(node);
		node = tmp;
	}
	node = stack->operations;
	while (node)
	{
		tmp = node->next;
		free(node);
		node = tmp;
	}
	free(stack->options);
}

int		main(int ac, char **av)
{
	t_stack	*stack;
	t_win	*mlx;

	stack = initialize_stack();
	ft_parse(stack, av, ac);
	mlx = 0;
	if (ft_strchr(stack->options, 'v') != NULL)
	{
		mlx = mlx_initialize();
		mlx->stack = (void *) stack;
		if (mlx)
		{
			ft_visualize(stack, mlx);
			mlx_key_hook(mlx->win_ptr, deal_key, (void *)mlx);
			mlx_loop_hook(mlx->mlx_ptr, ft_process_reel, (void *)mlx);
			mlx_loop(mlx->mlx_ptr);
		}
	}
	ft_process(stack, mlx, 0);
	ft_check(stack);
	ft_free(stack);
	free(stack);
}
