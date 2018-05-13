/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchiche <dchiche@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/12 15:03:52 by dchiche           #+#    #+#             */
/*   Updated: 2018/05/08 18:04:19 by dchiche          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	nbrlen(unsigned int n)
{
	int cpt;

	cpt = 1;
	while (n >= 10)
	{
		n /= 10;
		cpt += 1;
	}
	return (cpt);
}

char		*ft_utoa(unsigned int n)
{
	char	*res;
	int		len;

	len = nbrlen(n);
	if (!(res = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	res[len--] = '\0';
	while (n >= 10)
	{
		res[len--] = n % 10 + '0';
		n /= 10;
	}
	res[len] = n + '0';
	return (res);
}
