/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_parsing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malluin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 15:04:59 by malluin           #+#    #+#             */
/*   Updated: 2018/12/10 15:06:32 by malluin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char *skip_to_per(char * fmt)
{
	while (*fmt && (*fmt != '%' || (*fmt == '%' && *(fmt + 1) == '%')))
	{
		while (*fmt && *fmt != '%')
			fmt++;
		while (*(fmt) == '%' && *(fmt + 1) == '%')
			fmt += 2;
	}
	return (fmt);
}

int		is_option(char c)
{
	if (c == '#' || c == ' ' || c == '+' || c == '-' || c == '0')
		return (1);
	if (c >= '0' && c <= '9')
		return (2);
	if (c == '.')
		return (3);
	if (c == 'l' || c == 'h' || c == 'L')
		return (4);
	return (0);
}

int		is_type(char c)
{
	if (c == 'd' || c == 'i' || c == 'o' || c == 'u' || c == 'x' || c == 'X')
		return (1);
	if (c >= 'f')
		return (2);
	if (c == 'c' || c == 's'|| c == 'p')
		return (3);
	return (0);
}
