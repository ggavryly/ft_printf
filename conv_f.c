/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_f.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggavryly <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 15:26:17 by ggavryly          #+#    #+#             */
/*   Updated: 2019/01/14 15:26:18 by ggavryly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int float_len_before(long double k)
{
	int len;

	len = 0;
	while (k > 1.0)
	{
		k /= 10.0;
		len++;
	}
	return (len);
}

static int float_len_after(long double k)
{

	int len;

	k *= 10;
	while ((((int)(k)) % 10) != 0)
	{
		k *= 10.0;
		len++;
	}
	return (len);
}

int print_f(t_type *con)
{
	long double k;
	int len[2];
	char *buf;

	k = flag_float(con);
	buf = float_str(k);
}
