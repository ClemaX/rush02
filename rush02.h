/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iel-amra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 19:17:04 by iel-amra          #+#    #+#             */
/*   Updated: 2021/11/07 16:50:24 by chamada          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */
#ifndef RUSH02_H
# define RUSH02_H

# define GRID_EMPTY '_'
# define GRID_PLAYER_A 'X'
# define GRID_PLAYER_B 'O'

# define BLOB_RESOLUTION 3

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
int		recv_pos(int *x);
int		send_pos(int x);

int		blob(plateau grille, char joueur, int coups);

void	clear_grid(plateau *grille);
void	print_grid(plateau *grille);
int		place(plateau *grille, int x, char player);
int		unplace(plateau *grille, int x);

int		scorer(plateau grille, plateau grille2, int pos);


#endif
