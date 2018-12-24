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

int    scan_c(t_type *con, const char *str, int str_len)
{
    int i;

    i = 0;
    initialize_type(con);
    con->conversion = 'c';
    con->field_width = 1;
    con->right_ali = 1;
    while (i < str_len && str[i])
    {
        if (str[i] == '0')
        {
            con->zero_pad = 16;
            i++;
        }
        else if (str[i] >= '1' && str[i] <= '9')
        {
            if (str[i - 1] != '.')
                con->field_width = ft_atoi(str + i);
            while (str[i] >= '1' && str[i] <= '9')
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
