/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malluin <malluin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 11:02:28 by malluin           #+#    #+#             */
/*   Updated: 2018/12/13 17:55:16 by malluin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdio.h>

void	print_args(t_output *out) // pour tester resultat sur les ints
{
	t_keys		*tmp;

	tmp = out->lst;
	ft_putstr(out->fmt);
	ft_putchar('\n');
	while (tmp)
	{
		fac_opt(tmp, out->ref);
		printf("ADR et NEXT // KEY // ORIGIN // CONV ---- \n>>  %p->%p // %s%d.%s%s%c // %s // %d\n", tmp, tmp->next,
				tmp->options, tmp->length, tmp->prec,
				tmp->size, tmp->conv, tmp->origin, tmp->content.d);
		tmp = tmp->next;
	}
}

char	*replace_double_per(char *fmt) // replace double % par simple %
{
	char *begin;
	int i;

	begin = fmt;
	while (*fmt)
	{
		if(*fmt == '%' && (*fmt + 1) && *(fmt + 1) == '%')
		{
			i = ft_strlen(fmt + 2);
			ft_memmove((fmt + 1), (fmt + 2), i);
			(fmt + 1)[i] = '\0';
		}
		fmt++;
	}
	return (begin);
}

char	*clean_fmt(char *fmt, int size, t_keys	*lst)
{
	char *tmp;
	char *dest;
	int i;

	if (!(dest = (char *)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	ft_memcpyeol(dest, fmt, ft_strlen(fmt));
	while (*fmt && lst)
	{
		fmt = dest;
		fmt = skip_to_per(fmt);
		if (!*fmt)
			break;
		if (*fmt)
			tmp = (fmt++);
		while (*fmt && is_option(*fmt))
			(fmt)++;
		i = ft_strlen(++(fmt));
		ft_memmove(tmp, (fmt), i);
		(tmp)[i] = '\0';
		dest = ft_insert(&dest, tmp, lst->res);
		if (lst)
			lst = lst->next;
	}
	return (dest);
}

void	assemble_res(t_output *out)
{
	t_keys	*tmp;
	int			c;

	c = 0;
	if (out->fmt)
		c = ft_strlen(out->fmt);
	tmp = out->lst;
	while(tmp)
	{
		if (tmp->res)
			c += ft_strlen(tmp->res);
		//c+= 100;
		tmp = tmp->next;
	}
	if (c != 0)
		out->result = clean_fmt(out->fmt, c, out->lst);
	// out->result = replace_double_per(out->fmt);
}
