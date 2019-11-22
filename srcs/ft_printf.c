/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jbennink <jbennink@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/04 15:40:05 by jbennink       #+#    #+#                */
/*   Updated: 2019/11/22 16:24:33 by jbennink      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_printarg(char **traverse, va_list args, int count)
{
	t_flags	flags;

	ft_processflags(&(*traverse), args, &flags);
	if (!**traverse)
		return (count);
	if (**traverse == 'c')
		count = ft_printchar(flags, count, va_arg(args, int));
	else if (**traverse == 's')
		count = ft_printstr(flags, count, va_arg(args, char*));
	else if (**traverse == 'x' || **traverse == 'X')
		count += ft_printunsg(args, flags, 16, **traverse);
	else if (**traverse == 'd' || **traverse == 'i')
		count = ft_printnbr(args, flags, count);
	else if (**traverse == 'u')
		count += ft_printunsg(args, flags, 10, 'a');
	else if (**traverse == 'p')
		count = ft_printptr(args, flags, count);
	else if (**traverse == '%')
		count = ft_printchar(flags, count, '%');
	(*traverse)++;
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	char	*traverse;
	int		count;

	traverse = (char*)format;
	va_start(args, format);
	count = 0;
	while (*traverse)
	{
		while (*traverse != '%' && *traverse)
		{
			ft_putchar_fd(*traverse, 1);
			traverse++;
			count++;
		}
		if (!*traverse)
			break ;
		traverse++;
		count = ft_printarg(&traverse, args, count);
	}
	va_end(args);
	return (count);
}
