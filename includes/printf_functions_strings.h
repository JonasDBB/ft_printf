/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   printf_functions_strings.h                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: jbennink <jbennink@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/22 13:34:14 by jbennink       #+#    #+#                */
/*   Updated: 2019/11/22 13:44:56 by jbennink      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_FUNCTIONS_STRINGS_H
# define PRINTF_FUNCTIONS_STRINGS_H
# include "libftprintf.h"

int	ft_printchar(t_flags flags, int count, int c);
int	ft_printstr(t_flags flags, int count, char *str);
int	ft_emptystr(t_flags flags, int count);
int	ft_padright(t_flags *flags, int count, int i);
int	ft_padleft(t_flags *flags, int count);

#endif
