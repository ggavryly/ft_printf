/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggavryly <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 18:35:02 by ggavryly          #+#    #+#             */
/*   Updated: 2019/01/14 18:35:05 by ggavryly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	float_put_before(char **str, int *len, long double k, int *iter)
{
	char *tmp;
	int len0;
	int i;

	len0 = len[0];
	i = *iter;
	tmp = *str;
	if (len0)
	{
		tmp[i++] = ((int) (k) % 10) + '0';
		len0--;
	}
	while (len0)
	{
		tmp[i++] = ((int)(k / 10.0) % 10) + '0';
		len0--;
		k /= 10;
	}
	*iter = i;
	*str = tmp;
}

static void	float_put_after(char **str, int *len, long double k, int *iter)
{
	char *tmp;
	int len1;
	int i;

	len1 = len[1];
	i = *iter;
	tmp = *str;
	while (len1)
	{
		tmp[i++] = ((int)(k * 10.0) % 10) + '0';
		len1--;
		k *= 10;
	}
	*iter = i;
	*str = tmp;
}

static int float_len_before(long double k)
{
	int len;

	len = 1;
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

	len = 0;
	while (k < 1.0)
	{
		k *= 10;
		len++;
	}
	k *= 10.0;
	while ((((int)(k)) % 10) != 0)
	{
		k *= 10.0;
		len++;
	}
	return (len);
}

char *float_str(long double k)
{
	int len[2];
	char *str;
	int i;

	len[0] = float_len_before(k);
	len[1] = float_len_after(k);
	i = 0;
	if (!(str = (char *)malloc(sizeof(char) * len[0] + len[1] + 2)))
		return (NULL);
	str[len[0] + len[1] + 1] = '\0';
	float_put_before(&str,len,k,&i);
	str[len[0]] = '.';
	i++;
	float_put_after(&str,len,k,&i);
	return (str);
}