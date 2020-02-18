/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ninieddu <ninieddu@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 21:31:08 by ninieddu          #+#    #+#             */
/*   Updated: 2020/02/17 21:20:35 by ninieddu         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf(char const *format, ...)
{
	t_argu	ma;
	int		i;
	char	*mf;
	va_list	alist;
	int		ret;

	va_start(alist, format);
	ret = 0;
	i = 0;
	ma.ret = &ret;
	ma.width = 0;
	ma.minus = 0;
	ma.precision = 0;
	ma.w_precision = 0;
	ma.zero = 0;
	ma.ptr = &alist;
	mf = (char *)format;
	ft_parsing(mf, i, ma);
	return (ret);
}

void	ft_parsing(char *mf, int i, t_argu ma)
{
	while (mf[i] != '\0')
	{
		if (mf[i] == '%' && mf[i + 1] == '\0')
			return ;
		if (mf[i] == '%' && mf[i + 1] == '%')
		{
			*ma.ret += write(1, "%", 1);
			i++;
		}
		else if (mf[i] == '%')
		{
			i++;
			ft_format(mf, i, ma);
			while (mf[i] != 'c' && mf[i] != 's' && mf[i] != 'p'
			&& mf[i] != 'd' && mf[i] != 'i' && mf[i] != 'u'
			&& mf[i] != 'x' && mf[i] != 'X' && mf[i] != '%' && mf[i])
				i++;
		}
		else
			*ma.ret += write(1, &mf[i], 1);
		i++;
	}
}

void	ft_format(char *mf, int i, t_argu ma)
{
	while (mf[i] != 'c' && mf[i] != 's' && mf[i] != 'p' && mf[i] != 'd'
	&& mf[i] != 'i' && mf[i] != 'u' && mf[i] != 'x' && mf[i] != 'X'
	&& mf[i] != '%' && mf[i] != '.' && mf[i])
	{
		if (mf[i] == '*' && mf[i - 1] != '.' && ma.width == 0)
			ma.width = va_arg(*ma.ptr, int);
		if (mf[i] > '0' && mf[i] <= '9' && mf[i - 1] != '.' && ma.width == 0)
		{
			ma.width = ft_atoiformat(mf, i);
			while (mf[i + 1] >= '0' && mf[i + 1] <= '9')
				i++;
		}
		if (mf[i] == '-')
			ma.minus = 1;
		if (mf[i] == '0' && mf[i - 1] == '%')
			ma.zero = 1;
		i++;
	}
	ft_format_n(mf, i, ma);
}

void	ft_format_n(char *mf, int i, t_argu ma)
{
	while (mf[i] != 'c' && mf[i] != 's' && mf[i] != 'p' && mf[i] != 'd'
	&& mf[i] != 'i' && mf[i] != 'u' && mf[i] != 'x' && mf[i] != 'X'
	&& mf[i] != '%' && mf[i])
	{
		if (mf[i] == '.')
		{
			ma.precision = 1;
			if (mf[i + 1] == '*')
				ma.w_precision = va_arg(*ma.ptr, int);
			if (mf[i + 1] >= '0' && mf[i + 1] <= '9')
				ma.w_precision = ft_atoiformat(mf, i + 1);
			if (ma.w_precision < 0)
				ma.precision = 0;
			while (mf[i + 1] >= '0' && mf[i + 1] <= '9')
				i++;
		}
		i++;
	}
	ft_toconvert(mf, i, ma);
}
