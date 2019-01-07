/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_perc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggavryly <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/20 13:51:53 by ggavryly          #+#    #+#             */
/*   Updated: 2018/12/20 13:51:56 by ggavryly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int    print_perc(t_type con)
{
    char c;
    
    c = '%';
    con.print = (con.field_width) ? (con.field_width) : 1;
    if (con.left_ali)
    {
        ft_putchar(c);
        while (--con.field_width > 0)
            ft_putchar(' ' + con.zero_pad);
    }
    else if (con.right_ali)
    {
        while (--con.field_width > 0)
            ft_putchar(' ' + con.zero_pad);
    ft_putchar(c);
    }
    return (con.print);
}