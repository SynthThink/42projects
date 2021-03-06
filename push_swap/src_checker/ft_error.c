/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malluin <malluin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 16:05:09 by malluin           #+#    #+#             */
/*   Updated: 2019/02/13 19:08:38 by malluin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_error(void)
{
	write(2, "Error\n", 6);
	exit(-1);
}

void	ft_ko(void)
{
	write(1, "KO\n", 3);
	exit(-1);
}

void	ft_usage(void)
{
	write(1, "./checker [-hv] [list of integers]\n", 35);
}
