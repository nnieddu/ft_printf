/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_di.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ninieddu <ninieddu@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 14:38:02 by ninieddu          #+#    #+#             */
/*   Updated: 2021/04/13 15:35:54 by ninieddu         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_conversion_nbr(char *mf, int i, t_argu ma)
{
	int		n;
	int		n2;
	int		x;

	x = 1;
	n = 0;
	if (mf[i] == 'd' || mf[i] == 'i')
		n = va_arg(*ma.ptr, int);
	n2 = n;
	if (n < 0)
	{
		n = -n;
		ma.neg = 1;
		x++;
		ma.w_precision++;
	}
	while (n2 > 10)
	{
		n2 /= 10;
		x++;
	}
	if (n == 0 && ma.w_precision == 0 && ma.precision == 1)
		ma.width++;
	ft_conversion_nbr_n(mf[i], ma, n, x);
}

void	ft_conversion_nbr_n(char mfi, t_argu ma, int n, int x)
{
	if (ma.minus == 0)
	{
		ft_fill_nbr(ma, x);
		ft_nbr_road(mfi, ma, n);
	}
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
		ft_nbr_road(mfi, ma, n);
		ft_fill_nbrl(ma, x);
	}
}

void	ft_nbr_road(char mfi, t_argu ma, int n)
{
	if (mfi == 'd' || mfi == 'i')
	{
		if (n > INT_MAX)
		{
			*ma.ret += write(1, "2147483648", 10);
			return ;
		}
		if (n == 0 && ma.w_precision != 0)
		{
			ft_putchar('0', ma);
			return ;
		}
		if (n == 0 && ma.w_precision == 0 && ma.precision == 1)
			return ;
		ft_putnbr_base(n, 10, 0, ma);
	}
}

void	ft_fill_nbr(t_argu ma, int x)
{
	char	c;

	c = 32;
	if (x < ma.w_precision && ma.width != 0 && ma.minus == 0)
		ma.width -= ma.w_precision - x;
	if (ma.width >= 0)
	{
		if (ma.minus == 0 && ma.precision == 0 && ma.zero == 1)
			c = 48;
		if (ma.neg == 1 && c == 48)
		{
			*ma.ret += write(1, "-", 1);
			ma.neg = 0;
		}
		while (ma.width > x)
		{
			ft_putchar(c, ma);
			ma.width--;
		}
	}
	ft_fill_nbr_n(ma, x);
}

void	ft_fill_nbr_n(t_argu ma, int x)
{
	if (ma.neg == 1)
		*ma.ret += write(1, "-", 1);
	while (ma.w_precision > x && ma.precision == 1 && x <= ma.w_precision
		&& ma.minus == 0)
	{
		*ma.ret += write(1, "0", 1);
		ma.w_precision--;
	}
}
