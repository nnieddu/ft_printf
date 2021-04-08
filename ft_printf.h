/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ninieddu <ninieddu@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/17 16:01:50 by ninieddu          #+#    #+#             */
/*   Updated: 2021/04/08 14:42:43 by ninieddu         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <limits.h>

typedef struct	s_argu
{
	int			neg;
	int			width;
	int			precision;
	int			w_precision;
	int			minus;
	int			zero;
	int			*ret;
	va_list		*ptr;
}				t_argu;

int				ft_printf(char const *format, ...)
 __attribute__((format(printf,1,2)));
void			ft_parsing(char *mf, int i, t_argu ma);
void			ft_format(char *mf, int i, t_argu ma);
void			ft_format_n(char *mf, int i, t_argu ma);
int				ft_atoiformat(char *mf, int i);
int				ft_strlen_printf(char *s);
void			ft_toconvert(char *mf, int i, t_argu ma);
void			ft_toconvert_n(char *mf, int i, t_argu ma);
void			ft_putchar(char c, t_argu ma);
void			ft_conversion_s(t_argu ma);
void			ft_conversion_nbr(char *mf, int i, t_argu ma);
void			ft_conversion_nbr_n(char mfi, t_argu ma, int n, int x);
void			ft_putstr(char *str, t_argu ma);
void			ft_fill_r(t_argu ma, char *str);
void			ft_fill_l(t_argu ma, char *str, char c);
void			ft_convert_pu(char *mf, int i, t_argu ma);
void			ft_fill_nbr(t_argu ma, int x);
void			ft_fill_nbr_n(t_argu ma, int x);
void			ft_fill_nbrl(t_argu ma, int x);
void			ft_nbr_road(char mfi, t_argu ma, int n);
void			ft_fill_rc(t_argu ma, int prct);
void			ft_fill_lc(t_argu ma, char c, int prct);
void			ft_conversion_xx(char *mf, int i, t_argu ma);
void			ft_conversion_xx_m0(char mfi, t_argu ma, int x,
unsigned long n);
void			ft_conversion_xx_m1(char mfi, t_argu ma, int x,
unsigned long n);
void			ft_putstrp(char *str, t_argu ma);
void			ft_convert_u(t_argu ma, int x);
void			ft_convert_pu_n(char mfi, t_argu ma, unsigned long n, int x);
void			ft_convert_pu_n2(char mfi, t_argu ma, unsigned long n, int x);
void			ft_putnbr_base_p(unsigned long n, unsigned long base, int maj,
t_argu ma);
void			ft_putnbr_base(unsigned int n, unsigned int base, int maj,
t_argu ma);

#endif
