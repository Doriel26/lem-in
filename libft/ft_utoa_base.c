/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchiche <dchiche@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/11 20:04:25 by dchiche           #+#    #+#             */
/*   Updated: 2018/05/08 18:05:00 by dchiche          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_nbrlen(uintmax_t n, size_t blen)
{
	int cpt;

	cpt = 1;
	while (n >= blen)
	{
		cpt++;
		n /= blen;
	}
	return (cpt);
}

char			*ft_utoa_base(uintmax_t n, const char *base)
{
	char	*res;
	size_t	blen;
	int		nbrlen;

	blen = ft_strlen(base);
	nbrlen = ft_nbrlen(n, blen);
	if (!(res = (char *)malloc(sizeof(char) * (nbrlen + 1))))
		return (NULL);
	res[nbrlen--] = '\0';
	while (n >= blen)
	{
		res[nbrlen--] = base[n % blen];
		n /= blen;
	}
	res[nbrlen] = base[n];
	return (res);
}
