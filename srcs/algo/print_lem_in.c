/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_lem_in.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchiche <dchiche@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/14 17:16:12 by dchiche           #+#    #+#             */
/*   Updated: 2018/05/14 18:21:42 by dchiche          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/lem_in.h"

/*
 * ** Deflate current input to
 * ** stdout. This is a core
 * ** requierement for the project
 * ** @return nil
 * */

void			deflate(t_dlist *list)
{
	while (list != NULL && list->content != NULL)
	{
		ft_printf("%s\n", list->content);
		list = list->next;
	}
}

/*
 * ** Print a pretty formated solution
 * ** to stdout. Should be removed for
 * ** the next step.
 * ** @return nil
 * */

void			print_solution(t_dlist *solution)
{
	ft_printf("|==========| [ Best Path ] |=========|\n\n");
	while (solution != NULL)
	{
		ft_printf("%s (%d)", ROOM(solution)->name,
				ROOM(solution)->flavor);
		if (solution->next != NULL)
			ft_printf(" -> ");
		else
			ft_printf("\n");
		solution = solution->next;
	}
	ft_printf("\n|==========| +++++++++++++ |=========|\n\n");
}

/*
 * ** Flatten list of rooms (solution)
 * ** to an const, immutable array of
 * ** string for pretty printing purpose
 * ** only.
 * ** @return nil
 * */

static void		flatten_paths(t_dlist *solr,
		char **paths)
{
	size_t	i;
	t_dlist	*dex;
	t_dlist	*cpy;

	i = 0;
	dex = NULL;
	cpy = solr;
	while (cpy != NULL)
	{
		if (ROOM(cpy)->flavor == START)
			dex = cpy;
		cpy = cpy->next;
	}
	if (dex == NULL)
		dex = solr;
	while (dex != NULL)
	{
		paths[i] = ft_strdup(ROOM(dex)->name);
		dex = dex->next;
		i++;
	}
}

/*
 * ** Print the line by using
 * ** pre-computed values to
 * ** avoid confusions in callbacks.
 * ** @return nil
 * */

static uint8_t	printline(int i, int j, int k,
		t_artefakts art)
{
	if ((j > k || i >=	art.ants + 1))
	{
		if (j > k && i >= art.ants)
			return (1);
		return (0);
	}
	ft_printf("L%d-%s ", i, art.paths[j]);
	return (2);
}

/*
 * ** Print the road traject by respecting
 * ** the traject.
 * ** One ant cannot be on the same time
 * ** as one other one.
 * ** @fmt Lx-y Lz-w Lr-o
 * ** @where x, z, r -> ants number
 * ** @where y, w, o -> rooms number
 * ** @return nil
 * */

void			ant_road(t_dlist *solution,
						const uint32_t solution_size,
						uint32_t ants,
						int index)
{
	char		*paths[solution_size + 1];
	int			cursor;
	t_artefakts	art;

	cursor = 1;
	flatten_paths(solution, paths);
	art.paths = paths;
	art.ants = (int)ants;
	while (TRUE)
	{
		cursor = 1;
		while (cursor < index)
		{
			if (printline(cursor, index - cursor,
						(int)solution_size, art) == 1)
				return (flattenized_cleanup(paths, 0, solution_size));
			cursor++;
		}
		ft_putchar('\n');
		index++;
	}
}
