/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggavryly <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/20 11:20:44 by ggavryly          #+#    #+#             */
/*   Updated: 2018/12/20 11:20:55 by ggavryly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <stdarg.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdint.h>
#include <limits.h>

typedef struct  s_conv
{
    char        conversion;
    int         field_width;
    int         precision;
	unsigned int         alt_form : 1;
	unsigned int         left_ali : 1;
	unsigned int         right_ali : 1;
	unsigned int         sign : 1;
	unsigned int         space : 1;
	unsigned int         zero_pad : 1;
	unsigned int         h : 1;
	unsigned int         hh : 1;
	unsigned int         l : 1;
	unsigned int         ll : 1;
	unsigned int         l32 : 1;
    int         print;
}               t_type;

int     ft_printf(const char *format, ...);

void 	ft_putchar(char c);
int		ft_atoi(const char *str);
char	*ft_itoa(intmax_t value, char sig);
void	ft_putnbr(intmax_t k, int sign);
void	ft_putstr(char const *s);
char	*ft_strchr(const char *s, int c);
size_t	ft_strlen(const char *s);
char	*ft_strdup(const char *src);
int		ft_strcmp(const char *s1, const char *s2);
char	*itoa_base(intmax_t value, uintmax_t base, char a_a32);
char	*itoa_base_u(uintmax_t value, uintmax_t  base, char a_a32);
long long int    atoi_base(char *nbr, int base, char a_a32);
void    ft_putnstr(const char *str, int n);

int     scan_conv(const char *str, t_type *con, int str_len);
int     scan_precision(const char *str, int *iter);
int     scan_field(const char *str, int *iter);
int    scan_all(t_type *con, const char *str, int str_len, char conv);
void    scan_flag(const char *str, int *iter, t_type *con);

int     con_len(const char *str);
void    initialize_type(t_type *con);
intmax_t	flag_intdi(t_type con, va_list ap);
intmax_t	flag_intoux(t_type con, va_list ap);
void	zero_case_right(t_type *con, char *str);
void	zero_case_left(t_type *con, char *str);
void	zero_case_help(t_type *con, int *flag);
void	zero_field(t_type *con, int print, int *flag);

int    print_conv(char con, t_type c, va_list ap);
int    print_p(va_list ap, t_type con);
int    print_s(va_list ap, t_type con);
int    print_c(va_list ap, t_type con);
int 	print_d(va_list ap, t_type con);
int 	print_i(va_list ap, t_type con);
int 	print_x(va_list ap, t_type con);
int 	print_o(va_list ap, t_type con);
int 	print_u(va_list ap, t_type con);
int    print_perc(t_type con);

#endif
