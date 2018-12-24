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
	unsigned int         zero_pad : 5;
	unsigned int         h : 1;
	unsigned int         hh : 1;
	unsigned int         l : 1;
	unsigned int         ll : 1;
	unsigned int         l32 : 1;
    int         print;
}               t_type;

void 	ft_putchar(char c);
int	ft_atoi(const char *str);
char			*ft_itoa(int n);
void			ft_putnbr(int n);
void	ft_putstr(char const *s);
char	*ft_strchr(const char *s, int c);
size_t	ft_strlen(const char *s);
char	*ft_strdup(const char *src);
int		ft_strcmp(const char *s1, const char *s2);

char    *print_int(t_type *con, long long int nbr, int base);

void    initialize_type(t_type *con);
char	*itoa_base(long long int value, int base, char a_a32);
long long int    atoi_base(char *nbr, int base, char a_a32);
int     scan_conv(const char *str, t_type *con, int str_len);
int    print_conv(char con, t_type c, va_list ap);
int     con_len(const char *str);
int    scan_c(t_type *con, const char *str, int str_len);
int    scan_s(t_type *con, const char *str, int str_len);
int    scan_d(t_type *con, const char *str, int str_len);
int     scan_perc(t_type *con, const char *str, int str_len);
int    print_p(va_list ap, t_type con);
int    print_d(va_list ap, t_type con);
int    scan_p(t_type *con, const char *str, int str_len);

int    print_s(va_list ap, t_type con);
int    print_c(va_list ap, t_type con);
int    print_perc(t_type con);
int     ft_printf(const char *format, ...);
void    ft_putnstr(const char *str, int n);
void	print(t_type *con, int len);
void    print_null(void);

#endif
