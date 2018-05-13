/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vfprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchiche <dchiche@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/07 18:29:01 by dchiche           #+#    #+#             */
/*   Updated: 2018/05/13 15:30:23 by dchiche          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_vfprintf(const int fd, const char *format, va_list ap)
{
	size_t	i;
	size_t	cpt;
	va_list	cpy;
	t_token	token;

	va_copy(cpy, ap);
	if (!format)
		return (-1);
	i = 0;
	cpt = 0;
	while (format[i])
	{
		if (format[i] == '%' && (i += 1))
		{
			token = parse_token(format, &i, &cpy);
			cpt += print_token(fd, token, &cpy, cpt);
		}
		else
		{
			write(fd, format + i++, 1);
			cpt += 1;
		}
	}
	va_end(cpy);
	return (cpt);
}
