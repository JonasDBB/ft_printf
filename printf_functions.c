/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   printf_functions.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: jbennink <jbennink@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/06 11:23:11 by jbennink       #+#    #+#                */
/*   Updated: 2019/11/20 10:35:03 by jbennink      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Libft/libft.h"
#include "libftprintf.h"

int		ft_printchar(t_flags flags, int count, int c)
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

int		ft_printstr(t_flags flags, int count, char *str)
{
	int		len;
	int		i;

	len = ft_strlen(str);
	i = 0;
	if (flags.padside == PADLEFT)
		while (flags.minwidth > len)
		{
			ft_putchar_fd(flags.filler, 1);
			count++;
			flags.minwidth--;
		}
	flags.precision = (flags.precision == -1) ? (len) : flags.precision;
	while (str[i] && i < flags.precision)
	{
		ft_putchar_fd(str[i], 1);
		i++;
	}
	if (flags.padside == PADRIGHT)
		while (flags.minwidth > i)
		{
			ft_putchar_fd(flags.filler, 1);
			count++;
			flags.minwidth--;
		}
	return (count + i);
}

int		ft_digits(long n)
{
	int	i;

	i = 0;
	if (n < 0)
	{
		i++;
		n = -n;
	}
	while (n)
	{
		i++;
		n /= 10;
	}
	return (i);
}

int		ft_printnbr(va_list args, t_flags flags, int count)
{
	char	*result;
	int		digits;
	int		n;
	int		zeros;

	n = va_arg(args, int);
	if (flags.precision == -1 && flags.filler == ' ')
	{
		result = (ft_itoa(n));
		return (ft_printstr(flags, count, result));
	}
	digits = ft_digits(n);
	zeros = 0;
	if (flags.precision == -1 && flags.filler == '0')
	{
		while (flags.minwidth > digits)
		{
			zeros++;
			flags.minwidth--;
		}
		result = ft_getnbrstr(n, digits, zeros);
		return (ft_printstr(flags, count, result));
	}
	if (flags.filler == '0')
		flags.filler = ' ';
	if (n < 0)
		digits -= 1;
	while (flags.precision > digits)
	{
		zeros++;
		flags.precision--;
	}
	if (n < 0)
		digits += 1;
	result = ft_getnbrstr(n, digits, zeros);
	flags.precision = -1;
	return (ft_printstr(flags, count, result));
}

char	*ft_getnbrstr(int n, int digits, int zeros)
{
	char	*result;
	int		i;
	char	*nbr;
	int		len;

	len = digits + zeros + 1;
	result = malloc(len);
	i = 0;
	if (n < 0)
	{
		result[0] = '-';
		i++;
		n = -n;
	}
	while (zeros)
	{
		result[i] = '0';
		i++;
		zeros--;
	}
	nbr = ft_itoa(n);
	ft_strlcat(result, nbr, len);
	free(nbr);
	return (result);
}

int		ft_printhex(va_list args, t_flags flags, int count, char capital)
{
	unsigned long	n;
	char			*result;

	n = va_arg(args, unsigned long);
	result = ft_itoabase(n, 16, capital);
	return (ft_printstr(flags, count, result));
}

char	*ft_itoabase(unsigned long n, int base, char capital)
{
	char	*result;
	int		i;
	char	c;

	i = ft_digits(n);
	result = malloc(i + 1);
	if (!result)
		return (NULL);
	result[i] = '\0';
	i--;
	while (n)
	{
		c = ft_getchar(n % base, capital, base);
		result[i] = c;
		n /= base;
		i--;
	}
	return (result);
}

char	ft_getchar(unsigned long n, char capital, int base)
{
	if (n < 10)
		return (n + '0');
	if (capital >= 'A' && capital <= 'Z')
		return (n + 'A' - 10);
	return (n + 'a' - 10);
}
