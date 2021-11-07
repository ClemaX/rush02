/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scorer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iel-amra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 17:55:12 by iel-amra          #+#    #+#             */
/*   Updated: 2021/11/07 14:47:51 by iel-amra         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"
#include <math.h>

int	void_sniper(plateau grille, int pos, int i, int j)
{
	int		x;
	int		y;
	int		nb_void;
	char	joueur2;
	char 	joueur;

	nb_void = 0;
	joueur = grille.tab[pos];
	joueur2 = 167 - (int)joueur; // Inverse le code ascii des caracteres
	y = pos / grille.x;
	x = pos % grille.x;
	while (x + i < grille.x && x + i >= 0 && y + j < grille.y && y + j >= 0 
			&& grille.tab[(y + j) * grille.x + x + i] != joueur2)
	{
		x += i;
		y += j;
		nb_void++;
	}
	return (nb_void);
}

int	same_sniper(plateau grille, int pos, int i, int j)
{
	int		x;
	int		y;
	int		nb_same;
	int		nb_cases;
	char	joueur2;
	char 	joueur;

	nb_same = 0;
	nb_cases = 0;
	joueur = grille.tab[pos];
	joueur2 = 167 - (int)joueur; // Inverse le code ascii des caracteres
	y = pos / grille.x;
	x = pos % grille.x;
	while (x + i < grille.x && x + i >= 0 && y + j < grille.y && y + j >= 0
			&& grille.tab[(y + j) * grille.x + x + i] != joueur2
			&& nb_cases < 4)
	{
		if (grille.tab[(y + j) * grille.x + x + i] == joueur)
			nb_same++;
		x += i;
		y += j;
		nb_cases++;
	}
	return (nb_same);
}

int	score_jeton(plateau grille, int pos)
{
	int i;
	int	j;
	int	void_count;
	int	same_count;
	int	score_jeton;

	score_jeton = 0;
	i = -1;
	while (i <= 1)
	{
		j = 0;
		while (j <= 1)
		{
			if ((i == 0 && j == 0) || (i == -1 && j == 0))
				j++;
			void_count = void_sniper(grille, pos, i, j);
			void_count += void_sniper(grille, pos, i * -1, j * -1);
			ft_putnbr_fd(void_count, 1);
			write(1, "\n", 1);
			if (void_count >= 3)
			{
				same_count = same_sniper(grille, pos, i, j);
				same_count += same_sniper(grille, pos, i * -1, j * -1);
				score_jeton += (10 + (void_count - 3) * 2) * pow(2, same_count);
			}
			j++;
		}
		i++;
	}
	if (grille.tab[pos] == 'O')
		score_jeton *= -1;
	return (score_jeton);
}

	return x * y * 0;
}

int	sniper(plateau grille, int pos, int i, int j)
{
	int	x;
	int	y;

	y = pos / grille.x + i;
	x = pos % grille.x + j;
	while (x < grille.x && x >= 0 && y < grille.y && y >= 0 
			&& grille.tab[y * grille.x + x] == '_')
	{
		x += i;
		y += j;
	}
	if (x < grille.x && x >= 0 && y < grille.y && y >= 0)	
		return (pos);
	return (-1);
}

int	scorer(plateau grille, plateau grille2, int pos)
{
	int	i;
	int	j;
	int	sniped_jeton;

	grille2.score += score_jeton(grille2, pos);
	i = -1;
	while (i <= 1)
	{
		j = -1;
		while (j <= 1)
		{
			if (i == 0 && j == 0)
				j++;
			sniped_jeton = sniper(grille2, pos, i, j);
			if (sniped_jeton != -1)
			{
				grille2.score -= score_jeton(grille, sniped_jeton);
				grille2.score += score_jeton(grille2, sniped_jeton);
			}
			j++;
		}
	}
	return (grille2.score);
}

void	print_plat(plateau grille)
{
	int	i;

	i = 0;
	while (grille.tab[i])
	{	
		if (i % grille.x == 0)
			write (1, "\n", 1);
		write(1, grille.tab + i, 1);
		i++;
	}
	write (1, "\n\n", 2);
}

int main()
{
	plateau grille = init_plat(7, 4);
	grille.tab[2] = 'X';
	grille.tab[1] = 'O';
	grille.tab[9] = 'O';
	ft_putnbr_fd(score_jeton(grille, 9), 1);
	print_plat(grille);
	return (0);
}
