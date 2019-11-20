# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: jbennink <jbennink@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2019/11/06 10:19:54 by jbennink       #+#    #+#                 #
#    Updated: 2019/11/06 12:10:46 by jbennink      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

LIBNAME = Libft.a

FLAGS = -Wall -Wextra -Werror

SRCS = ft_printf.c printf_functions.c

OBJS = $(SRCS:.c=.o)

all: library $(NAME)

$(NAME):
	gcc $(FLAGS) -c $(SRCS)
	ar rc $(NAME) libft/$(LIBNAME) $(OBJS)

clean:
	rm -f $(OBJS)
	cd libft && $(MAKE) clean

fclean:	clean
	rm -f $(NAME)
	cd libft && $(MAKE) fclean

re: fclean all

library:
	cd libft && $(MAKE) all
