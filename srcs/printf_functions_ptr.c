/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   printf_functions_ptr.c                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: jbennink <jbennink@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/02 16:44:45 by jbennink       #+#    #+#                */
/*   Updated: 2019/12/02 16:49:18 by jbennink      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_printunsglong(va_list args, t_flags flags, int base, char capital)
{
	unsigned long	n;
	char			*rs;
	int				zeros;
	int				count;

	count = 0;
	n = va_arg(args, unsigned long);
	if (flags.prcsn == 0 && n == 0)
		rs = ft_strdup("");
	else
	{
		rs = ft_itoabase(n, base, capital);
		zeros = ft_u_get_zeros(&flags, ft_strlen(rs), n);
		rs = ft_getnbrstr(n, zeros, rs);
	}
	if ((flags.zerox == with_0x && n != 0) || flags.zerox == pointer_0x)
	{
		rs = (capital <= 'Z') ? ft_strjoin2("0X", &rs) : ft_strjoin2("0x", &rs);
		flags.prcsn = (flags.prcsn < (int)ft_strlen(rs)) ? -1 : flags.prcsn;
	}
	if (!rs)
		return (-1);
	count = (ft_printstr(flags, count, rs));
	free(rs);
	return (count);
}

int	ft_printptr(va_list args, t_flags flags, int count)
{
	flags.zerox = pointer_0x;
	return (count + ft_printunsglong(args, flags, 16, 'a'));
}
