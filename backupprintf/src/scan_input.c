/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scan_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnussbau <fnussbau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 15:39:54 by fnussbau          #+#    #+#             */
/*   Updated: 2018/12/13 18:02:02 by malluin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "libftprintf.h"

static t_keys	*parse(const char *str, t_keys *lst_key, t_ref *ref)
{
	int k;

	k = 0;
	while (str[k] != '\0')
	{
		while (is_options(str[k], ref))
		{
			lst_key->options = ft_strncat(lst_key->options, &str[k], 1);
			k++;
		}
		if (str[k] >= 48 && str[k] <= 57)
		{
			lst_key->length = ft_atoi(&str[k]);
			while (str[k] >= 48 && str[k] <= 57)
				k++;
		}
		if (str[k] == '.')
		{
			lst_key->options = ft_insert(&(lst_key->options),
				ft_strlen(lst_key->options), "."); // code malluin
			k++;
			if (str[k] >= 48 && str[k] <= 57)
			{
				lst_key->prec = ft_itoa(ft_atoi(&str[k]));
				while (str[k] >= 48 && str[k] <= 57)
					k++;
			}
		}
		while (is_size(str[k], ref))
		{
			lst_key->size = ft_strncat(lst_key->size, &str[k], 1);
			k++;
		}
		while (is_conv(str[k], ref))
		{
			lst_key->conv = str[k];
			return (lst_key);
			k++;
		}
		k++;
	}

	return (NULL);
}

t_keys			*scan_input(const char *str, t_keys *lst_key, t_ref *ref)
{
	int		k;
	int		j;
	int		count;
	t_keys	*tmp;

	k = 0;
	count = 0;
	while (str[k] != '\0')
	{
		if (str[k] == '%')
		{
			j = 0;
			k++;
			while (str[k + j] && !is_conv(str[k + j], ref))
				j++;
			tmp = lst_new_elem(j);
			parse(&str[k], tmp, ref);
			tmp->origin = ft_strsub(str, k - 1, j + 2);
			lst_key = lst_add_end(lst_key, tmp);
			count++;
		}
		k++;
	}
	return (lst_key);
}
