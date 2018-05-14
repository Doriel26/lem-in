/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   log.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchiche <dchiche@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/06 17:39:02 by dchiche           #+#    #+#             */
/*   Updated: 2018/05/14 16:26:10 by dchiche          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"
#include "../libft/ft_printf.h"

void	log_print(t_dlist *elem)
{
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
