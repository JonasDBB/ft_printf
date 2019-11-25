/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   printf_flags.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: jbennink <jbennink@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/14 13:45:24 by jbennink       #+#    #+#                */
/*   Updated: 2019/11/25 12:03:02 by jbennink      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_setnewflags(int size, t_flags *flags)
{
	flags->flagstr = (char*)ft_calloc(size + 1, 1);
	flags->minwidth = 0;
	flags->filler = ' ';
	flags->prcsn = -1;
	flags->padside = PADLEFT;
	flags->zerox = NO_0X;
}

int		ft_processflags(char **traverse, va_list args, t_flags *flags)
{
	int		i;

	i = 0;
	while (ft_strchr("0123456789-*.#", (*traverse)[i]) && (*traverse)[i])
		i++;
	ft_setnewflags(i, flags);
	if (!flags->flagstr)
		return (-1);
	i = 0;
	while (ft_strchr("0123456789-*.#", **traverse) && **traverse)
	{
		flags->flagstr[i] = **traverse;
		i++;
		(*traverse)++;
	}
	ft_fillflags(flags, args);
	free(flags->flagstr);
	return (1);
}

void	ft_fillflags(t_flags *flags, va_list args)
{
	int	i;

	i = 0;
	while (flags->flagstr[i])
	{
		if (flags->flagstr[i] == '-')
			i += ft_flags_minus(flags);
		if (flags->flagstr[i] == '*')
			i += ft_flags_wildcard(flags, args);
		if (flags->flagstr[i] == '.')
			i = ft_flags_prcsn(flags, args, i);
		if (flags->flagstr[i] == '#')
			i += ft_flags_hashtag(flags);
		if (flags->flagstr[i] == '0' && flags->padside != PADRIGHT)
			i += ft_flags_zero(flags);
		while (ft_isdigit(flags->flagstr[i]))
		{
			flags->minwidth = flags->minwidth * 10 + (flags->flagstr[i] - '0');
			i++;
		}
	}
}
