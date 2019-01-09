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

int    print_p(va_list ap, t_type con)
{
	long long c;
	long long tmp;
	int i;
	char *str;
	
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
		str = itoa_base(c, 16, 'a');
		ft_putstr(str);
		free(str);
	}
	con.print += i;
	return (con.print);
}
