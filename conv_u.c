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

static void	zero_pad(int field, t_type *con)
{
	if (field >= 0 && !con->precision)
	{
		con->print += field;
		while (field-- > 0)
			write(1, "0", 1);
	}
	else if (field >= 0)
	{
		con->print += field;
		while (field-- > 0)
			write(1, " ", 1);
	}
}

static int	precision(uintmax_t k, t_type *con, int strlen)
{
	int print;
	int prec;

	print = strlen;
	prec = con->precision;
	if (print <= prec)
	{
		prec -= print;
		con->print += prec + strlen;
		while (prec-- > 0)
			write(1, "0", 1);
	}
	else if  (prec == -1 && k == 0)
		return (-1);
	else if (prec == 0 || prec < print)
		con->print += print;
	return (1);
}

static void	field(t_type *con, int strlen, char *str)
{
	int prec;
	int field;
	int print;

	prec = con->precision;
	print = (str[0] == '0' && prec == -1) ? 0 : strlen;
	field = con->field_width;
	if (prec > strlen)
		print += prec - strlen;
	else if (prec < strlen && prec > 0)
		print = strlen;
	else
		print += (prec == -1) ? 0 : prec;
	field -= print;
	if (con->zero_pad && !con->left_ali)
		zero_pad(field, con);
	else if (field >= 0)
	{
		con->print += field;
		while (field-- > 0)
			write(1, " ", 1);
	}
}

int 	print_u(va_list ap, t_type con)
{
	uintmax_t k;
	int strlen;
	char *str;

	k = flag_intoux(con, ap);
	str = ft_itoa(k, '0');
	strlen = ft_strlen(str);
	if (con.left_ali)
	{
		con.zero_pad = 0;
		if (precision(k, &con, strlen) != -1)
			ft_putstr(str);
		field(&con, strlen, str);
	}
	else if (con.right_ali)
	{
		field(&con, strlen, str);
		if (precision(k, &con, strlen) != -1)
			ft_putstr(str);
	}
	free(str);
	return (con.print);
}