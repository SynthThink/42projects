/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malluin <malluin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 13:54:31 by malluin           #+#    #+#             */
/*   Updated: 2019/02/01 14:48:45 by malluin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	if (ft_strlen(str) > 11)
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

void	ft_parse(t_stack *stack, char **av, int ac)
{
	int		i;
	int		nb;
	char	*str;


	i = 1;
	if (ac == 1)
		ft_error();
	while (av[i][0] == '-' && ft_isalpha(av[i][1]) == 1)
	{
		stack->options = ft_insert(&stack->options, stack->options, &av[i][1]);
		i++;
	}
	while (i < ac)
	{
		nb = ft_verify(av[i++]);
		stack->max = stack->max < nb ? nb : stack->max;
		stack->min = stack->min > nb ? nb : stack->min;
		lst_new_back(nb, &stack->stack_a);
		stack->size++;
	}
	while (get_next_line(0, &str) > 0)
	{
		assign_op(str, stack);
		free(str);
	}
	free(str);
}
