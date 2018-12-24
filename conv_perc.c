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

int     scan_perc(t_type *con, const char *str, int str_len)
{
    int i;

    i = 0;
    initialize_type(con);
    con->conversion = '%';
    con->right_ali = 1;
    con->print = 1;
    if (str_len == 1)
        return (-1);
    while (i < str_len && str[i])
    {
        if (str[i] == '0')
        {
            con->zero_pad = 16;
            i++;
        }
        else if (str[i] >= '1' && str[i] <= '9')
        {
            con->field_width = ft_atoi(str + i);
            while (str[i] >= '1' && str[i] <= '9')
                i++;
        }
        else if (str[i] == '.')
        {
            con->precision = ft_atoi(str + (++i));
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