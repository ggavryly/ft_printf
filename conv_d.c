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

static int	sign(intmax_t k,t_type *con)
{
	if ((con->sign) || k < 0)
	{
		if (k < 0)
			ft_putchar('-');
		else
			ft_putchar('+');
	}
	else if (con->space)
		ft_putchar(' ');
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
	if (con->sign || str[0] == '-' || con->space)
		prec += 1;
	prec += print;
	con->field_width -= prec;
	if (con->field_width >= 0)
		prec += con->field_width;
	con->print = prec;
	if (con->zero_pad && !con->left_ali)
		flag = sign(k, con);
	while (con->field_width-- > 0)
		ft_putchar(' ' + ((con->precision) ? (0) : con->zero_pad));
	return (flag);
}

int 	print_d(va_list ap, t_type con)
{
	intmax_t k;
	char *str;

	k = flag_intdi(con, ap);
	str = itoa_base(k, 10, 'a');
	if (con.left_ali)
	{
		if (k == 0)
		{
			zero_case_left(&con, str);
			return (con.print);
		}
		con.zero_pad = 0;
		sign(k, &con);
		precision(str, con);
		ft_putnbr(k, 0);
		field(&con, str, k);
	}
	else if (con.right_ali)
	{
		if (k == 0)
		{
			zero_case_right(&con, str);
			return (con.print);
		}
		if (!(field(&con, str, k)))
			sign(k, &con);
		precision(str, con);
		ft_putnbr(k, 0);
	}
	free(str);
	return (con.print);
}