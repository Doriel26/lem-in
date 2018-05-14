/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstreverse.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchiche <dchiche@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/03 19:11:00 by dchiche           #+#    #+#             */
/*   Updated: 2018/05/14 16:25:59 by dchiche          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_dlstreverse(t_dlist **alst)
{
	t_dlist *prev;
	t_dlist *curr;
	t_dlist *tmp;

	if (!alst)
		return ;
	curr = *alst;
	prev = NULL;
	while (curr)
	{
		tmp = curr->next;
		curr->next = prev;
		curr->prev = tmp;
		prev = curr;
		curr = tmp;
	}
	*alst = prev;
}
