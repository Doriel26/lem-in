/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dijkstra.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchiche <dchiche@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/06 14:18:19 by dchiche           #+#    #+#             */
/*   Updated: 2018/05/08 18:07:49 by dchiche          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/lem_in.h"

static void	set_cost(t_dlist *elem)
{
	ROOM(elem)->cost = UINT_MAX;
}

static void	recursion(t_room *curr)
{
	t_dlist *walk;

	walk = curr->neighbours;
	while (walk)
	{
		if (curr->cost + 1 < ROOM(walk)->cost)
		{
			ROOM(walk)->cost = curr->cost + 1;
			recursion(ROOM(walk));
		}
		walk = walk->next;
	}
}

void		dijkstra(t_dlist *nodes, t_room *start)
{
	if (!start)
		return ;
	ft_dlstiter(nodes, set_cost);
	start->cost = 0;
	recursion(start);
}
