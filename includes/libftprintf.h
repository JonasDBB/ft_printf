/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   libftprintf.h                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: jbennink <jbennink@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/06 11:24:42 by jbennink       #+#    #+#                */
/*   Updated: 2019/11/28 11:30:05 by jbennink      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H
# include <stdarg.h>
# include <stdlib.h>
# include "printf_flags.h"
# include "printf_functions_strings.h"
# include "printf_functions_numbers.h"
# include "../libft/libft.h"

int	ft_printf(const char *format, ...);
int	ft_printarg(char **traverse, va_list args, int count);

#endif
