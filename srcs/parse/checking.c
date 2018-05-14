/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checking.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchiche <dchiche@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/06 15:44:42 by dchiche           #+#    #+#             */
/*   Updated: 2018/05/14 14:55:54 by dchiche          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/lem_in.h"

int		is_comment(const char *line)
{
	return (line
			&& *line == '#'
			&& *(line + 1) != '#');
}

int		is_command(const char *line)
{
	if (line && *line == '#' && *(line + 1) == '#')
	{
		if (!ft_strcmp(line + 2, "start"))
			return (1);
		if (!ft_strcmp(line + 2, "end"))
			return (2);
		return (3);
	}
	return (0);
}

int		is_room(const char *line)
{
	if (!line)
		return (0);
	while (*line && *line != ' ' && *line != 'L')
		line++;
	if (*line != ' ')
		return (0);
	line += 1;
	while (*line && *line >= '0' && *line <= '9')
		line++;
	if (*line != ' ')
		return (0);
	line += 1;
	while (*line && *line >= '0' && *line <= '9')
		line++;
	return (!*line);
}

int		is_valid_connexion(t_dlist *list, char *line)
{
	char	*tmp[2];

	if (!list)
		return (0);
	tmp[0] = line;
	while (*line)
	{
		while (*line && *line != '-')
			line++;
		if (*line == '-')
		{
			*line = '\0';
			if (find_room(list, tmp[0]) && find_room(list, line + 1))
				return (1);
			*line++ = '-';
		}
	}
	tmp[1] = line;
	return (0);
}
