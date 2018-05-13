/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchiche <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 17:21:38 by dchiche           #+#    #+#             */
/*   Updated: 2018/05/09 18:35:48 by dchiche          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include "libft.h"
# include <stdlib.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <fcntl.h>
# include <unistd.h>

# define BUFF_SIZE 32

typedef struct		s_clist
{
	int				fd;
	int				offset;
	char			buff[BUFF_SIZE + 1];
	struct s_clist	*next;
}					t_clist;

int					get_next_line(const int fd, char **line);

#endif
