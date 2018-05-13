/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reconnect.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchiche <dchiche@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/06 17:42:23 by dchiche           #+#    #+#             */
/*   Updated: 2018/05/08 18:11:35 by dchiche          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/lem_in.h"

void	reconnect(t_dlist *elem)
{
	t_dlist	*tmp;

	if (!elem)
		return ;
	tmp = ROOM(elem)->removed;
	if (!tmp)
		return ;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = ROOM(elem)->neighbours;
	ROOM(elem)->neighbours = ROOM(elem)->removed;
	ROOM(elem)->removed = NULL;
}
