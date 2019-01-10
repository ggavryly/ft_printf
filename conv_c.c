/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_c.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggavryly <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/20 09:36:13 by ggavryly          #+#    #+#             */
/*   Updated: 2018/12/20 09:36:15 by ggavryly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	print(t_type *con, int len)
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

int    print_c(va_list ap, t_type con)
{
    char c;
    
    c = va_arg(ap, int);
    print(&con, 1);
    if (con.left_ali)
    {
        ft_putchar(c);
        while (con.field_width--)
            ft_putchar(' ' + con.zero_pad);
    }
    else if (con.right_ali)
    {
        while (con.field_width--)
            ft_putchar(' ' + con.zero_pad);
        ft_putchar(c);
    }
    return (con.print);
}
