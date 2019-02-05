/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_refs.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnussbau <fnussbau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 12:07:08 by fnussbau          #+#    #+#             */
/*   Updated: 2018/12/11 13:33:19 by malluin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "libftprintf.h"

t_ref	*set_refs(void)
{
	t_ref *ref;

	if (!(ref = (t_ref *)malloc(sizeof(t_ref) * (1))))
		return (NULL);
	if (!(ref->options = (char *)malloc(sizeof(char) * (5 + 1))))
		return (NULL);
	if (!(ref->size = (char *)malloc(sizeof(char) * (3 + 1))))
	{
		free(ref->options);
		return (NULL);
	}
	if (!(ref->conv = (char *)malloc(sizeof(char) * (10 + 1))))
	{
		free(ref->options);
		free(ref->size);
		return (NULL);
	}
	ref->options = ft_strcpy(ref->options, "+-#0 ");
	ref->size = ft_strcpy(ref->size, "hlL");
	ref->conv = ft_strcpy(ref->conv, "cspdiouxXf");
	return (ref);
}
