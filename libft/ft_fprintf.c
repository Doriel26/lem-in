/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchiche <dchiche@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/07 17:15:30 by dchiche           #+#    #+#             */
/*   Updated: 2018/05/13 15:23:01 by dchiche          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_fprintf(const int fd, const char *format, ...)
{
	int		res;
	va_list	ap;

	va_start(ap, format);
	res = ft_vfprintf(fd, format, ap);
	va_end(ap);
	return (res);
}
