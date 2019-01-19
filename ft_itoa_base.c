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

static uintmax_t	swap_sign(intmax_t value, int *sign, uintmax_t base)
{
	uintmax_t res;

	if (value < 0 && base == 10)
	{
		*sign = 1;
		res = -value;
	}
	else
		res = value;
	return (res);
}

static	int			numbers(uintmax_t value)
{
	int i;

	i = 0;
	while (value >= 10)
	{
		value /= 10;
		i++;
	}
	return (i);
}

char				*itoa_base(intmax_t value, uintmax_t base, char a_a32)
{
	int			i;
	char		*str;
	uintmax_t	tmp;
	int			sign;

	sign = 0;
	tmp = swap_sign(value, &sign, base);
	i = numbers(tmp);
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

char				*itoa_base_u(uintmax_t value, uintmax_t base, char a_a32)
{
	int			i;
	char		*str;
	uintmax_t	tmp;

	i = 0;
	tmp = value;
	i = numbers(tmp);
	if (!(str = (char *)malloc(sizeof(char) * (i + 1))))
		return (NULL);
	str[i + 1] = '\0';
	while (i >= 0)
	{
		value = tmp % base;
		str[i] = (value >= 10) ? value - 10 + a_a32 : value + '0';
		tmp /= base;
		i--;
	}
	return (str);
}
