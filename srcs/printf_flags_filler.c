/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   printf_flags_filler.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: jbennink <jbennink@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/22 12:25:16 by jbennink       #+#    #+#                */
/*   Updated: 2019/11/22 16:41:54 by jbennink      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_flags_minus(t_flags *flags)
{
	flags->filler = ' ';
	flags->padside = PADRIGHT;
	return (1);
}

int	ft_flags_wildcard(t_flags *flags, va_list args)
{
	int	i;

	i = 0;
	flags->minwidth = va_arg(args, int);
	i++;
	if (flags->minwidth < 0)
	{
		ft_flags_minus(flags);
		flags->minwidth *= -1;
	}
	return (i);
}

int	ft_flags_precision(t_flags *flags, va_list args, int i)
{
	i++;
	flags->precision = 0;
	if (flags->flagstr[i] == '*')
	{
		flags->precision = va_arg(args, int);
		i++;
	}
	else
		while (ft_isdigit(flags->flagstr[i]))
		{
			flags->precision = flags->precision * 10 + flags->flagstr[i] - '0';
			i++;
		}
	return (i);
}

int	ft_flags_hashtag(t_flags *flags)
{
	flags->zerox = WITH_0X;
	return (1);
}

int	ft_flags_zero(t_flags *flags)
{
	flags->filler = '0';
	return (1);
}
