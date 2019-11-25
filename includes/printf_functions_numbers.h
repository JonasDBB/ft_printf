/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   printf_functions_numbers.h                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: jbennink <jbennink@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/22 14:15:58 by jbennink       #+#    #+#                */
/*   Updated: 2019/11/25 12:03:02 by jbennink      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_FUNCTIONS_NUMBERS_H
# define PRINTF_FUNCTIONS_NUMBERS_H
# include "libftprintf.h"

int		ft_digits(long n, int base);
int		ft_abs(int i);
char	*ft_itoabase(unsigned long n, int base, char capital);
char	ft_getchar(unsigned long n, char capital);
char	*ft_getnbrstr(long long n, int zeros, char *nbr);

int		ft_printnbr(va_list args, t_flags flags, int count);
int		ft_zero_prcsn(t_flags flags, int count);
int		ft_regular_fill(t_flags flags, int count, int n);
int		ft_zeros_fill(t_flags flags, int count, int n);

int		ft_printunsg(va_list args, t_flags flags, int count, char capital);
int		ft_u_get_zeros(t_flags *flags, int len, int n);
int		ft_u_zeros_prcsn(t_flags *flags, int len);
int		ft_u_zeros_fill(t_flags *flags, int len, int n);
int		ft_printptr(va_list args, t_flags flags, int count);

#endif
