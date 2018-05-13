/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_room.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchiche <dchiche@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/06 14:52:26 by dchiche           #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2018/05/08 18:06:22 by dchiche          ###   ########.fr       */
=======
/*   Updated: 2018/05/13 16:05:04 by dchiche          ###   ########.fr       */
>>>>>>> 365fd0c744d1717690f2f21e6b24868c11769b0d
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/lem_in.h"
<<<<<<< HEAD
=======
#include "../../libft/ft_printf.h"
>>>>>>> 365fd0c744d1717690f2f21e6b24868c11769b0d

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
