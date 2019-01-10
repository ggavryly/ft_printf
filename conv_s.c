/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_s.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggavryly <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/20 09:36:21 by ggavryly          #+#    #+#             */
/*   Updated: 2018/12/20 09:36:23 by ggavryly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	print_null(t_type *con)
{
	char *k;
	int i;

	k = "(null)";
	i = 0;
	if (con->precision != -1)
	{
		if (con->precision)
		{
			while (k[i] && con->precision--)
			{
				con->print++;
				ft_putchar(k[i++]);
			}
		}
		else
		{
			ft_putstr("(null)");
			con->print += 6;
		}
	}
}

static void	right_field(char *str, t_type *con)
{
	int field;
	int strlen;
	int print;

	strlen = ft_strlen(str);
	print = 0;
	field = con->field_width;
	if (con->precision > 0)
	{
		if (strlen < con->precision)
			print = strlen;
		else if (con->precision < strlen)
			print = con->precision;
	}
	else if (con->precision == -1)
		strlen = 0;
	else
		print = strlen;
	if (field > print)
	{
		field -= print;
		con->print += field;
		while (field-- > 0)
			ft_putchar(' ');
	}
}
static void	left_field(t_type *con)
{
	int field;
	int print;

	field = con->field_width;
	print = con->print;
	if (field > print)
	{
		field -= print;
		con->print += field;
		while (field-- > 0)
			ft_putchar(' ');
	}
}

static void	precision(char *str, t_type *con)
{
	int strlen;
	int i;

	strlen = ft_strlen(str);
	i = 0;
	if (con->precision > 0)
	{
		if (strlen < con->precision)
		{
			ft_putstr(str);
			con->print += strlen;
		}
		else if (con->precision < strlen)
		{
			while (con->precision-- > 0)
			{
				con->print++;
				ft_putchar(str[i++]);
			}
		}
	}
	else if (con->precision == 0)
	{
		con->print += strlen;
		ft_putstr(str);
	}
}

int    print_s(va_list ap, t_type con)
{
    char *c;

    c = va_arg(ap, char*);
    if (con.left_ali)
    {
    	if (!c)
		{
    		print_null(&con);
			return (con.print);
		}
		precision(c, &con);
		left_field(&con);
    }
    else if (con.right_ali)
    {
		if (!c)
		{
			print_null(&con);
			return (con.print);
		}
		right_field(c, &con);
		precision(c, &con);
    }
    return (con.print);
}
