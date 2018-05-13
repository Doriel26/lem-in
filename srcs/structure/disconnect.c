/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disconnect.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchiche <dchiche@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/06 17:40:11 by dchiche           #+#    #+#             */
/*   Updated: 2018/05/08 17:40:45 by dchiche          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/lem_in.h"

void	rm(t_dlist *tmp, t_room *room)
{
	t_dlist	*prev;
	t_dlist	*tmp2;

	prev = NULL;
	tmp2 = ROOM(tmp)->neighbours;
	while (tmp2)
	{
		if (ROOM(tmp2) == room)
		{
			if (prev)
				prev->next = tmp2->next;
			else
				ROOM(tmp)->neighbours = tmp2->next;
			ft_dlstprepend(&ROOM(tmp)->removed, tmp2);
			break ;
		}
		prev = tmp2;
		tmp2 = tmp2->next;
	}
}

void	disconnect(t_room *room)
{
	t_dlist	*tmp;

	if (!room)
		return ;
	tmp = room->neighbours;
	while (tmp)
	{
		rm(tmp, room);
		tmp = tmp->next;
	}
}
