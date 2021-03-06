/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstsort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchiche <dchiche@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/03 19:11:13 by dchiche           #+#    #+#             */
/*   Updated: 2018/05/03 19:11:24 by dchiche          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_dlist	*merge(
					t_dlist *a,
					t_dlist *b,
					int (*cmp)(t_dlist *l1, t_dlist *l2))
{
	t_dlist *head;

	if (!b)
		return (a);
	else if (!a)
		return (b);
	if (cmp(a, b) < 0)
	{
		head = a;
		head->next = merge(a->next, b, cmp);
	}
	else
	{
		head = b;
		head->next = merge(a, b->next, cmp);
	}
	head->next->prev = head;
	head->prev = NULL;
	return (head);
}

static void		split(t_dlist *head, t_dlist **a, t_dlist **b)
{
	t_dlist *fast;
	t_dlist *slow;

	if (!head || head->next == NULL)
	{
		*a = head;
		*b = NULL;
		return ;
	}
	slow = head;
	fast = head->next;
	while (fast)
	{
		fast = fast->next;
		if (fast)
		{
			fast = fast->next;
			slow = slow->next;
		}
	}
	*a = head;
	*b = slow->next;
	slow->next = NULL;
}

void			ft_dlstsort(t_dlist **head,
							int (*cmp)(t_dlist *l1, t_dlist *l2))
{
	t_dlist *a;
	t_dlist *b;

	if (!head || !*head || !(*head)->next)
		return ;
	split(*head, &a, &b);
	ft_dlstsort(&a, cmp);
	ft_dlstsort(&b, cmp);
	*head = merge(a, b, cmp);
}
