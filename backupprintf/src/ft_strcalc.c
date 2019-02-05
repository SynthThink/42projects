/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcalc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malluin <malluin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 18:42:26 by malluin           #+#    #+#             */
/*   Updated: 2018/12/18 12:14:34 by malluin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*ft_stradd(char *s1, char *s2, int base)
{
	char	*result;
	short	res;
	short	carry;
	short	i;
	short	j;

	i = ft_imax(ft_strlen(s1), ft_strlen(s2)) - 1;
	j = ft_imin(ft_strlen(s1), ft_strlen(s2)) - 1;
	if (ft_strlen(s2) > ft_strlen(s1))
		ft_pswap(&s2, &s1);
	result = ft_strxdup(s1, i + 2);
	carry = 0;
	while (i >= 0 || carry == 1)
	{
		if (i >= 0)
			res = j >= 0 ? s1[i] - 96 + s2[j] + carry : s1[i] + carry - 48;
		j--;
		carry = res >= base ? 1 : 0;
		res = res >= base ? res - base : res;
		if (i >= 0)
			result[i--] = res + 48;
		else
		{
			result = ft_insert(&result, result, "1");
			carry = 0;
		}
	}
	return (result);
}

char	*ft_strmul(char *s1, char *s2, int base)
{
	char	*res;
	short	i;
	short	j;

	i = ft_imax(ft_strlen(s1), ft_strlen(s2)) - 1;
	if (ft_strlen(s2) > ft_strlen(s1))
		ft_pswap(&s2, &s1);
	if ((s1[0] == '0' && s1[1] == '\0') || (s2[0] == '0' && s2[1] == '\0'))
	{
		res = ft_strdup("0");
		return (res);
	}
	res = ft_strxdup("", ft_strlen(s1) + ft_strlen(s2) + 2);
	while (i >= 0)
	{
		j = -1;
		while (++j < (int)(s1[i]) - 48)
			res = ft_stradd(s2, res, base);
		s2 = ft_strdup(s2);
		s2 = ft_insert(&s2, s2 + ft_strlen(s2), "0");
		i--;
	}
	return (res);
}



char	*bin_to_dec(char *nb)
{
	char	*mult;
	char	*res;
	short	i;

	i = ft_strlen(nb) - 1;
	mult = ft_strdup("1");
	res = ft_strdup("0");
	while (i >= 0)
	{
		if (nb[i--] == '1')
			res = ft_stradd(res, mult, 10);
		mult = ft_strmul(mult, "2", 10);
	}
	return (res);
}
