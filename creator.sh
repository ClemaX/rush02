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

echo '#ifndef RUSH02_H'
echo '# define RUSH02_H'
echo ''
echo '# include <unistd.h>'
echo '# include <stdlib.h>'
echo ''
echo '# include "logger.h"'
echo ''
echo "# define GRID_EMPTY '_'"
echo "# define GRID_PLAYER_A 'X'"
echo "# define GRID_PLAYER_B 'O'"
echo ''
echo '# define TURN_PLAYER_A 1'
echo '# define TURN_PLAYER_B 2'
echo ''
echo '# define BLOB_RESOLUTION 3'
echo ''
echo 'typedef struct
{
	char	*tab;
	int		x;
	int		y;
	int		score;
	unsigned	win_length;
	unsigned	player_turn;
	unsigned	total_time;
	unsigned	time_gain;
}		plateau;
'
echo ''
(grep -h ^int *.c | sed -e 's/$/;/g' | sed -e 's/^int/int	/g'
grep -h ^char *.c | sed -e 's/$/;/g'
grep -h ^void *.c | sed -e 's/$/;/g'
grep -h ^size_t *.c | sed -e 's/$/;/g'
grep -h ^plateau *.c | sed -e 's/$/;/g')
echo ''
echo "#endif"
