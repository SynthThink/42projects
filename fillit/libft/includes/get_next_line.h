/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malluin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 17:56:07 by malluin           #+#    #+#             */
/*   Updated: 2018/11/16 13:47:03 by malluin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFF_SIZE 32

typedef struct			s_blist {
	char				buff[BUFF_SIZE];
	int					ret;
	int					fd;
	struct s_blist		*next;
}						t_blist;

int						get_next_line(const int fd, char **line);

#endif
