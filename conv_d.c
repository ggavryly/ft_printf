/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggavryly <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/20 09:39:26 by ggavryly          #+#    #+#             */
/*   Updated: 2018/12/20 09:39:27 by ggavryly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int    scan_d(t_type *con, const char *str, int str_len)
{
	int i;
	
	i = 0;
	initialize_type(con);
	con->conversion = 'd';
	con->right_ali = 1;
	while (i < str_len - 1 && str[i])
	{
		if (str[i] == '0')
		{
			con->zero_pad = 16;
			i++;
		}
		else if (str[i] == '+')
		{
			con->sign = 1;
			i++;
		}
		else if (str[i] == ' ')
		{
			con->space = 1;
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

int    print_d(va_list ap, t_type con)
{
	long long c;
	char *str;
	int i;
	
	c = (long long)va_arg(ap, void *);
	i = 0;
	str = print_int(&con, c, 10);
	if (str[0] == '-')
		i++;
	if (con.left_ali)
	{
		while (con.precision-- > 0)
			ft_putchar('0');
		while (str[i++])
			ft_putchar(str[i]);
		while (--con.field_width >= 0)
			ft_putchar(' ');
	}
	else if (con.right_ali)
	{
		while (--con.field_width >= 0)
			ft_putchar(' ');
		while (con.precision-- > 0)
			ft_putchar('0');
		while (str[i])
			ft_putchar(str[i++]);
	}
	return (con.print);
}