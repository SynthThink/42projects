/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bytes.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malluin <malluin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 18:45:00 by malluin           #+#    #+#             */
/*   Updated: 2018/12/18 15:12:32 by malluin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

t_double	*calc_exp(t_double *doub)
{
	int i;

	i = 0;
	i = ft_strlen(doub->mantbin);
	while (i >= 0 && doub->mantbin[i - 1] != '1')
		i--;
	doub->dot = i;
	return (doub);
}

unsigned char *conv_bytes_double(double f)
{
	unsigned char *byte;
	unsigned char *p;
	int i;

	if (!(byte = (unsigned char *)malloc(sizeof(unsigned char) * 65)))
		exit(-1);
	i = 0;
	p = (unsigned char *)&f;
	while (i < 64)
	{
		byte[i] = (p[7 - i / 8] >> (7 - i % 8)) & 1 ? '1' : '0';
		i++;
	}
	byte[i] = '\0';
	return (byte);
}

unsigned char *conv_bytes_float(float f)
{
	unsigned char *byte;
	unsigned char *p;
	int i;

	if (!(byte = (unsigned char *)malloc(sizeof(unsigned char) * 33)))
		exit(-1);
	i = 0;
	p = (unsigned char *)&f;
	while (i < 32)
	{
		byte[i] = (p[3 - i / 8] >> (7 - i % 8)) & 1 ? '1' : '0';
		i++;
	}
	byte[i] = '\0';
	return (byte);
}

t_double	*double_convert_pos(t_double *doub)
{
	doub = calc_exp(doub);
	doub->mantconv = ft_strdup(doub->mantbin);
	doub->mantconv[doub->dot] = '\0';
	doub->mantconv = ft_insert(&doub->mantconv, doub->mantconv, "1");
	doub = converge_exp(doub);
	doub->result = bin_to_dec(doub->result);
	doub->mantdec = bin_to_dec(doub->mantdec);
	if (doub->dot < 0)
	{
		doub->mantdec = ft_strnegpower(&doub->mantdec, ft_iabs(doub->dot));
		doub->result = ft_insert(&doub->result, doub->result + ft_strlen(doub->result), ft_strchr(doub->mantdec, '.'));
	}
	if (doub->sign == 1)
	doub->result = ft_insert(&doub->result, doub->result, "-");
	return (doub);
}

t_double	*double_convert_neg(t_double *doub)
{
	doub = calc_exp(doub);
	doub->mantconv = ft_strdup(doub->mantbin);
	doub->mantconv[doub->dot] = '\0';
	doub->mantconv = ft_insert(&doub->mantconv, doub->mantconv, "1");
	doub->result = bin_to_dec(doub->mantconv);
	doub->result = ft_strnegpower(&doub->result, doub->dot - doub->expnb);
	if (doub->result[0] == '.')
		doub->result = ft_insert(&doub->result, doub->result, "0");
	if (doub->sign == 1)
		doub->result = ft_insert(&doub->result, doub->result, "-");
	return (doub);
}

t_double *double_byte(double f)
{
	t_double		*doub;
	unsigned char	*byte;
	char			*tmp;

	if (!(doub = (t_double *)malloc(sizeof(t_double))))
		exit(-1);
	byte = conv_bytes_double(f);

	doub->sign = byte[0] == '1' ? 1 : 0;
	tmp = ft_strdup((char *)&byte[1]);
	tmp[11] = '\0';
	doub->expbin = ft_strdup(tmp);
	doub->expnb = ft_atoi(ft_convert_base(doub->expbin, "01", "0123456789"));
	doub->expnb -= ft_power(2,ft_strlen(tmp) - 1) - 1;
	ft_strdel(&tmp);
	doub->mantbin = ft_strdup((char *)&byte[12]);
	if (doub->expnb >= 0)
		doub = double_convert_pos(doub);
	else
		doub = double_convert_neg(doub);
	return (doub);
}

t_double *float_byte(float f)
{
	t_double		*flt;
	unsigned char	*byte;
	char			*tmp;

	if (!(flt = (t_double *)malloc(sizeof(t_double))))
		exit(-1);
	byte = conv_bytes_float(f);
	flt->sign = byte[0] == '1' ? 1 : 0;
	tmp = ft_strdup((char *)&byte[1]);
	tmp[8] = '\0';
	flt->expbin = ft_strdup(tmp);
	flt->expnb = ft_atoi(ft_convert_base(flt->expbin, "01", "0123456789"));
	flt->expnb -= ft_power(2,ft_strlen(tmp) - 1) - 1;
	ft_strdel(&tmp);
	flt->mantbin = ft_strdup((char *)&byte[9]);
	if (flt->expnb >= 0)
		flt = double_convert_pos(flt);
	else
		flt = double_convert_neg(flt);
	return (flt);
}
