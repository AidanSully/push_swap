/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.h                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: asulliva <asulliva@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/07/09 16:02:39 by asulliva       #+#    #+#                */
/*   Updated: 2019/07/09 16:03:24 by asulliva      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include "libft/libft.h"
# define BUFF_SIZE 100

typedef struct		s_lst
{
	void			*left;
	size_t			left_size;
	struct s_lst	*next;
	int				fd;
}					t_lst;

int					get_next_line(int const fd, char **line);
int					check_extra(int fd, char *buf, t_lst **head);
t_lst				*find_extra(int fd, t_lst **head);
char				*get_extra_else(t_lst *elem);
char				*get_extra(int fd, t_lst **head);

#endif
