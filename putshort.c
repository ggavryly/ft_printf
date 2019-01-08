/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putshort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggavryly <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/07 11:44:05 by ggavryly          #+#    #+#             */
/*   Updated: 2019/01/07 11:44:07 by ggavryly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static unsigned short	init(short val, int *sign)
{
	unsigned short res;

	res = 0;
	if (val < 0)
	{
		if (*sign)
			*sign = 3;
		res = (unsigned short) -val;
	}
	else
	{
		if (*sign)
			*sign = 1;
		res = (unsigned short) val;
	}
	return (res);
}

static char *	str_mem(unsigned short res, int *count1, int sign)
{
	char *str;
	int count;

	str = NULL;
	count = 0;
	if (res == 0)
		count++;
	if (sign)
		count++;
	while (res)
	{
		res /= 10;
		count++;
	}
	str = (char *)malloc(count + 1);
	*count1 = count;
	return (str);
}
void	ft_putshort(short val, int sign)
{
	unsigned short print;
	int count;
	char *str;

	count = 0;
	print = init(val, &sign);
	str = str_mem(print, &count, sign);
	str[count--] = '\0';
	while (count >= 0)
	{
		if (print >= 10)
			str[count] = (char)(print % 10 + '0');
		else
			str[count] = (char)(print + '0');
		print /= 10;
		count--;
	}
	if (sign)
		str[0] = 42 + sign;
	ft_putstr(str);
	free(str);
}

