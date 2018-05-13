/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchiche <dchiche@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/07 17:18:28 by dchiche           #+#    #+#             */
/*   Updated: 2018/05/13 15:30:51 by dchiche          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_vprintf(const char *format, va_list ap)
{
	int		res;
	va_list	cpy;

	va_copy(cpy, ap);
	res = ft_vfprintf(1, format, cpy);
	va_end(cpy);
	return (res);
}
