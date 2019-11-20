/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jbennink <jbennink@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/04 15:40:05 by jbennink       #+#    #+#                */
/*   Updated: 2019/11/20 10:35:10 by jbennink      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Libft/libft.h"
#include "libftprintf.h"

int		ft_printarg(char **traverse, va_list args, int count)
{
	t_flags	flags;
	
	ft_processflags(&(*traverse), args, &flags);
	if (**traverse == 'c')
		count = ft_printchar(flags, count, va_arg(args, int));
	else if (**traverse == 's')
		count = ft_printstr(flags, count, va_arg(args, char*));
	else if (**traverse == 'x' || **traverse == 'X')
		count = ft_printhex(args, flags, count, **traverse);
	else if (**traverse == 'd' || **traverse == 'i')
		count = ft_printnbr(args, flags, count);
	// else if (**traverse == 'u')
	// 	count = ft_printunbr(args, flags, count);
	// else if (**traverse == 'p')
	// 	count = ft_printptr(args, flags, count);
	else if (**traverse == '%')
		count = ft_printchar(flags, count, '%');
	(*traverse)++;
	return (count);
}

int		ft_printf(const char *format, ...)
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

int	main(void)
{
	int ft_print;
	int print;

	/* STRING & CHAR & % */

	// const char s[] = "howdy";
	// char c = 'c';

	// printf("\n\t__ft_print__\n");
	// ft_print = ft_printf("string:\t%234s\nchar: %5c\npercent: %%\n", s, c);
	// printf("\n\t __print__\n");
	// print = printf("string:\t%234s\nchar: %5c\npercent: %%\n", s, c);
	// printf("\nreturn values:\nft_print: %i\nprint:\t  %i\n", ft_print, print);
	// printf ("\n");

	/* I & D & U & SPACES & +ES */
	
	int i = -45;
	
	printf("\t__ft_print__\n");
	ft_print = ft_printf ("x: %x\nX: %X\n", i, i);
	printf("\n\t __print__\n");
	print = printf ("x: %x\nX: %X\n", i, i);
	printf("return values:\nft_print: %i\nprint:\t  %i\n", ft_print, print);

	/* POINTER */

	// printf("ft_print:\n");
	// ft_print = ft_printf("%p\n", &c);
	// printf("print:\n");
	// print = printf("%p\n", &c);
	// printf("return values:\nft_print: %i\nprint:\t  %i\n", ft_print, print);
	// return (1);
}
