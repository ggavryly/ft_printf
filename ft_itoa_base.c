/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggavryly <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/21 16:59:48 by ggavryly          #+#    #+#             */
/*   Updated: 2018/12/21 16:59:49 by ggavryly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static uintmax_t	swap_sign(intmax_t value, int *sign)
{
	uintmax_t res;

	res = 0;
	if (value < 0)
	{
		*sign = 1;
		res = -value;
	}
	else if (value >= 0)
		res = value;
	return (res);
}

char	*itoa_base(intmax_t value, uintmax_t  base, char a_a32)
{
	int			i;
	char		*str;
	uintmax_t	tmp;

	int             sign;
	
	i = 0;
	sign = 0;
	tmp = swap_sign(value, &sign);
	while (tmp >= base)
	{
		tmp /= base;
		i++;
	}
	tmp = (value < 0) ? (-value) : value;
	if (!(str = (char *)malloc(sizeof(char) * (i + 1 + sign))))
		return (NULL);
	str[i + 1 + sign] = '\0';
	if (sign)
		str[0] = '-';
	while (i >= 0)
	{
		value = tmp % base;
		str[i + sign] = (value >= 10) ? value - 10 + a_a32 : value + '0';
		tmp /= base;
		i--;
	}
	return (str);
}