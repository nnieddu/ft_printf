/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_xx.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ninieddu <ninieddu@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 17:49:39 by ninieddu          #+#    #+#             */
/*   Updated: 2021/04/13 15:36:10 by ninieddu         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_conversion_xx(char *mf, int i, t_argu ma)
{
	long	n;
	long	n2;
	int		x;

	x = 1;
	n = va_arg(*ma.ptr, unsigned int);
	n2 = n;
	if (n < 0)
	{
		n = -n;
		ma.neg = 1;
		x++;
	}
	while (n2 > 16)
	{
		n2 /= 16;
		x++;
	}
	if (n == 0 && ma.w_precision == 0 && ma.precision == 1)
		ma.width++;
	ft_conversion_xx_m0(mf[i], ma, x, n);
}

void	ft_conversion_xx_m0(char mfi, t_argu ma, int x, unsigned long n)
{
	if (ma.minus == 0)
	{
		ft_fill_nbr(ma, x);
		if (ma.precision == 1 && ma.w_precision == 0 && n == 0)
			return ;
		if (mfi == 'x')
			ft_putnbr_base_p(n, 16, 0, ma);
		if (mfi == 'X')
			ft_putnbr_base_p(n, 16, 1, ma);
	}
	ft_conversion_xx_m1(mfi, ma, x, n);
}

void	ft_conversion_xx_m1(char mfi, t_argu ma, int x, unsigned long n)
{
	if (ma.minus == 1)
	{
		if (ma.neg == 1 && ma.zero == 0)
			*ma.ret += write(1, "-", 1);
		while (ma.w_precision > x && ma.precision == 1 && x <= ma.w_precision)
		{
			*ma.ret += write(1, "0", 1);
			ma.w_precision--;
			ma.width--;
		}
		if (ma.precision == 1 && ma.w_precision == 0 && n == 0)
		{
			ft_fill_nbrl(ma, x);
			return ;
		}
		if (mfi == 'x')
			ft_putnbr_base_p(n, 16, 0, ma);
		if (mfi == 'X')
			ft_putnbr_base_p(n, 16, 1, ma);
		ft_fill_nbrl(ma, x);
	}
}
