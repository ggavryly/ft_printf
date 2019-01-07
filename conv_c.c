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
