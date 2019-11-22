/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   printf_functions.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: jbennink <jbennink@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/06 11:23:11 by jbennink       #+#    #+#                */
/*   Updated: 2019/11/22 16:16:08 by jbennink      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_digits(long n, int base)
{
	int	i;

	i = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		i++;
		n = -n;
	}
	while (n)
	{
		i++;
		n /= base;
	}
	return (i);
}

int		ft_abs(int i)
{
	if (i < 0)
		return (-i);
	return (i);
}

char	*ft_getnbrstr(long long n, int zeros, char *nbr)
{
	char	*result;
	char	*nulls;
	int		i;

	nulls = malloc(zeros + 1);
	i = 0;
	if (n < 0)
	{
		nulls[0] = '-';
		i++;
		n = -n;
	}
	while (zeros)
	{
		nulls[i] = '0';
		i++;
		zeros--;
	}
	result = ft_strjoin(nulls, nbr);
	free(nbr);
	free(nulls);
	return (result);
}

char	*ft_itoabase(unsigned long n, int base, char capital)
{
	char	*result;
	int		i;
	char	c;

	i = ft_digits(n, base);
	result = malloc(i + 1);
	if (!result)
		return (NULL);
	result[i] = '\0';
	i--;
	if (n == 0)
		return (ft_strdup("0"));
	while (n)
	{
		c = ft_getchar(n % base, capital);
		result[i] = c;
		n /= base;
		i--;
	}
	return (result);
}

char	ft_getchar(unsigned long n, char capital)
{
	if (n < 10)
		return (n + '0');
	if (capital >= 'A' && capital <= 'Z')
		return (n + 'A' - 10);
	return (n + 'a' - 10);
}
