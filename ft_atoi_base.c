/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggavryly <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/21 16:59:57 by ggavryly          #+#    #+#             */
/*   Updated: 2018/12/21 16:59:58 by ggavryly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

long long int    atoi_base(char *nbr, int base, char a_a32)
{
	long long int nb;
	long long int tmp;
	int sign;
	int i;
	
	tmp = 0;
	i = 0;
	sign = 1;
	if (!nbr)
		return (0);
	while (nbr[i] && (nbr[i] < '0' || nbr[i] > '9') && (nbr[i] < a_a32 || nbr[i] > a_a32 + 26))
		i++;
	if (nbr[i - 1] == '-' || nbr[i - 1] == '+')
	{
		if (nbr[i - 1] == '-' && base == 10)
			sign = -1;
	}
	while (nbr[i] && ((nbr[i] >= '0' && nbr[i] <= '9') || (nbr[i] >= a_a32 && nbr[i] <= a_a32 + 26)))
	{
		nb = ((nbr[i] >= a_a32 && nbr[i] <= a_a32 + 26) ? ((nbr[i] - a_a32) + 10) : (nbr[i] - '0'));
		if (nb >= 0 && nb < base)
			tmp = tmp * base + nb;
		i++;
	}
	return (tmp * sign);
}
