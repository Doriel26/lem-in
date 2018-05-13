/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_connexions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchiche <dchiche@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/06 15:36:46 by dchiche           #+#    #+#             */
/*   Updated: 2018/05/08 17:47:54 by dchiche          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/lem_in.h"

static void	parse_connexion(t_dlist *list, char *line)
{
	t_room	*tmp1;
	t_room	*tmp2;
	char	*first;

	first = line;
	while (*line)
		line++;
	line += 1;
	tmp1 = find_room(list, first);
	tmp2 = find_room(list, line);
	ft_dlstprepend(&tmp1->neighbours, ft_dlstlink(tmp2, sizeof(t_room)));
	ft_dlstprepend(&tmp2->neighbours, ft_dlstlink(tmp1, sizeof(t_room)));
	free(first);
}

static int	first(t_dlist *list, char *line)
{
	static int norm = 0;

	if (norm)
		return (norm);
	else if (logger(line, 0) && is_valid_connexion(list, line))
	{
		parse_connexion(list, line);
		norm = 1;
	}
	return (norm);
}

void		parse_connexions(t_dlist *list, char *line)
{
	int ret;

	while (first(list, line) && get_next_line(0, &line) == 1 && logger(line, 0)
		&& ((ret = is_valid_connexion(list, line))
			|| is_comment(line)
			|| is_command(line) == 3))
	{
		if (ret)
			parse_connexion(list, line);
		else
			free(line);
	}
	free(line);
}
