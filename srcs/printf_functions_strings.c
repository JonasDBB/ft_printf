/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   printf_functions_strings.c                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: jbennink <jbennink@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/22 13:32:57 by jbennink       #+#    #+#                */
/*   Updated: 2019/11/26 18:08:59 by jbennink      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_printchar(t_flags flags, int count, int c)
{
	if (flags.padside == padleft)
		while (flags.minwidth > 1)
		{
			ft_putchar_fd(flags.filler, 1);
			count++;
			flags.minwidth--;
		}
	ft_putchar_fd(c, 1);
	if (flags.padside == padright)
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
	flags.prcsn = (flags.prcsn <= -1) ? (len) : flags.prcsn;
	if (len < flags.prcsn && flags.padside == padleft)
		flags.minwidth += flags.prcsn - len;
	i = 0;
	if (flags.padside == padleft)
		count = ft_padleft(&flags, count);
	while (str[i] && i < flags.prcsn)
	{
		ft_putchar_fd(str[i], 1);
		i++;
	}
	if (flags.padside == padright)
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
	while (flags->minwidth > flags->prcsn)
	{
		ft_putchar_fd(flags->filler, 1);
		count++;
		flags->minwidth--;
	}
	return (count);
}
