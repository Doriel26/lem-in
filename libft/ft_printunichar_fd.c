/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printunichar_fd.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchiche <dchiche@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/07 16:26:16 by dchiche           #+#    #+#             */
/*   Updated: 2018/05/13 15:28:38 by dchiche          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_printunichar_fd(const int fd, t_token token, va_list *ap)
{
	char			utf8[4];
	int				len;
	unsigned int	c;
	int				cpt;

	c = (unsigned int)va_arg(*ap, wint_t);
	len = to_utf8(c, utf8);
	cpt = (token.width > len) ? token.width : len;
	if (!ft_strchr(token.flags, '-'))
	{
		while (token.width-- > len)
			write(fd, " ", 1);
	}
	write(fd, utf8, len);
	while (token.width-- > len)
		write(fd, " ", 1);
	return (cpt);
}
