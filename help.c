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


t_flag *flag_intr(t_type con, va_list ap)
{
	t_flag *res;
	
	res = (t_flag *)malloc(sizeof(t_flag));
	initialize_flag(res);
	if (con.hh)
		res->hh = (char)va_arg(ap,  void *);
	else if (con.h)
		res->h = (short)va_arg(ap, void *);
	else if (con.l)
		res->l = va_arg(ap, long);
	else if (con.ll)
		res->ll = va_arg(ap, long long);
	else if (con.l32)
		res->l32 = va_arg(ap, long double);
	else
		res->i = va_arg(ap, int);
	flag_value(res);
	return (res);
}

void	flag_value(t_flag *flag)
{
	if (flag->i)
		flag->value = &flag->i;
	else if (flag->hh)
		flag->value = &flag->hh;
	else if (flag->h)
		flag->value = &flag->h;
	else if (flag->l)
		flag->value = &flag->l;
	else if (flag->ll)
		flag->value = &flag->ll;
	else if (flag->l32)
		flag->value = &flag->l32;
}