/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malluin <malluin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 13:54:31 by malluin           #+#    #+#             */
/*   Updated: 2019/02/22 14:48:41 by malluin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		has_duplicates_checker(t_node *stack, int size)
{
	t_node	*node;
	t_node	*cmp;
	int		i;

	node = stack;
	if (size == 0)
		exit(-1);
	if (node)
		i = node->value;
	node = node->next;
	while (node)
	{
		cmp = node;
		while (cmp)
		{
			if (i == cmp->value)
				ft_error();
			cmp = cmp->next;
		}
		i = node->value;
		node = node->next;
	}
	return (1);
}

void	assign_op(char *str, t_stack *stack)
{
	if (ft_strcmp(str, "sa") == 0)
		lst_new_back(1, &stack->operations);
	else if (ft_strcmp(str, "sb") == 0)
		lst_new_back(2, &stack->operations);
	else if (ft_strcmp(str, "ss") == 0)
		lst_new_back(3, &stack->operations);
	else if (ft_strcmp(str, "pa") == 0)
		lst_new_back(4, &stack->operations);
	else if (ft_strcmp(str, "pb") == 0)
		lst_new_back(5, &stack->operations);
	else if (ft_strcmp(str, "ra") == 0)
		lst_new_back(6, &stack->operations);
	else if (ft_strcmp(str, "rb") == 0)
		lst_new_back(7, &stack->operations);
	else if (ft_strcmp(str, "rr") == 0)
		lst_new_back(8, &stack->operations);
	else if (ft_strcmp(str, "rra") == 0)
		lst_new_back(9, &stack->operations);
	else if (ft_strcmp(str, "rrb") == 0)
		lst_new_back(10, &stack->operations);
	else if (ft_strcmp(str, "rrr") == 0)
		lst_new_back(11, &stack->operations);
	else
		ft_error();
}

int		ft_verify(char *str)
{
	long	nb;
	int		i;

	i = str[0] == '-' ? 1 : 0;
	if (ft_strlen(str) > 11 || str[i] == '\0')
		ft_error();
	while (str[i] != '\0')
	{
		if (!ft_isdigit(str[i++]))
			ft_error();
	}
	nb = ft_atol(str);
	if (nb < -2147483648 || nb > 2147483647)
		ft_error();
	return (nb);
}

void	ft_parse_checker(t_stack *sk, char **av, int ac, int i)
{
	int		nb;
	char	*str;

	while (i < ac && av[i][0] == '-' && ft_isalpha(av[i][1]) == 1)
		sk->options = ft_insert(&sk->options, sk->options, &av[i++][1]);
	while (i < ac)
	{
		nb = ft_verify(av[i++]);
		sk->max = sk->max < nb ? nb : sk->max;
		sk->min = sk->min > nb ? nb : sk->min;
		lst_new_back(nb, &sk->stack_a);
		sk->size++;
	}
	if (ft_strchr(sk->options, 'h') != NULL && sk->size == 0)
		ft_usage();
	has_duplicates_checker(sk->stack_a, sk->size);
	str = NULL;
	if (read(0, &str, 0) == -1)
		ft_error();
	while (get_next_line(0, &str) > 0)
	{
		assign_op(str, sk);
		ft_memdel((void **)&str);
	}
	ft_memdel((void **)&str);
}
