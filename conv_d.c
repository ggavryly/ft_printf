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



int 	print_d(va_list ap, t_type con)
{
	t_flag *nbr;

	nbr = flag_intr(con, ap);
	flag_value(nbr);
	if (con.left_ali)
	{


	}
	else if (con.right_ali)
	{

	}

}