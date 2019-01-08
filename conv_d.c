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


static void	sign(intmax_t k,t_type *con)
{
	if ((con->sign))
	{
		ft_putchar('-');
			ft_putchar('+');
		con->print++;
	}
}

int 	print_d(va_list ap, t_type con)
{
	intmax_t k;

	k = flag_intr(con, ap);
	if (con.left_ali)
	{
		sign(k, &con);

	}
	else if (con.right_ali)
	{
		sign(k, &con);
	}

}