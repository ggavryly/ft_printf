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

static void	sign(intmax_t *k,t_type *con)
{
	if (((con->sign) || *k < 0 || con->space))
	{
		if (*k < 0)
			write(1, "-", 1);
		else if (con->sign)
			write(1, "+", 1);
		else if (con->space)
			write(1, " ", 1);
		if (!con->left_ali)
		{
			con->sign = 0;
			*k = 0;
			con->space = 0;
		}
		con->print++;
	}
}

static void	zero_pad(int field, t_type *con, intmax_t *k)
{
	if (con->sign || con->space || *k < 0)
		sign(k, con);
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

static int	precision(intmax_t k, t_type *con, int strlen)
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

static void	field(t_type *con, int strlen, char *str, intmax_t *k)
{
	int prec;
	int field;
	int print;

	prec = con->precision;
	print = (str[0] == '0' && prec == -1) ? 0 : strlen;
	field = con->field_width;
	if (con->sign || *k < 0 || con->space)
		print += 1;
	if (prec > strlen)
		print += prec - strlen;
	else if (prec < strlen && prec > 0)
		print = strlen;
	else
		print += (prec == -1) ? 0 : prec;
	field -= print;
	if (con->zero_pad && !con->left_ali)
		zero_pad(field, con, k);
	else if (field >= 0)
	{
		con->print += field;
		while (field-- > 0)
			write(1, " ", 1);
	}
}

int 	print_d(va_list ap, t_type con)
{
	intmax_t k;
	int strlen;
	char *str;

	k = flag_intdi(con, ap);
	str = ft_itoa(k, '0');
	strlen = ft_strlen(str);
	if (con.left_ali)
	{
		con.zero_pad = 0;
		sign(&k, &con);
		if (precision(k, &con, strlen) != -1)
			ft_putstr(str);
		field(&con, strlen, str, &k);
	}
	else if (con.right_ali)
	{
		field(&con, strlen, str, &k);
		sign(&k, &con);
		if (precision(k, &con, strlen) != -1)
			ft_putstr(str);
	}
	free(str);
	return (con.print);
}