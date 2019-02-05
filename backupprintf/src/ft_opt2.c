/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_opt2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malluin <malluin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 11:33:13 by malluin           #+#    #+#             */
/*   Updated: 2018/12/14 13:55:31 by malluin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*zero_padding(char **str, int length)
{
	char	*cat;
	int		i;
	int		padding;

	i = 0;
	padding = length - ft_strlen(*str);
	if (!(cat = (char *)malloc(sizeof(char) * (padding + 1))))
		return (NULL);
	while (i < padding)
		cat[i++] = '0';
	cat[i] = '\0';
	*str = ft_insert(str, *str + (**str == '-' || **str == '+'), cat);
	free(cat);
	return (*str);
}

void	ft_diese(t_keys *lst)
{
	if (lst->conv == 'o')
	{
		if (lst->res && lst->res[0] != '0')
			lst->res = ft_insert(&lst->res, lst->res, "0");
	}
	else if (lst->conv == 'x')
	{
		if (lst->res && lst->res[0] != '0')
			lst->res = ft_insert(&lst->res, lst->res, "0x");
	}
	else if (lst->conv == 'X')
	{
		if (lst->res && lst->res[0] != '0')
			lst->res = ft_insert(&lst->res, lst->res, "0X");
	}
}

void	ft_precision(t_keys *l)
{
	int		len;
	int		prec;
	int		b;
	char	*fill;

	b = 0;
	if (ft_strstr(l->options, "#") != NULL)
		b = l->conv == 'x' || l->conv == 'X' ? b + 2 : b;
	len = ft_strlen(l->res) - b;
	if (l->prec[0] == '\0')
		return ;
	prec = ft_atoi(l->prec);
	if (l->conv == 's')
		if (len > prec)
			l->res[prec] = '\0';
	len = l->res[0] == '-' ? len - 1 : len;
	l->res[0] = l->res[0] == '0' ? '\0' : l->res[0];
	if (l->conv != 's')
		if (prec > len)
		{
			if (!(fill = (char *)malloc(sizeof(char) * (prec - len + 1))))
				exit(-1);
			fill = ft_memset(fill, '0', prec - len);
			fill[prec - len] = '\0';
			l->res = ft_insert(&l->res, l->res + b + (l->res[0] == '-'), fill);
		}
}
