/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scan_conv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggavryly <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/26 22:59:52 by ggavryly          #+#    #+#             */
/*   Updated: 2018/12/26 22:59:54 by ggavryly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int    scan_all(t_type *con, const char *str, int str_len, char conv)
{
	int i;
	
	i = 0;
	initialize_type(con);
	con->right_ali = 1;
	con->conversion = conv;
	while (i < str_len - 1 && str[i])
	{
		if (str[i] == '0')
			con->zero_pad = 16;
		else if (str[i] == '+')
			con->sign = 1;
		else if (str[i] == ' ')
			con->space = 1;
		else if (str[i] == '#')
			con->alt_form = 1;
		else if (str[i] >= '1' && str[i] <= '9')
		{
			con->field_width = scan_field(str, &i);
			continue;
		}
		else if (str[i] == '.')
		{
			con->precision = scan_precision(str, &i);
			continue;
		}
		else if (str[i] == 'h' || str[i] == 'l' || str[i] == 'L')
			scan_flag(str, &i, con);
		else if (str[i] == '-')
		{
			con->left_ali = 1;
			con->right_ali = 0;
		}
		i++;
	}
	if (str_len > 1)
		return (con->conversion);
	return (-1);
}

int     scan_precision(const char *str, int *iter)
{
	int res;
	int i;
	
	i = *iter + 1;
	res = ft_atoi(str + i);
	if (!res)
	{
		*iter = i;
		return (-1);
	}
	while (str[i] >= '0' && str[i] <= '9')
		i++;
	*iter = i;
	return (res);
}

int     scan_field(const char *str, int *iter)
{
	int res;
	int i;
	
	i = *iter;
	res = ft_atoi(str + i);
	while (str[i] >= '0' && str[i] <= '9')
		i++;
	*iter = i;
	return (res);
}

void    scan_flag(const char *str, int *iter, t_type *con)
{
	int i;
	
	i = *iter;
	if (str[i] == 'h' && str[i + 1] == 'h')
		con->hh = 1;
	else if (str[i] == 'h' && str[i + 1] != 'h')
		con->h = 1;
	else if (str[i] == 'l' && str[i + 1] == 'l')
		con->ll = 1;
	else if (str[i] == 'l' && str[i + 1] != 'l')
		con->l = 1;
	else if (str[i] == 'L')
		con->l32 = 1;
	while (str[i] == 'h' || str[i] == 'l')
		i++;
	*iter = i;
}