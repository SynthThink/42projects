/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_errors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malluin <malluin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 16:14:54 by malluin           #+#    #+#             */
/*   Updated: 2019/01/17 12:33:31 by malluin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_error(char *str)
{
	int		i;

	i = 0;
	while (str[i])
		i++;
	while (i > 0 && str[i] != '/')
		i--;
	if (i != 0)
		i++;
	ft_printf("ft_ls: %s: %s\n", &str[i], strerror(errno));
}

void	usage(char c)
{
	ft_printf("ft_ls: illegal option -- %c\n", c);
	ft_printf("usage: ft_ls [-1Raglrtu] [file ...]\n");
}
