/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lltoa_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <exam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 10:03:56 by exam              #+#    #+#             */
/*   Updated: 2018/12/14 13:44:20 by malluin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	ft_reduce(long long value, int base, char *out, int size)
{
	char	*b;
	int		sign;

	b = ft_strdup("0123456789ABCDEF");
	sign = 0;
	if (value < 0 && base == 10)
		sign = 1;
	out[size] = '\0';
	if (value < 0 && base == 10)
		out[0] = '-';
	else if (value < 0)
		value = -value;
	size--;
	while (value && size >= sign)
	{
		out[size] = b[ft_iabs(value % base)];
		size--;
		value = value / base;
	}
}

char	*ft_lltoa_base(long long value, int base)
{
	long long	m;
	int			size;
	char		*out;
	char		*zero;

	size = 0;
	m = value;
	if (base < 2 || base > 16)
		return (NULL);
	else if (value == 0)
	{
		zero = ft_strdup("0");
		return (zero);
	}
	if (value < 0 && base == 10)
		size++;
	while (m != 0)
		m = (++size) ? m / base : m / base;
	if (!(out = (char *)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	ft_reduce(value, base, out, size);
	return (out);
}
