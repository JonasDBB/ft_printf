/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   printf_functions_signed.c                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: jbennink <jbennink@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/22 14:14:24 by jbennink       #+#    #+#                */
/*   Updated: 2019/11/25 12:04:41 by jbennink      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_zero_prcsn(t_flags flags, int count)
{
	char	*result;

	result = ft_strdup("");
	if (!result)
		return (-1);
	count = ft_printstr(flags, count, result);
	free(result);
	return (count);
}

int	ft_regular_fill(t_flags flags, int count, int n)
{
	char	*result;

	result = ft_itoa(n);
	if (!result)
		return (-1);
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
	if (!result)
		return (-1);
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
	if (flags.prcsn == 0)
		return (ft_zero_prcsn(flags, count));
	if (flags.prcsn == -1 && flags.filler == ' ')
		return (ft_regular_fill(flags, count, n));
	zeros = 0;
	if (flags.prcsn == -1 && flags.filler == '0')
		return (ft_zeros_fill(flags, count, n));
	flags.filler = ' ';
	while (flags.prcsn > ft_digits(ft_abs(n), 10))
	{
		zeros++;
		flags.prcsn--;
	}
	result = ft_getnbrstr(n, zeros, ft_itoa(ft_abs(n)));
	if (!result)
		return (-1);
	flags.prcsn = -1;
	count = ft_printstr(flags, count, result);
	free(result);
	return (count);
}
