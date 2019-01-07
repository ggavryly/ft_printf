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

int    print_s(va_list ap, t_type con)
{
    int len;
    char *c;

    c = va_arg(ap, char*);
    len = ft_strlen(c);
    if (!c || con.precision == -1)
		return (print_null(con));
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

int		print_null(t_type con)
{
	char *k;
	int i;

	k = "(null)";
	i = 0;
	if (con.precision == -1)
		return (0);
	else
	{
		if (con.precision)
		{
			while (k[i] && con.precision--)
				ft_putchar(k[i++]);
			return (i);
		}
		else
			ft_putstr("(null)");
	}
	return (6);
}