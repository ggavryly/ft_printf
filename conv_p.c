/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_p.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggavryly <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/20 09:36:27 by ggavryly          #+#    #+#             */
/*   Updated: 2018/12/20 09:36:29 by ggavryly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int    scan_p(t_type *con, const char *str, int str_len)
{
	int i;
	
	i = 0;
	initialize_type(con);
	con->conversion = 'p';
	con->right_ali = 1;
	while (i < str_len - 1 && str[i])
	{
		if (str[i] == '0')
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

int    print_p(va_list ap, t_type con)
{
	long long c;
	long long tmp;
	int i;
	
	c = (long long)va_arg(ap, void*);
	i = 0;
	tmp = c;
	con.print = 3;
	while (tmp >= 16)
	{
		tmp = tmp / 16;
		i++;
	}
	if (con.field_width > i + 3)
	{
		con.field_width -= i + 3;
		con.print += con.field_width;
	}
	if (con.left_ali)
	{
		ft_putstr("0x");
		ft_putstr(itoa_base(c, 16, 'a'));
		while (--con.field_width >= 0)
			ft_putchar(' ');
	}
	else if (con.right_ali)
	{
		while (--con.field_width >= 0)
			ft_putchar(' ');
		ft_putstr("0x");
		ft_putstr(itoa_base(c, 16, 'a'));
	}
	con.print += i;
	return (con.print);
}
