/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   printf_functions_strings.c                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: jbennink <jbennink@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/22 13:32:57 by jbennink       #+#    #+#                */
/*   Updated: 2019/11/22 16:26:44 by jbennink      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_printchar(t_flags flags, int count, int c)
{
	if (flags.padside == PADLEFT)
		while (flags.minwidth > 1)
		{
			ft_putchar_fd(flags.filler, 1);
			count++;
			flags.minwidth--;
		}
	ft_putchar_fd(c, 1);
	if (flags.padside == PADRIGHT)
		while (flags.minwidth > 1)
		{
			ft_putchar_fd(flags.filler, 1);
			count++;
			flags.minwidth--;
		}
	return (count + 1);
}

int	ft_printstr(t_flags flags, int count, char *str)
{
	int		len;
	int		i;

	if (!str)
		return (ft_emptystr(flags, count));
	len = ft_strlen(str);
	flags.precision = (flags.precision == -1) ? (len) : flags.precision;
	if (len < flags.precision && flags.padside == PADLEFT)
		flags.minwidth += flags.precision - len;
	i = 0;
	if (flags.padside == PADLEFT)
		count = ft_padleft(&flags, count);
	while (str[i] && i < flags.precision)
	{
		ft_putchar_fd(str[i], 1);
		i++;
	}
	if (flags.padside == PADRIGHT)
		count = ft_padright(&flags, count, i);
	return (count + i);
}

int	ft_emptystr(t_flags flags, int count)
{
	char	*str;

	str = ft_strdup("(null)");
	count = ft_printstr(flags, count, str);
	free(str);
	return (count);
}

int	ft_padright(t_flags *flags, int count, int i)
{
	while (flags->minwidth > i)
	{
		ft_putchar_fd(flags->filler, 1);
		count++;
		flags->minwidth--;
	}
	return (count);
}

int	ft_padleft(t_flags *flags, int count)
{
	while (flags->minwidth > flags->precision)
	{
		ft_putchar_fd(flags->filler, 1);
		count++;
		flags->minwidth--;
	}
	return (count);
}
