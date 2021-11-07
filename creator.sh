# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    header.sh                                          :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: iel-amra <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/04 12:26:33 by iel-amra          #+#    #+#              #
#    Updated: 2021/11/07 12:37:49 by iel-amra         ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

echo "#ifndef RUSH02_H"
echo "# define RUSH02_H"
echo "# include <unistd.h>"
echo "# include <stdlib.h>"
echo ''
echo 'struct	plt
{
	char	*tab;
	int		x;
	int		y;
	int		score;
} typedef plateau;
'
grep -h ^int *.c | sed -e 's/$/;/g' | sed -e 's/^int/int	/g'
grep -h ^char *.c | sed -e 's/$/;/g'
grep -h ^void *.c | sed -e 's/$/;/g'
grep -h ^size_t *.c | sed -e 's/$/;/g'
grep -h ^plateau *.c | sed -e 's/$/;/g'
echo "#endif"
