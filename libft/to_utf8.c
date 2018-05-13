/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_utf8.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchiche <dchiche@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/07 18:32:48 by dchiche           #+#    #+#             */
/*   Updated: 2018/05/13 15:33:14 by dchiche          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	case_4(unsigned int unicode, char *utf8)
{
	utf8[0] = (unicode >> 16) | 0xF0;
	utf8[1] = ((unicode >> 12) & 0x3F) | 0x80;
	utf8[2] = ((unicode >> 6) & 0x3F) | 0x80;
	utf8[3] = (unicode & 0x3F) | 0x80;
	return (4);
}

static int	error(char *utf8)
{
	utf8[0] = 0xEF;
	utf8[1] = 0xBF;
	utf8[2] = 0xBD;
	return (3);
}

int			to_utf8(unsigned int unicode, char *utf8)
{
	if (unicode < 0x80)
	{
		utf8[0] = unicode;
		return (1);
	}
	if (unicode < 0x800)
	{
		utf8[0] = (unicode >> 6) | 0xC0;
		utf8[1] = (unicode & 0x3F) | 0x80;
		return (2);
	}
	if (unicode < 0x10000)
	{
		utf8[0] = (unicode >> 12) | 0xE0;
		utf8[1] = ((unicode >> 6) & 0x3F) | 0x80;
		utf8[2] = (unicode & 0x3F) | 0x80;
		return (3);
	}
	if (unicode <= 0x10FFFF)
		return (case_4(unicode, utf8));
	return (error(utf8));
}
