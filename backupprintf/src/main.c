/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malluin <malluin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 11:19:05 by malluin           #+#    #+#             */
/*   Updated: 2018/12/18 15:09:37 by malluin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <limits.h>
#include <float.h>

t_double	*converge_exp(t_double *doub)
{
	char	*tmp;

	printf("||dot %d||", doub->dot);
	doub->dot = (ft_strlen(doub->expconv) - 1) - doub->dot ;
	doub->result = ft_strdup(doub->mantconv);
	doub->mantdec = ft_strdup("");
	if (doub->dot > 0)
	{
		tmp = ft_memcset(ft_iabs(doub->dot), '0');
		doub->result = ft_insert(&doub->result, doub->result +
			ft_strlen(doub->result), tmp);
		ft_strdel(&tmp);
	}
	else if (doub->dot < 0)
	{
		printf("\n\n%s\n\n", doub->result);
		tmp = ft_strdup(&doub->mantconv[ft_strlen(doub->mantconv)
			- ft_iabs(doub->dot)]);
		tmp[ft_iabs(doub->dot)] = '\0';
		doub->mantdec = ft_insert(&doub->mantdec, doub->mantdec, tmp);
		doub->result[ft_strlen(doub->mantconv) - ft_iabs(doub->dot)] = '\0';
		printf("\n\n%s\n\n", doub->result);
		ft_strdel(&tmp);
	}
	return (doub);
}

t_double	*converge_exp_neg(t_double *doub)
{
	char	*tmp;

	printf("||dot %d||", doub->dot);
	doub->dot = (ft_strlen(doub->expconv) - 1) - doub->dot ;
	printf("||dot %d||", doub->dot);
	doub->result = ft_strdup(doub->mantconv);
	doub->mantdec = ft_strdup("");
	if (doub->dot > 0)
	{
		tmp = ft_memcset(ft_iabs(doub->dot), '0');
		doub->result = ft_insert(&doub->result, doub->result +
			ft_strlen(doub->result), tmp);
		ft_strdel(&tmp);
	}
	else if (doub->dot < 0)
	{
		printf("\n\n%s\n\n", doub->result);
		tmp = ft_strdup(&doub->mantconv[ft_strlen(doub->mantconv)
			- ft_iabs(doub->dot)]);
		tmp[ft_iabs(doub->dot)] = '\0';
		doub->mantdec = ft_insert(&doub->mantdec, doub->mantdec, tmp);
		doub->result[ft_strlen(doub->mantconv) - ft_iabs(doub->dot)] = '\0';
		printf("\n\n%s\n\n", doub->result);
		ft_strdel(&tmp);
	}
	return (doub);
}

char	*ft_strdecdivtwo(char *s1)
{
	char	*res;
	size_t	i;
	size_t	len;
	int		calc;
	int		carry;

	i = 0;
	carry = 0;
	len = ft_strlen(s1);
	res = ft_strdup("");
	while ((i < len || carry != 0) && i < 500)
	{
		i = s1[i] == '.' ? i + 1 : i;
		if (s1[i] == '.')
			continue ;
		carry = carry * 10;
		calc = i < len ? (s1[i] - 48 + carry) / 2 : carry / 2;
		if ((i == len || s1[i - 1] == '.') && !ft_strchr(res, '.'))
			res = ft_insert(&res, res + ft_strlen(res), ".");
		if (!(i == 0 && calc == 0 ) || res[0] != '.')
			res = ft_insert(&res, res + ft_strlen(res), ft_itoa(calc));
		carry = i < len ? ((s1[i] - 48) + carry) % 2 : carry % 2;
		i++;
	}
	return (res);
}

char	*ft_strnegpower(char **s, int nb)
{
	int		i;
	char	*tmp;
	int		len;

	tmp = *s;
	i = 0;
	while (i++ < nb)
		*s = ft_strdecdivtwo(*s);
	free(tmp);
	i = 0;
	while ((*s)[i] == '0')
		i++;
	len = ft_strlen((*s) + i);
	ft_memmove(*s, (*s) + i, len);
	(*s)[len] = '\0';
	return (*s);
}

int		main(int ac, char **av)
{
	// t_ref	*ref;
	// t_keys	*lst_key;
	// t_keys	*tmp;
	// char	*format;

	t_double *test;
	double f;
	f = 0.01524212425;
	test = double_byte(f);
	printf("mantisse binaire:%s\nsigne:%d\nexponent binaire:%s\nexponent dec:%d\n", test->mantbin, test->sign, test->expbin, test->expnb);
	printf("exponent conv:%s mantisse conv:%s dot:%d\nmantdec:|%s|\nresult:|%s|", test->expconv, test->mantconv, test->dot,test->mantdec,  test->result);
	printf("\nprintf |%.45lf|", f);

	// printf("%s", ft_strdecdivtwo(av[1]));

	// printf("%s", bin_to_dec("101"));

	// test = 5.445554354354354353454544543;
	// ft_printf(av[1], ft_atol(av[2]), ft_atol(av[3]));
	// printf(av[1], ft_atol(av[2]), ft_atol(av[3]));

	// printf("%.25lf", test);

	// printf("%s >>> iota base \n", ft_lltoa_base(-42, 16));
	// printf("%s >>> iota base \n", ft_lltoa_base(42, 16));

// 	short s;
// short short ss;
// 	s = 32767;
// 	ss = 12;
// 	ft_printf("%hd >>> my printf short\n", s);
// 	printf("%hd >>> short\n", s);
// 	ft_printf("%hd >>> my printf short short\n", ss);
//
// 	printf("%hd >>> short short\n", ss);
// 	printf("--------\n");
//
// 	ft_printf("%ld >>> my prinft long\n", 2147483690);
// 	printf("%ld >>> long\n", 2147483690);
//
// 	ft_printf("%lld >>> my prinft long\n", 2147483690);

	// long long l;
	// l = 9223372036854775820;
	// printf("\n-----------------char-----------------------\n");
	// char c = 126;
	// ft_printf("%c >>> ft_printf char\n", c);
	// printf("%c >>> printf char\n", c);



	// printf("%lx >>> long\n", l);

	// printf("%hd >>> short\n", 32768);
	// printf("%#X\n", 454);
	// printf("%x\n", 5);
	// printf("%03u", -42);
	// printf("TEST-- i %#i\n", 42);
	// printf("TEST-- o %#o\n", 42);
	// printf("TEST-- u %#u\n", 42);
	// printf("TEST-- x %#x\n", 42);
	// printf("TEST-- X %#X\n", 42);
	// printf("TEST--  %-+#0 10.4d\n", 42);
	// printf("\nTEST - string 10 prec 4 %.4s\n", "abcde12345");

	return (0);
}
