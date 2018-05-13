/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printpercent_fd.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchiche <dchiche@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/07 16:05:53 by dchiche           #+#    #+#             */
/*   Updated: 2018/05/13 15:26:09 by dchiche          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_printpercent_fd(const int fd, t_token token)
{
	int cpt;

	cpt = 1;
	if (!ft_strchr(token.flags, '-'))
	{
		while (token.width-- > 1)
		{
			write(fd, " ", 1);
			cpt++;
		}
	}
	write(fd, "%", 1);
	while (token.width-- > 1)
	{
		write(fd, " ", 1);
		cpt++;
	}
	return (cpt);
}
