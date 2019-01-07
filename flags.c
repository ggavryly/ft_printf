/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggavryly <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/15 18:57:59 by ggavryly          #+#    #+#             */
/*   Updated: 2018/12/15 18:58:01 by ggavryly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void    initialize_type(t_type *con)
{
    con->conversion = 0;
    con->field_width = 0;
    con->precision = 0;
    con->alt_form = 0;
    con->left_ali = 0;
    con->right_ali = 0;
    con->sign = 0;
    con->space = 0;
    con->zero_pad = 0;
    con->hh = 0;
    con->h = 0;
    con->l = 0;
    con->ll = 0;
    con->l32 = 0;
    con->print = 0;
}

void	initialize_flag(t_flag *flag)
{
	flag->value = NULL;
	flag->i = 0;
	flag->d = 0;
	flag->f = 0;
	flag->h = 0;
	flag->hh = 0;
	flag->l = 0;
	flag->l32 = 0;
	flag->ll = 0;
}
