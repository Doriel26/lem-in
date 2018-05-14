/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstappend.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchiche <dchiche@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/03 19:06:59 by dchiche           #+#    #+#             */
/*   Updated: 2018/05/14 17:00:27 by dchiche          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_dlstappend(t_dlist **alst, t_dlist *new)
{
	t_dlist	*curr;

	if (!alst || !new)
		return ;
	new->next = NULL;
	if (!*alst)
	{
		new->prev = NULL;
		*alst = new;
	}
	else
	{
		curr = *alst;
		while (curr->next)
			curr = curr->next;
		curr->next = new;
		new->prev = curr;
	}
}
