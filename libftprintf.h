/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   libftprintf.h                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: jbennink <jbennink@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/06 11:24:42 by jbennink       #+#    #+#                */
/*   Updated: 2019/11/20 10:20:49 by jbennink      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H
# include <stdarg.h>
# include <stdlib.h>
# include <stdio.h>
# define PADLEFT 1
# define PADRIGHT 0

typedef struct	s_flagset
{
	char	*flagstr;
	int		minwidth;
	char	filler;
	int		precision;
	int		padside;
}				t_flags;

int				ft_printf(const char *format, ...);
void			ft_fillflags(t_flags *flags, va_list args);
void			ft_processflags(char **traverse, va_list args, t_flags *flags);
void			ft_setnewflags(int size, t_flags *flags);
int				ft_printarg(char **traverse, va_list args, int count);
int				ft_printchar(t_flags flags, int count, int c);
int				ft_printstr(t_flags flags, int count, char *str);
int				ft_printnbr(va_list args, t_flags flags, int count);
int				ft_digits(long n);
char			*ft_getnbrstr(int n, int digits, int zeros);
int				ft_printhex(va_list args, t_flags flags, int count, char capital);
char			*ft_itoabase(unsigned long n, int base, char capital);
char			ft_getchar(unsigned long n, char capital, int base);

#endif
