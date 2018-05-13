/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
<<<<<<< HEAD
/*   By: dchiche <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 15:26:26 by dchiche           #+#    #+#             */
/*   Updated: 2018/05/03 19:05:47 by dchiche          ###   ########.fr       */
=======
/*   By: dchiche <dchiche@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/07 18:28:15 by dchiche           #+#    #+#             */
/*   Updated: 2018/05/13 15:43:23 by dchiche          ###   ########.fr       */
>>>>>>> 365fd0c744d1717690f2f21e6b24868c11769b0d
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
<<<<<<< HEAD
# include "libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <stdint.h>
# include <stdarg.h>
# include <wchar.h>
# include <inttypes.h>

enum				e_length
{
	hh, h, l, ll, j, z, none
};

typedef struct		s_flag
{
	char			specifier;
	char			flag[5];
	int				width;
	int				precision;
	enum e_length	length;
}					t_flag;

int					ft_printf(const char *format, ...);
int					ft_specifier(const char *str, va_list ap);
intmax_t			ft_type(t_flag new_struct, intmax_t n);
uintmax_t			ft_type_u(t_flag new_struct, uintmax_t n);
int					ft_c(t_flag new_struct, va_list ap);
int					ft_c_min(t_flag new_struct, int c);
int					ft_s(t_flag new_struct, va_list ap);
int					ft_d_or_i(t_flag new_struct, va_list ap);
int					ft_u(t_flag new_struct, va_list ap);
int					ft_x(t_flag new_struct, va_list ap);
int					ft_x_maj(t_flag new_struct, va_list ap);
int					ft_o(t_flag new_struct, va_list ap);
int					ft_p(t_flag new_struct, va_list ap);
enum e_length		ft_length(const char *str);
t_flag				ft_struct(const char *str);
char				*ft_flag(const char *str);
=======

# include "libft.h"
# include <stdarg.h>

/*
** Typedefs to restore sanity
*/

typedef long long int			t_llint;
typedef unsigned long long int	t_ullint;

typedef enum					e_length
{
	None,
	hh,
	h,
	l,
	ll,
	j,
	z
}								t_length;

typedef struct					s_token
{
	char			flags[6];
	int				width;
	int				precision;
	t_length		length;
	char			specifier;
}								t_token;

/*
** Main functions
*/

int								ft_fprintf(
									const int fd,
									const char *format,
									...);

int								ft_printf(
									const char *format,
									...);

int								ft_vprintf(
									const char *format,
									va_list ap);

int								ft_vfprintf(
									const int fd,
									const char *format,
									va_list ap);

/*
** Parsing functions
*/

t_token							parse_token(
									const char *str,
									size_t *i,
									va_list *ap);

/*
** Printing functions
*/

int								print_token(
									const int fd,
									t_token token,
									va_list *ap,
									int cpt);

int								ft_printpercent_fd(
									const int fd,
									t_token token);

int								ft_printchar_fd(
									const int fd,
									t_token token,
									va_list *ap);

int								ft_printstr_fd(
									const int fd,
									t_token token,
									va_list *ap);

int								ft_printint_fd(
									const int fd,
									t_token token,
									va_list *ap);

int								ft_printuint_fd(
									const int fd,
									t_token token,
									va_list *ap);

int								ft_printoctal_fd(
									const int fd,
									t_token token,
									va_list *ap);

int								ft_printhexa_fd(
									const int fd,
									t_token token,
									va_list *ap);

int								ft_printbin_fd(
									const int fd,
									t_token token,
									va_list *ap);

int								ft_printpointer_fd(
									const int fd,
									t_token token,
									va_list *ap);

int								ft_printunichar_fd(
									const int fd,
									t_token token,
									va_list *ap);

int								ft_printunistr_fd(
									const int fd,
									t_token token,
									va_list *ap);

void							ft_printn_fd(
									int n,
									va_list *ap);

/*
** Utilities
*/

char							*ft_printitoa(intmax_t n);
>>>>>>> 365fd0c744d1717690f2f21e6b24868c11769b0d

#endif
