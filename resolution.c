/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolution.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iel-amra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 10:52:06 by iel-amra          #+#    #+#             */
/*   Updated: 2021/11/07 14:29:42 by iel-amra         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

plateau	init_plat(int x, int y)
{
		plateau grille;
		grille.x = x;
		grille.y = y;
		grille.tab = malloc((x * y + 1) * sizeof(char));
		grille.tab[x * y] = '\0'; 
		ft_memset(grille.tab, '_', x * y);
		return (grille);
}

plateau	clone(plateau grille)
{
	plateau	grille2;

	grille2 = grille;
	grille2.tab = ft_strdup(grille.tab);
	return (grille2);
}

int	init_score_pref(char joueur)
{
	int	score_pref;

	if (joueur == 'X')
		score_pref = -2147483648;
	else
		score_pref = 2147483647;
	return (score_pref);
}
/*
int	blob(plateau grille, char joueur, int coups)
{
	int		i;
	int		score;
	int 	score_pref;
	char	joueur2;
	plateau	grille2;

	i = 0;
	score_pref = init_score_pref(joueur);
	joueur2 = 167 - (int)joueur; // Inverse le cod ascii des caracteres
	while (i < grille.x)
	{
		if (coups > 1)
		{
			grille2 = clone(grille);
			if (placable(i, grille2))
				placer(i, grille2, joueur);
			score = blob(grille2, joueur2, coups - 1);
			free(grille2.tab);
		}
		else
			score = get_score(grille, grille2, i);
		i++;

		if (joueur == 'X' && score_pref < score)
			score_pref = score;
		if (joueur == 'O' && score_pref > score)
			score_pref = score;
	}
	return (score_pref);
} */
