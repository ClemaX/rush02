/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iel-amra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 19:17:04 by iel-amra          #+#    #+#             */
/*   Updated: 2021/11/06 19:22:02 by iel-amra         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */
#ifndef RUSH02_H
# define RUSH02_H

# define GRID_EMPTY '_'
# define GRID_PLAYER_A 'X'
# define GRID_PLAYER_B 'O'

typedef struct	plt
{
	char		*tab;
	int			x;
	int			y;
	int			score;
	unsigned	win_length;
	unsigned	player_b_starts;
	unsigned	total_time;
	unsigned	time_gain;
}				plateau;

int		setup(plateau *grille);
int		recv_pos(unsigned *x);
int		send_pos(unsigned x);


void	clear_grid(plateau *grille);
void	print_grid(plateau *grille);
int		place(plateau *grille, int x, char player);

int		scorer(plateau grille, plateau grille2, int pos);


#endif
