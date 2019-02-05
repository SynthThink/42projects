/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malluin <malluin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 19:07:54 by malluin           #+#    #+#             */
/*   Updated: 2018/12/14 13:54:57 by malluin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_int(t_output *out, t_keys *lst, va_list *ap)
{
	(void)out;
	if (lst->conv == 'd' || lst->conv == 'i')
	{
		lst->content.d = va_arg(*ap, int);
		lst->res = ft_lltoa_base(lst->content.d, 10);
	}
	else
		lst->content.d = va_arg(*ap, unsigned int);
	if (lst->conv == 'o')
		lst->res = ft_lltoa_base(lst->content.d, 8);
	else if (lst->conv == 'u')
		lst->res = ft_lltoa_base(lst->content.d, 10);
	else if (lst->conv == 'x')
		lst->res = ft_strlowcase(ft_lltoa_base(lst->content.d, 16));
	else if (lst->conv == 'X')
		lst->res = ft_lltoa_base(lst->content.d, 16);
	if ((lst->conv == 'o' || lst->conv == 'X' || lst->conv == 'x') &&
	ft_strstr(lst->options, "#") != NULL)
		ft_diese(lst);
	if (ft_strstr(lst->options, ".") != NULL)
		ft_precision(lst);
	ft_align(lst);
}

void	ft_l(t_output *out, t_keys *lst, va_list *ap)
{
	(void)out;
	if (lst->conv == 'd' || lst->conv == 'i')
	{
		lst->content.l = va_arg(*ap, long);
		lst->res = ft_lltoa_base(lst->content.l, 10);
	}
	else
		lst->content.ul = va_arg(*ap, unsigned long);
	if (lst->conv == 'o')
		lst->res = ft_lltoa_base(lst->content.ul, 8);
	else if (lst->conv == 'u')
		lst->res = ft_lltoa_base(lst->content.ul, 10);
	else if (lst->conv == 'x')
		lst->res = ft_strlowcase(ft_lltoa_base(lst->content.ul, 16));
	else if (lst->conv == 'X')
		lst->res = ft_lltoa_base(lst->content.ul, 16);
	if ((lst->conv == 'o' || lst->conv == 'X' || lst->conv == 'x') &&
	ft_strstr(lst->options, "#") != NULL)
		ft_diese(lst);
	printf("\n\n\n%s\n\n\n", lst->res);
	if (ft_strstr(lst->options, ".") != NULL)
		ft_precision(lst);
	ft_align(lst);
}

void	ft_ll(t_output *out, t_keys *lst, va_list *ap)
{
	(void)out;
	if (lst->conv == 'd' || lst->conv == 'i')
	{
		lst->content.ll = va_arg(*ap, long long);
		lst->res = ft_lltoa_base(lst->content.ll, 10);
	}
	else
		lst->content.ull = va_arg(*ap, unsigned long long);
	if (lst->conv == 'o')
		lst->res = ft_lltoa_base(lst->content.ull, 8);
	else if (lst->conv == 'u')
		lst->res = ft_lltoa_base(lst->content.ull, 10);
	else if (lst->conv == 'x')
		lst->res = ft_strlowcase(ft_lltoa_base(lst->content.ull, 16));
	else if (lst->conv == 'X')
		lst->res = ft_lltoa_base(lst->content.ull, 16);
	if ((lst->conv == 'o' || lst->conv == 'X' || lst->conv == 'x') &&
	ft_strstr(lst->options, "#") != NULL)
		ft_diese(lst);
	if (ft_strstr(lst->options, ".") != NULL)
		ft_precision(lst);
	ft_align(lst);
}

void	ft_sh(t_output *out, t_keys *lst, va_list *ap)
{
	(void)out;
	if (lst->conv == 'd' || lst->conv == 'i')
	{
		lst->content.h = (short)va_arg(*ap, int);
		lst->res = ft_lltoa_base(lst->content.h, 10);
	}
	else
		lst->content.uh = (unsigned short)va_arg(*ap, unsigned int);
	if (lst->conv == 'o')
		lst->res = ft_lltoa_base(lst->content.uh, 8);
	else if (lst->conv == 'u')
		lst->res = ft_lltoa_base(lst->content.uh, 10);
	else if (lst->conv == 'x')
		lst->res = ft_strlowcase(ft_lltoa_base(lst->content.uh, 16));
	else if (lst->conv == 'X')
		lst->res = ft_lltoa_base(lst->content.uh, 16);
	if ((lst->conv == 'o' || lst->conv == 'X' || lst->conv == 'x') &&
	ft_strstr(lst->options, "#") != NULL)
		ft_diese(lst);
	if (ft_strstr(lst->options, ".") != NULL)
		ft_precision(lst);
	ft_align(lst);
}

void	ft_shsh(t_output *out, t_keys *lst, va_list *ap)
{
	(void)out;
	if (lst->conv == 'd' || lst->conv == 'i')
	{
		lst->content.hh = (short short)va_arg(*ap, int);
		lst->res = ft_lltoa_base(lst->content.h, 10);
	}
	else
		lst->content.uhh = (unsigned short short)va_arg(*ap, unsigned int);
	if (lst->conv == 'o')
		lst->res = ft_lltoa_base(lst->content.uhh, 8);
	else if (lst->conv == 'u')
		lst->res = ft_lltoa_base(lst->content.uhh, 10);
	else if (lst->conv == 'x')
		lst->res = ft_strlowcase(ft_lltoa_base(lst->content.uhh, 16));
	else if (lst->conv == 'X')
		lst->res = ft_lltoa_base(lst->content.uhh, 16);
	if ((lst->conv == 'o' || lst->conv == 'X' || lst->conv == 'x') &&
	ft_strstr(lst->options, "#") != NULL)
		ft_diese(lst);
	if (ft_strstr(lst->options, ".") != NULL)
		ft_precision(lst);
	ft_align(lst);
}
