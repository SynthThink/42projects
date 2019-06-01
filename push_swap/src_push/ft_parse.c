/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malluin <malluin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 13:54:31 by malluin           #+#    #+#             */
/*   Updated: 2019/03/08 17:12:28 by malluin          ###   ########.fr       */
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
	stack->count = 0;
	stack->size = 0;
	return (stack);
}

int		has_non_sorted(t_node *node)
{
	while (node)
	{
		if (node->sorted == 0)
			return (1);
		node = node->next;
	}
	return (0);
}

int		ft_verify(char *str)
{
	long	nb;
	int		i;
	int		ok;

	i = str[0] == '-' ? 1 : 0;
	ok = 0;
	while (str[i] != '\0')
	{
		if (!ft_isdigit(str[i++]))
			ft_error();
		else
			ok = 1;
	}
	if (ft_strlen(str) > 11 || ok == 0)
		ft_error();
	nb = ft_atol(str);
	if (nb < -2147483648 || nb > 2147483647)
		ft_error();
	return (nb);
}

void	ft_parse(t_stack *stack, char **av, int ac)
{
	int		i;
	int		nb;

	i = 1;
	if (ac == 1)
		ft_error();
	while (i < ac && av[i][0] == '-' && ft_isalpha(av[i][1]) == 1)
	{
		stack->options = ft_insert(&stack->options, stack->options, &av[i][1]);
		i++;
	}
	while (i < ac)
	{
		nb = ft_verify(av[i++]);
		lst_new_back(nb, &stack->stack_a);
		stack->size++;
	}
	if (stack->stack_a == NULL)
		ft_error();
	if (has_duplicates(stack->stack_a) == 0)
		ft_error();
}
