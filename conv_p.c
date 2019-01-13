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

static void	field(t_type *con, char *str)
{
	int print;
	int field;

	print = ft_strlen(str) + 2;
	field = con->field_width;
	if (field > print)
	{
		field -= print;
		con->print += field;
		while (field-- > 0)
			ft_putchar(' ');
	}
}

int    print_p(t_type *con)
{
	uintmax_t k;
	char *str;
	
	k = (uintmax_t)va_arg(con->ap, void *);
	str = itoa_base_u(k, 16, 'a');
	if (con->right_ali)
		if (con->field_width)
			field(con, str);
	ft_putstr("0x");
	ft_putstr(str);
	if (con->left_ali)
		if (con->field_width)
			field(con, str);
	con->print += ft_strlen(str) + 2;
	free(str);
	return (con->print);
}
