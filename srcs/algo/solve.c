/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchiche <dchiche@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/14 16:27:14 by dchiche           #+#    #+#             */
/*   Updated: 2018/05/15 21:31:34 by dchiche          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/lem_in.h"

t_dlist		*solve(t_dlist *list, t_room *start, t_room *end)
{
	t_dlist		*res;
	t_dlist		*tmp;

	res = NULL;
	dijkstra(list, start);
	while (end != start)
	{
		ft_dlstprepend(&res, ft_dlstlink(end, sizeof(t_room)));
		tmp = end->neighbours;
		while (tmp)
		{
			if (ROOM(tmp)->cost == end->cost - 1)
			{
				end = ROOM(tmp);
				break ;
			}
			tmp = tmp->next;
		}
	}
	return (res);
}
