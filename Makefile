# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: jbennink <jbennink@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2019/11/06 10:19:54 by jbennink       #+#    #+#                 #
#    Updated: 2019/11/25 12:40:36 by jbennink      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

LIBNAME = libft.a

FLAGS = -Wall -Wextra -Werror

SRCSPATH = srcs/

INCLUDES = includes/

SRCS = ft_printf.c \
printf_flags.c \
printf_flags_filler.c \
printf_functions_strings.c \
printf_functions_signed.c \
printf_functions_unsigned.c \
printf_functions_aux.c

OBJS = $(SRCS:.c=.o)

.PHONY: all clean fclean re library

all: library $(NAME)

%.o: $(SRCSPATH)%.c
	gcc $(FLAGS) -I $(INCLUDES) -c $<

$(NAME): $(OBJS)
	cp libft/$(LIBNAME) $(NAME)
	ar rcs $(NAME) $?

clean:
	rm -f $(OBJS)
	cd libft && $(MAKE) clean

fclean:	clean
	rm -f $(NAME)
	cd libft && $(MAKE) fclean

re: fclean all

library:
	cd libft && $(MAKE) all
