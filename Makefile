# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: iel-amra <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/05 13:22:25 by iel-amra          #+#    #+#              #
#    Updated: 2021/11/06 21:04:23 by iel-amra         ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

NAME=rush02
SRC=$(wildcard *.c)
OBJ=$(SRC:.c=.o)

$(NAME) : $(OBJ)
	gcc -o $(NAME) $(OBJ)

%o : %c
	gcc -c -Werror -Wall -Wextra $<

clean :
	rm -f *.o

fclean : clean
	rm -f $(NAME)

re : fclean $(NAME)

.SUFFIXES:
