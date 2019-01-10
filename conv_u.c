/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_u.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggavryly <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 13:08:59 by ggavryly          #+#    #+#             */
/*   Updated: 2019/01/10 13:09:01 by ggavryly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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

static void	field(t_type *con, char *str)
{
	int slen;
	int prec;
	int print;

	slen = ft_strlen(str);
	prec = 0;
	print = (str[0] == '-') ? slen - 1 : slen;
	if (print < con->precision)
		prec = con->precision - print;
	prec += print;
	con->field_width -= prec;
	if (con->field_width >= 0)
		prec += con->field_width;
	con->print = prec;
	while (con->field_width-- > 0)
		ft_putchar(' ' + ((con->precision) ? (0) : con->zero_pad));
}

int 	print_u(va_list ap, t_type con)
{
	uintmax_t k;
	char *str;

	k = flag_intoux(con, ap);
	str = itoa_base_u(k, 10, 'a');
	if (con.left_ali)
	{
		if (k == 0)
		{
			zero_case_left(&con, str);
			return (con.print);
		}
		con.zero_pad = 0;
		precision(str, con);
		ft_putstr(str);
		field(&con, str);
	}
	else if (con.right_ali)
	{
		if (k == 0)
		{
			zero_case_right(&con, str);
			return (con.print);
		}
		field(&con, str);
		precision(str, con);
		ft_putstr(str);
	}
	free(str);
	return (con.print);
}