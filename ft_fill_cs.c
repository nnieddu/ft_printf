/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_cs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ninieddu <ninieddu@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 14:55:52 by ninieddu          #+#    #+#             */
/*   Updated: 2021/04/08 16:03:08 by ninieddu         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_fill_rc(t_argu ma, int prct)
{
	char	c;

	c = 32;
	if (ma.width < 0)
	{
		ma.width = -ma.width;
		ma.minus = 1;
	}
	if (ma.minus == 1)
		ft_fill_lc(ma, c, prct);
	ma.width--;
	if (ma.width >= 0 && ma.minus == 0)
	{
		if (ma.minus == 0 && ma.zero == 1)
			c = 48;
		while (ma.width >= 1)
		{
			ft_putchar(c, ma);
			ma.width--;
		}
	}
	if (prct == 1 && ma.minus == 0)
		ft_putchar('%', ma);
	else if (prct == 0 && ma.minus == 0)
		ft_putchar(va_arg(*ma.ptr, int), ma);
}

void	ft_fill_lc(t_argu ma, char c, int prct)
{
	if (prct == 1)
		*ma.ret += write(1, "%", 1);
	else if (prct == 0)
		ft_putchar(va_arg(*ma.ptr, int), ma);
	if (ma.precision == 1 && ma.w_precision > 0)
		ma.width--;
	if (ma.precision == 0 || ma.w_precision == 0)
		ma.width--;
	if (ma.width >= 0)
	{
		if (ma.w_precision == 0 && ma.zero == 1)
			c = 48;
		while (ma.width >= 1)
		{
			ft_putchar(c, ma);
			ma.width--;
		}
	}
}

void	ft_fill_r(t_argu ma, char *str)
{
	char	c;

	c = 32;
	if (ma.width < 0)
	{
		ma.width = -ma.width;
		ma.minus = 1;
	}
	if (ma.precision == 1 && ft_strlen_printf(str) > ma.w_precision)
		ma.width += ft_strlen_printf(str) - ma.w_precision;
	if (ma.minus == 1)
	{
		ft_fill_l(ma, str, c);
	}
	if (ma.width >= 0 && ma.minus == 0)
	{
		if (ma.minus == 0 && ma.precision == 0 && ma.zero == 1)
			c = 48;
		while (ma.width > ft_strlen_printf(str))
		{
			ft_putchar(c, ma);
			ma.width--;
		}
		ft_putstrp(str, ma);
	}
}

void	ft_fill_l(t_argu ma, char *str, char c)
{
	ft_putstrp(str, ma);
	if (ma.width >= 0)
	{
		if (ma.w_precision == 0 && ma.zero == 1)
			c = 48;
		while (ma.width > ft_strlen_printf(str))
		{
			ft_putchar(c, ma);
			ma.width--;
		}
	}
}
