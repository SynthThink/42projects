/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malluin <malluin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 12:47:34 by malluin           #+#    #+#             */
/*   Updated: 2018/12/11 14:14:51 by malluin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	incomplete_error()
{
	ft_putstr("incomplete format specifier.");
	exit(-1);
}

void	incompatible_type()
{
	exit(-1);
}
