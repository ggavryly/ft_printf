/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggavryly <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/21 16:56:03 by ggavryly          #+#    #+#             */
/*   Updated: 2018/12/21 16:56:05 by ggavryly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int    scan_conv(const char *str, t_type *con, int str_len)
{
	if (str[str_len - 1])
		return (scan_all(con, str, str_len, str[str_len - 1]));
	return (0);
}

int    print_conv(char con, t_type c, va_list ap)
{
	if (con == 'c')
		return (print_c(ap, c));
	else if (con == 's')
		return (print_s(ap, c));
    else if (con == 'p')
		return (print_p(ap, c));
    else if (con == 'd')
		return (print_d(ap, c));
//    else if (str[str_len - 1] == 'i')
//        scan_i();
//    else if (str[str_len - 1] == 'o')
//        scan_o();
//    else if (str[str_len - 1] == 'u')
//        scan_u();
//    else if (str[str_len - 1] == 'x')
//        scan_x();
//    else if (str[str_len - 1] == 'X')
//        scan_x32();
//    else if (str[str_len - 1] == 'C')
//        scan_c32();
//    else if (str[str_len - 1] == 'f')
//        scan_f();
	else if (con == '%')
		return (print_perc(c));
	return (0);
}

int     con_len(const char *str)
{
	int i;
	int res;
	char *s;
	char *s1;
	
	i = 0;
	res = 1;
	s = "cspdiouxX%f";
	s1 = " #.-+0hlL123456789";
	while (str[i])
	{
		if (ft_strchr(s1, str[i]))
			res++;
		else if (ft_strchr(s, str[i]))
			return (res + 1);
		else
			return (res);
		i++;
	}
	return (res);
}

int ft_printf(const char *format, ...)
{
	va_list ap;
	t_type con;
	int i;
	int print;
	
	i = 0;
	print = 0;
	va_start(ap, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			print += print_conv(scan_conv(format + i, &con, con_len(format + i + 1)), con, ap);
			i += con_len(format + i + 1);
		}
		else
		{
			print++;
			ft_putchar(format[i++]);
		}
	}
	va_end (ap);
	return (print);
}
