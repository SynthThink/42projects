/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malluin <malluin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 11:18:06 by malluin           #+#    #+#             */
/*   Updated: 2018/12/13 15:49:55 by malluin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include "conv.h"

static t_keys *initialize(const char *format, t_output	*out)
{
	t_keys		*lst;

	if (!format)
		return (NULL);
	out->lst = NULL;
	out->fmt = ft_strdup(format);
	out->ref = set_refs();
	out->lst = scan_input(format, out->lst, out->ref);
	out->result = NULL;
	lst = out->lst;
	return (lst);
}

void	conv_args(t_output *out, t_keys *lst, va_list *ap)
{
	int		i;
	t_keys	*tmp;

	tmp = lst;
	while (tmp)
	{
		i = 0;
		while (i < 5)
		{
			if (ft_strstr(out->conv[i].key, &tmp->conv) != NULL)
				{
					out->conv[i].func(out, tmp, ap);
					break ;
				}
			i++;
		}
		tmp = tmp->next;
	}

}

int		ft_printf(const char *format, ...)
{
	t_output	*out;
	t_keys		*lst;
	va_list		ap;

	if (!(out = (t_output *)malloc(sizeof(t_output))))
		return (0);
	lst = initialize(format, out);
	out->conv = g_conv; // initialisation de la list de pointer sur fonctions
	out->size = g_size;
	va_start(ap, format);
	conv_args(out, lst, &ap);
	// ft_putendl("/////////");
	print_args(out);
	// ft_putendl("/////////");
	// valid_arg(out);
	assemble_res(out);
	// printf("%d",ft_strlen(out->fmt));

	printf("===========TEST============\n");
	printf("%s <<<---- RESULT\n", out->result);
	// printf("%s <<<---- ARG\n", out->lst->res);
	// printf("%s <<<---- ARG\n", out->lst->next->res);
	va_end(ap);
	return (0);
}
