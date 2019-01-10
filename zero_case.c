/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zero_case.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggavryly <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 15:25:49 by ggavryly          #+#    #+#             */
/*   Updated: 2019/01/09 15:25:51 by ggavryly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	fieldo(t_type *con)
{
	int field;

	if (con->print < con->field_width)
	{
		field = con->print - con->field_width;
		con->print += field;
		while (field-- > 0)
			ft_putchar(' ');
	}
}

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
	if (con->space || con->sign)
		con->print++;
	return (1);
}

static void	precision(t_type *con)
{
	int prec;

	prec = con->precision;
	if (prec > 0)
	{
		while (prec-- > 0)
			ft_putchar('0');
		con->print += con->precision;
	}
}

void	zero_case_left(t_type *con, char *str)
{
	int field;

	field = con->field_width;
	if ((con->sign || con->space))
		sign(0, con);
	precision(con);
	if (con->precision == -1)
	{
		field -= con->print;
		if (field > 0)
			con->print += field;
		while (field-- > 0)
			ft_putchar(' ');
		con->field_width = 0;
	}
	fieldo(con);
	free(str);
}

void	zero_case_right(t_type *con, char *str)
{
	int prec;
	int field;

	field = con->field_width;
	zero_case_help(con);
	prec = con->precision;
	if ((con->sign || con->space) && con->precision != -1)
		sign(0, con);
	precision(con);
	if (!con->precision)
	{
		con->print++;
		ft_putchar('0');
	}
	free(str);
}