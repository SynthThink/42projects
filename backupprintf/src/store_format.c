/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_format.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnussbau <fnussbau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 10:20:10 by fnussbau          #+#    #+#             */
/*   Updated: 2018/12/14 13:50:59 by malluin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_diouxx(t_output *out, t_keys *lst, va_list *ap)
{
	int i;

	i = 0;
	if (ft_strcmp(lst->size, "") == 0)
	{
		out->size[0].func(out, lst, ap);
		return ;
	}
	while (ft_strcmp(out->size[i].key, lst->size) != 0 && i < 5)
			i++;
	if (i == 5)
	{
		out->size[0].func(out, lst, ap);
		return ;
	}
	out->size[i].func(out, lst, ap);
}

void	ft_char(t_output *out, t_keys *lst, va_list *ap)
{
	(void)out;
	lst->content.c = (char)va_arg(*ap, unsigned int);
	lst->res = &lst->content.c;
	ft_align(lst);
}
