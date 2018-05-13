/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printchar_fd.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchiche <dchiche@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/18 16:17:42 by dchiche           #+#    #+#             */
/*   Updated: 2018/05/13 15:22:12 by dchiche          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_printchar_fd(const int fd, t_token token, va_list *ap)
{
	int		width;
	char	c;
	int		cpt;

	width = token.width;
	c = va_arg(*ap, int);
	cpt = 1;
	if (!ft_strchr(token.flags, '-'))
	{
		while (width > 1)
		{
			write(fd, " ", 1);
			width--;
			cpt++;
		}
	}
	write(fd, &c, 1);
	while (width > 1)
	{
		write(fd, " ", 1);
		width--;
		cpt++;
	}
	return (cpt);
}
