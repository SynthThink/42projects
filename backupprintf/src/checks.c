/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnussbau <fnussbau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 15:29:18 by fnussbau          #+#    #+#             */
/*   Updated: 2018/12/11 13:30:34 by malluin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "libftprintf.h"
#include <stdlib.h>

int		is_options(char c, t_ref *ref)
{
	int k;
	int count;

	k = 0;
	count = 0;
	while (ref->options[k])
	{
		if (ref->options[k] == c)
			count++;
		k++;
	}
	return (count);
}

int		is_size(char c, t_ref *ref)
{
	int k;
	int count;

	k = 0;
	count = 0;
	while (ref->size[k])
	{
		if (ref->size[k] == c)
			count++;
		k++;
	}
	return (count);
}

int		is_conv(char c, t_ref *ref)
{
	int k;
	int count;

	k = 0;
	count = 0;
	while (ref->conv[k])
	{
		if (ref->conv[k] == c)
			count++;
		k++;
	}
	return (count);
}
