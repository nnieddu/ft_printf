/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ninieddu <ninieddu@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 14:42:59 by ninieddu          #+#    #+#             */
/*   Updated: 2020/02/17 18:15:19 by ninieddu         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar(char c, t_argu ma)
{
	*ma.ret += write(1, &c, 1);
}

int		ft_strlen(char *s)
{
	int		size;

	size = 0;
	while (s[size])
		size++;
	return (size);
}

void	ft_putstr(char *str, t_argu ma)
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

int		ft_atoiformat(char *str, int i)
{
	unsigned long long int	big;
	int						nbr;
	char					sign;

	big = 0;
	sign = '+';
	while ((str[i] < 14 && str[i] > 8) || str[i] == 32)
		i++;
	if (str[i] == '-')
	{
		sign = str[i];
		i++;
	}
	while (str[i] >= 48 && str[i] <= 57)
	{
		big = big * 10 + (str[i] - 48);
		i++;
	}
	if (big > 9223372036854775807)
		return (sign == '-' ? 0 : -1);
	nbr = big;
	return (sign == '-' ? -nbr : nbr);
}

void	ft_putnbr_base(unsigned int n, unsigned int base, int maj, t_argu ma)
{
	int		i;

	i = 0;
	if (n == 0 && ma.precision == 1 && ma.w_precision == 0)
		return ;
	if (maj == 1)
		i = 32;
	if (n >= base && maj == 1)
		ft_putnbr_base(n / base, base, 1, ma);
	if (n >= base && maj == 0)
		ft_putnbr_base(n / base, base, 0, ma);
	if (n % base < 10)
		ft_putchar((n % base) + 48, ma);
	else
		ft_putchar((n % base) + 87 - i, ma);
}
