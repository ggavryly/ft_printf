/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help->c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggavryly <marvin@42->fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/20 10:35:50 by ggavryly          #+#    #+#             */
/*   Updated: 2018/12/20 10:36:09 by ggavryly         ###   ########->fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void    ft_putnstr(const char *str, int n)
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
		k = (char)va_arg(con->ap,  int);
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
