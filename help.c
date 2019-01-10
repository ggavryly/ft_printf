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

intmax_t	flag_intdi(t_type con, va_list ap)
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

void	zero_field(t_type *con, int print, int *flag)
{
	int field;

	field = con->field_width;
	if (con->space || con->sign)
	{
		if (con->space)
			ft_putchar(' ');
		else if (con->sign)
			ft_putchar('+');
		*flag = 1;
	}
	field -= print;
	con->print += field;
	while (field-- > 0)
		ft_putchar(' ' + ((con->precision == -1) ? (0) : con->zero_pad));

}

intmax_t	flag_intoux(t_type con, va_list ap)
{
	uintmax_t	k;

	if (con.hh)
		k = (unsigned char)va_arg(ap,  int);
	else if (con.h)
		k = (unsigned short)va_arg(ap, int);
	else if (con.l)
		k = (unsigned long)va_arg(ap, long);
	else if (con.ll)
		k = (unsigned long long)va_arg(ap, long long);
	else
		k = (unsigned int)va_arg(ap, int);
	return (k);
}

void	zero_case_help(t_type *con, int *flag)
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
	if (field > print && !con->zero_pad && prec != -1)
	{
		field -= print;
		con->print += field;
		while (field-- > 0)
			ft_putchar(' ' + ((con->precision) ? (0) : con->zero_pad));
	}
	else if (field > print)
		zero_field(con, print, flag);
}