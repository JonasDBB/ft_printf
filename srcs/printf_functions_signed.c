/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   printf_functions_signed.c                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: jbennink <jbennink@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/22 14:14:24 by jbennink       #+#    #+#                */
/*   Updated: 2019/11/22 16:23:46 by jbennink      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_zero_precision(t_flags flags, int count)
{
	char	*result;

	result = ft_strdup("");
	count = ft_printstr(flags, count, result);
	free(result);
	return (count);
}

int	ft_regular_fill(t_flags flags, int count, int n)
{
	char	*result;

	result = ft_itoa(n);
	count = ft_printstr(flags, count, result);
	free(result);
	return (count);
}

int	ft_zeros_fill(t_flags flags, int count, int n)
{
	int		zeros;
	char	*result;
	int		digits;

	zeros = 0;
	digits = ft_digits(n, 10);
	while (flags.minwidth > digits)
	{
		zeros++;
		flags.minwidth--;
	}
	result = ft_getnbrstr(n, zeros, ft_itoa((ft_abs(n))));
	count = ft_printstr(flags, count, result);
	free(result);
	return (count);
}

int	ft_printnbr(va_list args, t_flags flags, int count)
{
	char	*result;
	int		n;
	int		zeros;

	n = va_arg(args, int);
	if (flags.precision == 0)
		return (ft_zero_precision(flags, count));
	if (flags.precision == -1 && flags.filler == ' ')
		return (ft_regular_fill(flags, count, n));
	zeros = 0;
	if (flags.precision == -1 && flags.filler == '0')
		return (ft_zeros_fill(flags, count, n));
	if (flags.filler == '0')
		flags.filler = ' ';
	while (flags.precision > ft_digits(ft_abs(n), 10))
	{
		zeros++;
		flags.precision--;
	}
	result = ft_getnbrstr(n, zeros, ft_itoa(ft_abs(n)));
	flags.precision = -1;
	count = ft_printstr(flags, count, result);
	free(result);
	return (count);
}
