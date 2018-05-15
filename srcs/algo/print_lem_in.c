/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_lem_in.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchiche <dchiche@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/15 16:37:22 by dchiche           #+#    #+#             */
/*   Updated: 2018/05/15 21:40:37 by dchiche          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/lem_in.h"

void			print_lem_in(int nbant, t_dlist *result)
{
	t_dlist		*tmp;
	int			index;

	index = 1;
	while (index <= nbant)
	{
		tmp = result;
		while (tmp)
		{
			ft_printf("L%d-%s\n", index, ((t_room *)tmp->content)->name);
			tmp = tmp->next;
		}
		index++;
	}
}
