/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_x.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggavryly <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/20 09:39:51 by ggavryly          #+#    #+#             */
/*   Updated: 2018/12/20 09:40:06 by ggavryly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int hash(t_type *con, intmax_t k)
{
	if (con->alt_form && k != 0)
	{
		if (con->conversion == 'x')
			ft_putstr("0x");
		else if (con->conversion == 'X')
			ft_putstr("0X");
	}
	return (1);
}

static int	precision(char *str, t_type con)
{
	int slen;
	int print;

	slen = ft_strlen(str);
	print = (str[0] == '-') ? slen - 1 : slen;
	if (print < con.precision)
	{
		con.precision -= print;
		while (con.precision--)
			ft_putchar('0');
	}
	return (1);
}

static int	field(t_type *con, char *str, intmax_t k)
{
	int slen;
	int prec;
	int print;
	int flag;

	slen = ft_strlen(str);
	prec = 0;
	flag = 0;
	print = (str[0] == '-') ? slen - 1 : slen;
	if (print < con->precision)
		prec = con->precision - print;
	if (con->alt_form && str[0] != '0')
		prec += 2;
	if (con->alt_form && con->zero_pad)
		flag = hash(con, k);
	prec += print;
	con->field_width -= prec;
	if (con->field_width >= 0)
		prec += con->field_width;
	con->print = prec;
	while (con->field_width-- > 0)
		ft_putchar(' ' + ((con->precision) ? (0) : con->zero_pad));
	return (flag);
}

int 	print_x(va_list ap, t_type con)
{
	uintmax_t k;
	char *str;

	k = flag_intoux(con, ap);
	str = itoa_base_u(k, 16, (char)((con.conversion == 'x') ? 'a' : 'A'));
	if (con.left_ali)
	{
		if (k == 0)
		{
			zero_case_left(&con, str);
			return (con.print);
		}
		con.zero_pad = 0;
		hash(&con, k);
		precision(str, con);
		ft_putstr(str);
		field(&con, str, k);
	}
	else if (con.right_ali)
	{
		if (k == 0)
		{
			zero_case_right(&con, str);
			return (con.print);
		}
		if (!field(&con, str, k))
			hash(&con, k);
		precision(str, con);
		ft_putstr(str);
	}
	free(str);
	return (con.print);
}