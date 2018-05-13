/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printitoa.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchiche <dchiche@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/07 15:28:20 by dchiche           #+#    #+#             */
/*   Updated: 2018/05/13 15:24:40 by dchiche          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_nbrlen(intmax_t n)
{
	int cpt;

	cpt = 1;
	while (n <= -10 || n >= 10)
	{
		n /= 10;
		cpt++;
	}
	return (cpt);
}

char		*ft_printitoa(intmax_t n)
{
	int		nlen;
	char	*res;

	if (n == INTMAX_MIN)
		return (ft_strdup("9223372036854775808"));
	nlen = ft_nbrlen(n);
	if (!(res = (char *)malloc(sizeof(char) * (nlen + 1))))
		return (NULL);
	res[nlen--] = '\0';
	n = (n < 0) ? -n : n;
	while (n >= 10)
	{
		res[nlen--] = n % 10 + '0';
		n /= 10;
	}
	res[nlen--] = n + '0';
	return (res);
}
