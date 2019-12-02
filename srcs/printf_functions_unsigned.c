/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   printf_functions_unsigned.c                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jbennink <jbennink@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/22 14:27:54 by jbennink       #+#    #+#                */
/*   Updated: 2019/12/02 16:53:18 by jbennink      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_u_zeros_fill(t_flags *flags, int len, int n)
{
	int	zeros;

	zeros = 0;
	if ((flags->zerox == with_0x && n != 0) || flags->zerox == pointer_0x)
		flags->minwidth -= 2;
	while (flags->minwidth > len)
	{
		zeros++;
		flags->minwidth--;
	}
	flags->filler = ' ';
	return (zeros);
}

int		ft_u_zeros_prcsn(t_flags *flags, int len)
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

int		ft_u_get_zeros(t_flags *flags, int len, int n)
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

int		ft_printunsg(va_list args, t_flags flags, int base, char capital)
{
	unsigned int	n;
	char			*rs;
	int				zeros;
	int				count;

	count = 0;
	n = va_arg(args, unsigned int);
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

char	*ft_strjoin2(char const *s1, char **s2)
{
	char	*result;
	int		i;
	int		j;

	if (!s1 || !(*s2))
		return (NULL);
	result = malloc(ft_strlen(s1) + ft_strlen(*s2) + 1);
	if (!result)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i])
	{
		result[i] = s1[i];
		i++;
	}
	while ((*s2)[j])
	{
		result[i] = (*s2)[j];
		j++;
		i++;
	}
	free(*s2);
	result[i] = '\0';
	return (result);
}
