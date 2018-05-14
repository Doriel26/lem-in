/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_room.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchiche <dchiche@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/06 14:52:26 by dchiche           #+#    #+#             */
/*   Updated: 2018/05/14 16:46:01 by dchiche          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/lem_in.h"
#include "../../libft/ft_printf.h"

void	print_room(t_dlist *elem)
{
	t_dlist *list;

	ft_printf("%s - %u:\n", ((t_room *)elem->content)->name,
			ROOM(elem)->cost);
	list = ((t_room *)elem->content)->neighbours;
	while (list)
	{
		ft_printf("  %s\n", ((t_room *)list->content)->name);
		list = list->next;
	}
	ft_printf("\n");
}
