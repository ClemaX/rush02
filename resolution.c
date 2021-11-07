/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolution.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iel-amra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 10:52:06 by iel-amra          #+#    #+#             */
/*   Updated: 2021/11/07 20:34:42 by iel-amra         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"
#include <limits.h>

/* 
plateau	init_plat(int x, int y)
{
		plateau grille;
		grille.x = x;
		grille.y = y;
		grille.score = 0;
		grille.tab = malloc((x * y + 1) * sizeof(char));
		grille.tab[x * y] = '\0'; 
		ft_memset(grille.tab, '_', x * y);
		return (grille);
} */

plateau	clone(plateau grille)
{
	plateau	grille2;

	grille2 = grille;
	grille2.tab = ft_strdup(grille.tab);
	return (grille2);
}

int	init_score_pref(char joueur2)
{
	int	score_pref;

	if (joueur2 == 'X')
		score_pref = INT_MIN;
	else
		score_pref = INT_MAX;
	return (score_pref);
}

int	blob(plateau grille, char joueur, int coups, int n)
{
	int		i;
	int		pos;
	int		score;
	int 	score_pref;
	char	joueur2;
	plateau	grille2;

	grille2 = clone(grille);
	pos = place(&grille2, n, joueur);
	if (pos != -1)
		grille2.score = scorer(grille, grille2, pos);
	else
		return (-4000000);
	if (grille2.score > 1000000)
		return (grille.score - 10);
	else if (grille.score < -1000000)
		return (grille.score + 10);
	i = 0;
	joueur2 = 167 - (int)joueur; // Inverse le code ascii des caracteres
	score_pref = init_score_pref(joueur2);
	while (i < grille.x && coups > 0)
	{	
		score = blob(grille2, joueur2, coups - 1, i);
		if (joueur2 == 'X' && score_pref < score)
			score_pref = score;
		if (joueur2 == 'O' && score_pref > score)
			score_pref = score;
		i++;
	}
	if (coups == 0)
		return (grille2.score);
	return (score_pref);
}
