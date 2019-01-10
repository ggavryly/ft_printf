/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_o.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggavryly <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/20 09:39:43 by ggavryly          #+#    #+#             */
/*   Updated: 2018/12/20 09:39:45 by ggavryly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void hash(t_type *con, intmax_t k)
{
	if (con->alt_form && k != 0)
		ft_putstr("0");
	else if (con->precision == -1 && k == 0 && con->alt_form)
	{
		ft_putstr("0");
		con->print++;
	}
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
	if (con->alt_form && str[0] != '0')
		prec += 1;
	prec += print;
	con->field_width -= prec;
	if (con->field_width >= 0)
		prec += con->field_width;
	con->print = prec;
	while (con->field_width-- > 0)
		ft_putchar(' ' + ((con->precision) ? (0) : con->zero_pad));
}

int 	print_o(va_list ap, t_type con)
{
	uintmax_t k;
	char *str;

	k = flag_intoux(con, ap);
	str = itoa_base_u(k, 8, 'a');
	if (con.left_ali)
	{
		if (k == 0)
		{
			hash(&con, k);
			zero_case_left(&con, str);
			return (con.print);
		}
		con.zero_pad = 0;
		hash(&con, k);
		precision(str, con);
		ft_putstr(str);
		field(&con, str);
	}
	else if (con.right_ali)
	{
		if (k == 0)
		{
			hash(&con, k);
			zero_case_right(&con, str);
			return (con.print);
		}
		field(&con, str);
		hash(&con, k);
		precision(str, con);
		ft_putstr(str);
	}
	free(str);
	return (con.print);
}