/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_n.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ninieddu <ninieddu@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 14:42:59 by ninieddu          #+#    #+#             */
/*   Updated: 2021/04/08 16:04:09 by ninieddu         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_base_p(unsigned long n, unsigned long base, int maj,
t_argu ma)
{
	int		i;

	i = 0;
	if (maj == 1)
		i = 32;
	if (n >= base && maj == 1)
		ft_putnbr_base_p(n / base, base, 1, ma);
	if (n >= base && maj == 0)
		ft_putnbr_base_p(n / base, base, 0, ma);
	if (n % base < 10)
		ft_putchar((n % base) + 48, ma);
	else
		ft_putchar((n % base) + 87 - i, ma);
}

void	ft_putstrp(char *str, t_argu ma)
{
	int		i;

	i = 0;
	if (ma.precision == 1)
	{
		while (ma.w_precision > 0 && str[i])
		{
			*ma.ret += write(1, &str[i], 1);
			i++;
			ma.w_precision--;
		}
	}
	if (ma.precision == 0)
	{
		while (str[i])
		{
			*ma.ret += write(1, &str[i], 1);
			i++;
		}
	}
}

void	ft_fill_nbrl(t_argu ma, int x)
{
	char	c;

	c = 32;
	if (x < ma.w_precision && ma.width != 0)
		ma.width -= ma.w_precision - x;
	if (ma.neg == 1 && ma.minus == 0 && ma.zero == 0)
		*ma.ret += write(1, "-", 1);
	while (ma.w_precision > x && ma.precision == 1 && x <= ma.w_precision)
	{
		*ma.ret += write(1, "0", 1);
		ma.w_precision--;
	}
	if (ma.width >= 0)
	{
		if (ma.minus == 0 && ma.precision == 0 && ma.zero == 1)
			c = 48;
		while (ma.width > x)
		{
			ft_putchar(c, ma);
			ma.width--;
		}
	}
}

void	ft_toconvert(char *mf, int i, t_argu ma)
{
	if (ma.width < 0)
	{
		ma.width = -ma.width;
		ma.minus = 1;
	}
	if (ma.w_precision < 0)
	{
		ma.precision = 0;
		ma.w_precision = 0;
	}
	if (mf[i] == '%')
	{
		if (ma.minus == 1 && ma.zero == 1)
			ma.zero = 0;
		ft_fill_rc(ma, 1);
	}
	if (mf[i] == 'c')
		ft_fill_rc(ma, 0);
	ft_toconvert_n(mf, i, ma);
}

void	ft_toconvert_n(char *mf, int i, t_argu ma)
{
	char	*str;

	if (mf[i] == 's')
	{
		str = va_arg(*ma.ptr, char *);
		if (!str)
			ft_fill_r(ma, "(null)");
		if (str)
			ft_fill_r(ma, str);
	}
	if (mf[i] == 'd' || mf[i] == 'i')
		ft_conversion_nbr(mf, i, ma);
	if (mf[i] == 'x' || mf[i] == 'X')
		ft_conversion_xx(mf, i, ma);
	if (mf[i] == 'p' || mf[i] == 'u')
		ft_convert_pu(mf, i, ma);
}
