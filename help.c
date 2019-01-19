/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggavryly <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/19 20:47:19 by ggavryly          #+#    #+#             */
/*   Updated: 2019/01/19 20:47:26 by ggavryly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_putnstr(const char *str, int n)
{
	int i;

	i = 0;
	if (str)
	{
		while (i < n && str[i])
		{
			ft_putchar(str[i]);
			i++;
		}
	}
}

intmax_t	flag_intdi(t_type *con)
{
	intmax_t k;

	if (con->hh)
		k = (char)va_arg(con->ap, int);
	else if (con->h)
		k = (short)va_arg(con->ap, int);
	else if (con->l)
		k = va_arg(con->ap, long);
	else if (con->ll)
		k = va_arg(con->ap, long long);
	else if (con->j)
		k = va_arg(con->ap, intmax_t);
	else if (con->z)
		k = va_arg(con->ap, ssize_t);
	else
		k = va_arg(con->ap, int);
	return (k);
}

intmax_t	flag_intoux(t_type *con)
{
	uintmax_t	k;

	if (con->hh)
		k = (unsigned char)va_arg(con->ap, unsigned int);
	else if (con->h)
		k = (unsigned short)va_arg(con->ap, unsigned int);
	else if (con->l)
		k = va_arg(con->ap, unsigned long);
	else if (con->ll)
		k = va_arg(con->ap, unsigned long long);
	else if (con->j)
		k = va_arg(con->ap, uintmax_t);
	else if (con->z)
		k = (uintmax_t)va_arg(con->ap, size_t);
	else
		k = va_arg(con->ap, unsigned int);
	return (k);
}

long double	flag_float(t_type *con)
{
	long double k;

	if (con->l32)
		k = va_arg(con->ap, long double);
	else if (con->l)
		k = (long double)va_arg(con->ap, double);
	else
		k = (long double)va_arg(con->ap, double);
	return (k);
}

char		*float_up(char *buf)
{
	int i;
	int start;

	start = 0;
	while (buf[start] != '.')
		start++;
	start++;
	i = start;
	while (buf[i])
	{
		if (buf[i] == ':')
		{
			buf[i] = '0';
			buf[i - 1] += 1;
			i = start;
			continue ;
		}
		i++;
	}
	return (buf);
}
