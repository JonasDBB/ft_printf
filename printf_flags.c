/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   printf_flags.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: jbennink <jbennink@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/14 13:45:24 by jbennink       #+#    #+#                */
/*   Updated: 2019/11/19 16:59:12 by jbennink      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Libft/libft.h"
#include "libftprintf.h"

void	ft_setnewflags(int size, t_flags *flags)
{
	flags->flagstr = (char*)ft_calloc(size + 1, 1);
	flags->minwidth = 0;
	flags->filler = ' ';
	flags->precision = -1;
	flags->padside = PADLEFT;
}

void	ft_processflags(char **traverse, va_list args, t_flags *flags)
{
	int		i;

	i = 0;
	while (ft_strchr("0123456789-*.", (*traverse)[i]))
		i++;
	ft_setnewflags(i, flags);
	i = 0;
	while (ft_strchr("0123456789-*.", **traverse))
	{
		flags->flagstr[i] = **traverse;
		i++;
		(*traverse)++;
	}
	ft_fillflags(flags, args);
	free(flags->flagstr);
}

void	ft_fillflags(t_flags *flags, va_list args)
{
	int	i;

	i = 0;
	while (flags->flagstr[i])
	{
		if (flags->flagstr[i] == '-')
		{
			flags->filler = ' ';
			flags->padside = PADRIGHT;
			i++;
		}
		if (flags->flagstr[i] == '*')
		{
			flags->minwidth = va_arg(args, int);
			i++;
		}
		if (flags->flagstr[i] == '.')
		{
			i++;
			flags->precision = 0;
			while (ft_isdigit(flags->flagstr[i]))
			{
				flags->precision = flags->precision * 10 + (flags->flagstr[i] - '0');
				i++;
			}
		}
		if (flags->flagstr[i] == '0' && flags->padside != PADRIGHT)
		{
			flags->filler = '0';
			i++;
		}
		while (ft_isdigit(flags->flagstr[i]))
		{
			flags->minwidth = flags->minwidth * 10 + (flags->flagstr[i] - '0');
			i++;
		}
	}
}
