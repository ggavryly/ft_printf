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

void	print(t_type *con, int len)
{
	int pri;
	
	pri = len;
	if (con->field_width)
	{
		if (con->precision <= len && len && con->precision != 0)
			pri = (con->precision == -1) ? (0) : con->precision;
		con->field_width -= pri;
		con->print = pri + ((con->field_width < 0) ? (0) : (con->field_width));
	}
	else if (!con->field_width)
	{
		if (con->precision < len && len)
			pri = (con->precision) ? (con->precision) : (pri);
		con->print = pri + ((con->field_width < 0) ? (0) : (con->field_width));
	}
}


intmax_t	flag_intr(t_type con, va_list ap)
{
	intmax_t k;
	
	k = 0;
	if (con.hh)
		k = (char)va_arg(ap,  int);
	else if (con.h)
		k = (short)va_arg(ap, int);
	else if (con.l)
		k = va_arg(ap, long);
	else if (con.ll)
		k = va_arg(ap, long long);
	else
		k = va_arg(ap, int);
	return (k);
}

void	zero_case_help(t_type *con)
{
	int prec;
	int field;
	int print;

	prec = con->precision;
	field = con->field_width;
	print = (!con->precision) ? 1 : 0;
	if (con->sign || con->space)
		print++;
	if (prec > 0)
		print += prec;
	if (field > print)
	{
		field -= print;
		con->print += field;
		while (field-- > 0)
			ft_putchar(' ');
	}
}