/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malluin <malluin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 10:58:49 by malluin           #+#    #+#             */
/*   Updated: 2019/01/29 14:54:23 by malluin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		ft_timecmp(const char *c1, const char *c2)
{
	struct stat buf1;
	struct stat buf2;
	long		time;

	if ((stat(c1, &buf1)) != -1)
		if ((stat(c2, &buf2)) != -1)
		{
			time = buf1.st_mtimespec.tv_sec - buf2.st_mtimespec.tv_sec;
			if (time == 0)
				time = buf1.st_mtimespec.tv_nsec - buf2.st_mtimespec.tv_nsec;
			if (time > 0)
				return (-1);
			else if (time < 0)
				return (1);
			else
				return (ft_strcmp(c1, c2));
		}
	return (0);
}

int		ft_cmpjoin(char *c1, char *c2, char *path, int tsort)
{
	char	*c1t;
	char	*c2t;
	int		res;

	res = 0;
	if (tsort == 1)
	{
		if (path[0] != '\0')
			c1t = ft_strjoin(path, "/");
		else
			c1t = ft_strdup("");
		c2t = ft_strdup(c1t);
		c1t = ft_insert(&c1t, c1t + ft_strlen(c1t), c1);
		c2t = ft_insert(&c2t, c2t + ft_strlen(c2t), c2);
		res = ft_timecmp(c1t, c2t);
		free(c1t);
		free(c2t);
	}
	else
		res = ft_strcmp(c1, c2);
	return (res);
}
