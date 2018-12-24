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

int    scan_s(t_type *con, const char *str, int str_len)
{
    int i;

    i = 0;
    initialize_type(con);
    con->conversion = 's';
    con->right_ali = 1;
    while (i < str_len - 1 && str[i])
    {
        if (str[i] == '#' || str[i] == '+')
            i++;
        else if (str[i] == '0')
        {
            con->zero_pad = 16;
            i++;
        }
        else if (str[i] >= '1' && str[i] <= '9')
        {
            con->field_width = ft_atoi(str + i);
            while (str[i] >= '0' && str[i] <= '9')
                i++;
        }
        else if (str[i] == '.')
        {
        	con->precision = ft_atoi(str + (++i));
        	if (!con->precision)
        		con->precision = -1;
	        while (str[i] >= '0' && str[i] <= '9')
		        i++;
        }
        else if (str[i] == '-')
        {
            con->left_ali = 1;
            con->right_ali = 0;
            i++;
        }
        else
            i++;
    }
    return (con->conversion);
}

int    print_s(va_list ap, t_type con)
{
    int i;
    int len;
    char *c;

    i = 0;
    c = va_arg(ap, char*);
    len = ft_strlen(c);
    if (!c)
	{
		print_null();
		return (6);
	}
    print(&con, len);
    if (con.left_ali && (*c || con.field_width))
    {
        if (!con.precision)
            ft_putstr(c);
        else if (con.precision)
            ft_putnstr(c, con.precision);
        while (--con.field_width >= 0)
            ft_putchar(' ' + con.zero_pad);
    }
    else if (con.right_ali && (*c || con.field_width))
    {
        while (--con.field_width >= 0)
            ft_putchar(' ' + con.zero_pad);
        if (!con.precision)
            ft_putstr(c);
        else if (con.precision)
            ft_putnstr(c, con.precision);
    }
    return (con.print);
}

void	print_null(void)
{
	ft_putstr("(null)");
}