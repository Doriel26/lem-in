/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_room.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchiche <dchiche@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/06 17:41:09 by dchiche           #+#    #+#             */
/*   Updated: 2018/05/08 18:11:04 by dchiche          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/lem_in.h"

t_room	*find_room(t_dlist *head, char *name)
{
	while (head)
	{
		if (ft_strcmp(((t_room *)head->content)->name, name) == 0)
			return (head->content);
		head = head->next;
	}
	return (NULL);
}
