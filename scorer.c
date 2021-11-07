/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scorer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iel-amra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 17:55:12 by iel-amra          #+#    #+#             */
/*   Updated: 2021/11/06 20:43:47 by iel-amra         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"
#include "libft.h"

int	void_sniper(plateau grille, int pos, int i, int j)
{
	int		x;
	int		y;
	char	joueur2;


	joueur2 = 9 - (int)grille.tab[pos] + 158; // Inverse le code ascii des caracteres
	y = pos / grille.x;
	x = pos % grille.x;
	while (x + i < grille.x && x + i >= 0 && y + j < grille.y && y + j >= 0 
			&& grille.tab[(y + j) * grille.x + x + i] != joueur2)

	{
		x += i;
		y += j;
	}
	return (grille.x - x);
}

int	score_jeton(plateau grille, int pos)
{
	int	x;
	int	y;

	y = pos / grille.x;
	x = pos % grille.x;

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
