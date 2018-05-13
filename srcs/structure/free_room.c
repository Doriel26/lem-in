/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_room.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchiche <dchiche@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/06 17:41:38 by dchiche           #+#    #+#             */
/*   Updated: 2018/05/08 18:11:11 by dchiche          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/lem_in.h"

void	free_room(void *room, size_t size)
{
	if (!room)
		return ;
	(void)size;
	free(((t_room *)room)->name);
	ft_dlstdel(&((t_room *)room)->neighbours, NULL);
	free(room);
}
