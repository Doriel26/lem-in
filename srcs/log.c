/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   log.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchiche <dchiche@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/06 17:39:02 by dchiche           #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2018/05/11 14:21:26 by dchiche          ###   ########.fr       */
=======
/*   Updated: 2018/05/13 16:06:09 by dchiche          ###   ########.fr       */
>>>>>>> 365fd0c744d1717690f2f21e6b24868c11769b0d
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"
<<<<<<< HEAD
=======
#include "../libft/ft_printf.h"
>>>>>>> 365fd0c744d1717690f2f21e6b24868c11769b0d

void	log_print(t_dlist *elem)
{
	write(1, "SUP\n", 4);
	ft_printf("%s\n", (char *)elem->content);
}

void	free_str(void *str, size_t size)
{
	(void)size;
	free(str);
}

int		logger(char *line, int mode)
{
	static t_dlist *logger = NULL;

	if (mode && logger)
	{
		ft_dlstreverse(&logger);
		ft_dlstiter(logger, log_print);
	}
	else if (line)
		ft_dlstprepend(&logger,
				ft_dlstlink(ft_strdup(line), ft_strlen(line) + 1));
	if (!line)
		ft_dlstdel(&logger, free_str);
	return (1);
}
