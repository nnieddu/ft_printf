/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_pu.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ninieddu <ninieddu@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 18:38:11 by ninieddu          #+#    #+#             */
/*   Updated: 2021/04/13 15:05:20 by ninieddu         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_convert_pu(char *mf, int i, t_argu ma)
{
	unsigned long	n;
	int				x;

	x = 1;
	n = 0;
	if (mf[i] == 'p')
	{
		n = va_arg(*ma.ptr, unsigned long);
		if (ma.precision == 1 && ma.w_precision == 0 && ma.width > 0 && !n)
			x -= 2;
		x += 2;
		if (n == 0 && ma.minus == 0)
		{
			if (ma.precision == 1 && ma.w_precision == 0)
				x++;
			ft_fill_nbr(ma, x);
			if (ma.precision == 1 && ma.w_precision == 0)
				ft_putstrp("0x", ma);
			else
				ft_putstrp("0x0", ma);
			return ;
		}
	}
	ft_convert_pu_n(mf[i], ma, n, x);
}

void	ft_convert_pu_n(char mfi, t_argu ma, unsigned long n, int x)
{
	unsigned long	n2;

	if (mfi == 'p')
	{
		if (n == 0 && ma.minus == 1)
		{
			if (ma.precision == 1 && ma.w_precision == 0)
			{
				x++;
				ft_putstrp("0x", ma);
			}
			else
				ft_putstrp("0x0", ma);
			ft_fill_nbr(ma, x);
			return ;
		}
		n2 = n;
		while (n2 > 16)
		{
			n2 / 16;
			x++;
		}
	}
	ft_convert_pu_n2(mfi, ma, n, x);
}

void	ft_convert_pu_n2(char mfi, t_argu ma, unsigned long n, int x)
{
	if (mfi == 'p')
	{
		if (ma.minus == 0)
		{
			ft_fill_nbr(ma, x);
			ft_putstrp("0x", ma);
			ft_putnbr_base_p(n, 16, 0, ma);
		}
		if (ma.minus == 1)
		{
			ft_putstrp("0x", ma);
			ft_putnbr_base_p(n, 16, 0, ma);
			ft_fill_nbr(ma, x);
		}
	}
	if (mfi == 'u')
		ft_convert_u(ma, x, 0, 0);
}

void	ft_convert_u(t_argu ma, int x, unsigned int	n2, unsigned int n3)
{
	n2 = va_arg(*ma.ptr, unsigned int);
	if (n2 == 0 && ma.w_precision == 0 && ma.precision == 1)
		ma.width++;
	n3 = n2;
	while (n3 > 10)
	{
		n3 / 10;
		x++;
	}
	if (ma.minus == 0)
	{
		ft_fill_nbr(ma, x);
		ft_putnbr_base(n2, 10, 0, ma);
	}
	if (ma.minus == 1)
	{
		while (ma.w_precision > x && ma.precision == 1 && x <= ma.w_precision)
		{
			*ma.ret += write(1, "0", 1);
			ma.w_precision--;
			ma.width--;
		}
		ft_putnbr_base(n2, 10, 0, ma);
		ft_fill_nbrl(ma, x);
	}
}
