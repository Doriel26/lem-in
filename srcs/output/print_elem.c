/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_elem.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchiche <dchiche@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/06 14:50:50 by dchiche           #+#    #+#             */
/*   Updated: 2018/05/08 17:51:20 by dchiche          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/lem_in.h"

void	print_elem(t_dlist *elem)
{
	if (!elem || !elem->content)
		return ;
	if (elem->next)
		ft_printf("%s - ", ROOM(elem)->name);
	else
		ft_printf("%s\n", ROOM(elem)->name);
}
