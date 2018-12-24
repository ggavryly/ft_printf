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

char    *print_int(t_type *con, long long int nbr, int base)
{
	int pri;
	int len;
	char *str;
	
	len = (int)ft_strlen((str = itoa_base(nbr, base , 'a')));
	con->precision = (con->precision > len) ? (con->precision - len) : (0);
	pri = len + ((con->precision >= 0) ? (con->precision) : (0));
	if (con->field_width)
	{
		con->field_width -= pri;
		con->print = pri + ((con->field_width < 0) ? (0) : (con->field_width));
	}
	else if (!con->field_width)
		con->print = pri + ((con->field_width < 0) ? (0) : (con->field_width));
	return (str);
}