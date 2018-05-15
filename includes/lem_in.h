/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchiche <dchiche@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/06 17:35:11 by dchiche           #+#    #+#             */
/*   Updated: 2018/05/15 21:37:17 by dchiche          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include "../libft/libft.h"
# define ROOM(x) ((t_room *)x->content)
# define LIST(x) ((t_dlist *)x->content)

typedef struct					s_room
{
	unsigned int				cost;
	char						*name;
	unsigned int				x;
	unsigned int				y;
	t_dlist						*neighbours;
}								t_room;

/*
** Graph related functions
*/

void							free_room(void *room, size_t room_size);
int								room_cmp(const void *s1, const void *s2);
void							free_path(void *elem, size_t	size);
void							free_best(t_dlist *src);

/*
** Parsing related functions
*/

int								logger(char *line, int mode);
int								is_comment(const char *line);
int								is_command(const char *line);
int								is_room(const char *line);
int								is_valid_connexion(t_dlist *list, char *line);

void							parse_connexions(t_dlist *list, char *line);
t_dlist							*parse(t_room **start, t_room **end);

t_room							*find_room(t_dlist *list, char *room);
int								is_connected(t_room *start, t_room *end);

/*
** Solving related functions
*/

/*
** Output functions
*/

void							print_path(t_dlist *elem);
void							print_room(t_dlist *room);
void							print_elem(t_dlist *elem);

/*
** Algo
*/

void							dijkstra(t_dlist *nodes, t_room *start);
t_dlist							*solve(
										t_dlist *lst,
										t_room *start,
										t_room *end);
void							print_lem_in(int nbant, t_dlist *result);

#endif
