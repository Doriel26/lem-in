/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoimax.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchiche <dchiche@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/01 18:26:52 by dchiche           #+#    #+#             */
/*   Updated: 2018/05/08 18:05:22 by dchiche          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

intmax_t	ft_atoimax(const char *str)
{
	intmax_t	res;
	int			neg;

	res = 0;
	neg = 1;
	while ((*str > 8 && *str < 14) || *str == ' ')
		str++;
	neg = (*str == '-') ? -1 : 1;
	str = (neg == -1 || *str == '+') ? str + 1 : str;
	while (*str >= '0' && *str <= '9')
		res = res * 10 + (*str++ - '0');
	return (res * neg);
}
