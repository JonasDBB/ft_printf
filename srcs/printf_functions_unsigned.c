/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   printf_functions_unsigned.c                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jbennink <jbennink@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/22 14:27:54 by jbennink       #+#    #+#                */
/*   Updated: 2019/11/25 12:03:02 by jbennink      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_u_zeros_fill(t_flags *flags, int len, int n)
{
	int	zeros;

	zeros = 0;
	if ((flags->zerox == WITH_0X && n != 0) || flags->zerox == POINTER_0X)
		flags->minwidth -= 2;
	while (flags->minwidth > len)
	{
		zeros++;
		flags->minwidth--;
	}
	flags->filler = ' ';
	return (zeros);
}

int	ft_u_zeros_prcsn(t_flags *flags, int len)
{
	int	zeros;

	zeros = 0;
	while (flags->prcsn > len)
	{
		zeros++;
		flags->prcsn--;
	}
	flags->prcsn = -1;
	return (zeros);
}

int	ft_u_get_zeros(t_flags *flags, int len, int n)
{
	int	zeros;

	zeros = 0;
	if (flags->prcsn == -1 && flags->filler == '0')
		zeros += ft_u_zeros_fill(flags, len, n);
	if (flags->prcsn < len)
		flags->prcsn = -1;
	if (flags->prcsn > len)
		zeros += ft_u_zeros_prcsn(flags, len);
	if (flags->filler == '0')
		flags->filler = ' ';
	return (zeros);
}

int	ft_printunsg(va_list args, t_flags flags, int base, char capital)
{
	unsigned long	n;
	char			*res;
	int				zeros;
	int				count;

	count = 0;
	n = va_arg(args, unsigned long);
	if (flags.prcsn == 0)
		res = ft_strdup("");
	else
	{
		res = ft_itoabase(n, base, capital);
		zeros = ft_u_get_zeros(&flags, ft_strlen(res), n);
		res = ft_getnbrstr(n, zeros, res);
	}
	if ((flags.zerox == WITH_0X && n != 0) || flags.zerox == POINTER_0X)
	{
		res = (capital <= 'Z') ? ft_strjoin("0X", res) : ft_strjoin("0x", res);
		flags.prcsn = (flags.prcsn < (int)ft_strlen(res)) ? -1 : flags.prcsn;
	}
	if (!res)
		return (-1);
	count = (ft_printstr(flags, count, res));
	free(res);
	return (count);
}

int	ft_printptr(va_list args, t_flags flags, int count)
{
	flags.zerox = POINTER_0X;
	return (count + ft_printunsg(args, flags, 16, 'a'));
}
