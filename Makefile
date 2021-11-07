# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: iel-amra <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/05 13:22:25 by iel-amra          #+#    #+#              #
#    Updated: 2021/11/07 12:30:27 by iel-amra         ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

NAME=rush02
SRC=$(wildcard *.c)
OBJ=$(SRC:.c=.o)
HDR=rush02.h

CFLAGS=-Werror -Wall -Wextra
LDFLAGS=-Werror -Wall -Wextra

$(NAME) : $(OBJ)
	gcc $(LDFLAGS) -o $(NAME) $(OBJ)

debug: CFLAGS+=-DDEBUG
debug: fclean $(NAME)

%o : %c $(HDR)
	gcc -c $(CFLAGS) $<

clean :
	rm -f *.o

fclean : clean
	rm -f $(NAME)

re : fclean $(NAME)

.SUFFIXES:

.PHONY: debug clean fclean re
