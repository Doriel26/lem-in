/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchiche <dchiche@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/06 17:39:21 by dchiche           #+#    #+#             */
/*   Updated: 2018/05/09 18:39:55 by dchiche          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

static int	get_nbant(unsigned int *nbant)
{
	char	*tmp;
	int		ret;

	tmp = NULL;
	while ((ret = get_next_line(0, &tmp)) == 1 && is_comment(tmp))
	{
		logger(tmp, 0);
		free(tmp);
	}
	if (ret <= 0
		|| !tmp
		|| ft_strlen(tmp) > 10
		|| (ft_strlen(tmp) == 10 && ft_strcmp(tmp, "2147483647") > 0)
		|| !ft_str_is_numeric(tmp)
		|| !(*nbant = ft_atou(tmp))
		|| *nbant > INT_MAX)
	{
		free(tmp);
		logger(NULL, 0);
		write(2, "ERROR\n", 6);
		return (0);
	}
	logger(tmp, 0);
	free(tmp);
	return (1);
}

void		free_path(void *elem, size_t size)
{
	t_dlist	*next;
	t_dlist	*list;

	if (!elem)
		return ;
	list = (t_dlist *)elem;
	(void)size;
	while (list)
	{
		next = list->next;
		free(list);
		list = next;
	}
	elem = NULL;
}

int			main(void)
{
	t_dlist			*result;
	t_dlist			*list;
	t_room			*start;
	t_room			*end;
	unsigned int	nbant;

	if (!get_nbant(&nbant))
		return (1);
	start = NULL;
	end = NULL;
	list = parse(&start, &end);
	if (!list || !start || !end || !is_connected(start, end))
	{
		ft_dlstdel(&list, free_room);
		logger(NULL, 0);
		write(2, "ERROR\n", 6);
		return (1);
	}
	logger(NULL, 1);
	write(1, "OK\n", 3);
	/*result = solve(list, start, end);
	print_lem_in(result);*/
	ft_dlstdel(&result, free_room);
	ft_dlstdel(&list, free_room);
}
