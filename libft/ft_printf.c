/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
<<<<<<< HEAD
/*   By: dchiche <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 14:56:39 by dchiche           #+#    #+#             */
/*   Updated: 2018/01/16 15:57:04 by dchiche          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		ft_res(int res, const char **format, va_list ap)
{
	(*format)++;
	res += ft_specifier(*format, ap);
	while (**format && !ft_strchr("sSpdDioOuUxXcC%", **format)
			&& ft_strchr(" -+#0123456789.hljz%", **format))
	{
		(*format)++;
		if (!ft_strchr(" -+#0123456789.hljzsSpdDioOuUxXcC%", **format))
		{
			(*format)--;
			break ;
		}
	}
	if (**format && ft_strchr(" -+#0123456789.hljzsSpdDioOuUxXcC%", **format))
		(*format)++;
	return (res);
}

int				ft_printf(const char *format, ...)
{
	int		res;
	va_list	ap;
	int		i;

	i = 0;
	res = 0;
	va_start(ap, format);
	while (*format)
	{
		if (*format != '%')
		{
			write(1, format++, 1);
			res++;
		}
		else
			res = ft_res(res, &format, ap);
	}
=======
/*   By: dchiche <dchiche@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/07 18:26:20 by dchiche           #+#    #+#             */
/*   Updated: 2018/05/13 15:17:20 by dchiche          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_printf(const char *format, ...)
{
	int		res;
	va_list	ap;

	va_start(ap, format);
	res = ft_vfprintf(1, format, ap);
>>>>>>> 365fd0c744d1717690f2f21e6b24868c11769b0d
	va_end(ap);
	return (res);
}
