/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   printf_flags.h                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: jbennink <jbennink@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/22 12:26:34 by jbennink       #+#    #+#                */
/*   Updated: 2019/11/22 16:29:58 by jbennink      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_FLAGS_H
# define LIBFTPRINTF_FLAGS_H
# include "libftprintf.h"
# define PADLEFT 0
# define PADRIGHT 1
# define NO_0X 2
# define WITH_0X 3
# define POINTER_0X 4

typedef struct	s_flagset
{
	char	*flagstr;
	int		minwidth;
	char	filler;
	int		precision;
	int		padside;
	int		zerox;
}				t_flags;

void			ft_fillflags(t_flags *flags, va_list args);
void			ft_processflags(char **traverse, va_list args, t_flags *flags);
void			ft_setnewflags(int size, t_flags *flags);
int				ft_flags_minus(t_flags *flags);
int				ft_flags_wildcard(t_flags *flags, va_list args);
int				ft_flags_precision(t_flags *flags, va_list args, int i);
int				ft_flags_hashtag(t_flags *flags);
int				ft_flags_zero(t_flags *flags);

#endif
