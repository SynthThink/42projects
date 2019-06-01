/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malluin <malluin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/11 16:30:23 by malluin           #+#    #+#             */
/*   Updated: 2019/01/29 18:17:38 by malluin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include <dirent.h>
# include <sys/stat.h>
# include "libftprintf.h"
# include <time.h>
# include <pwd.h>
# include <grp.h>
# include "errno.h"
# include <stdio.h>

typedef struct		s_file {

	char			*name;
	char			*path;
	char			*user;
	char			*group;
	struct s_file	*next;
}					t_file;

typedef struct		s_sys {

	t_file			*dirs;
	t_file			*files;
	char			*options;
	int				nb_tar;
	int				title;
	short			l;
	long			size_pad;
	long			minor_pad;
	long			major_pad;
	long			links_pad;
	long			login_pad;
	long			group_pad;
	char			total;
	short			blank;
	time_t			t;
}					t_sys;

void				lst_new_front(char *content, t_file **lst);
void				lst_new_back(char *content, t_file **lst);
void				lst_insert_sort(char *content,
					t_file **lst, int tsort, char *path);
void				lst_insert_rsort(char *content,
					t_file **lst, int tsort, char *path);
int					ft_timecmp(const char *c1, const char *c2);
int					ft_cmpjoin(char *c1, char *c2, char *path, int tsort);

t_file				*lst_new_node(char *content);
void				parse(int ac, char **av, t_sys	*sys);
void				check_options(t_sys *sys);
t_sys				*initialize_sys(void);

void				treat_dir(t_sys *sys, struct dirent *tmp,
					t_file **dir, char *av);
t_file				*read_dir(t_sys *sys, char *av);
void				lst_insert_dirs(t_file **new_dirs, t_file **tmp);

void				free_node(t_file *file);
void				free_sys(t_sys *sys);
void				free_files(t_file **file, int opt);

void				ft_error(char *str);
void				usage(char c);

int					is_ddir(char *str);
int					is_dir(char *str);
int					is_reg(char *str);
int					is_slnk(char *str);
int					is_hidden(t_sys *sys, char *str);
int					is_pres(char *str);

void				print_files(t_sys *sys, t_file *tmp);
void				print_list(t_file *lst);
void				col_print(t_sys *sys, t_file *dir);
void				set_path_all(t_file *file, char *path);
void				set_path(t_file *file, char *path);

void				print_type(mode_t st_mode);
void				print_size(t_sys *sys, struct stat buf);
void				print_links(t_sys *sys, nlink_t st_nlink);
void				print_time(t_sys *sys, time_t st_time);
void				print_user(t_sys *sys, t_file *file);
void				print_symb(t_file *file);
#endif
