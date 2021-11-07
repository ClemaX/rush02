/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolution.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iel-amra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 10:52:06 by iel-amra          #+#    #+#             */
/*   Updated: 2021/11/06 20:15:35 by iel-amra         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"
#include "libft.h"
#include <limits.h>
/* 
plateau	init_tab(char *tab, int x, int y)
{
		plateau grille;
		grille.x = x;
		grille.y = y;
		grille.tab = malloc((x * y + 1) * sizeof(char));
		grille.tab[x * y] = '\0'; 
		ft_memset(grille.tab, '_', y);
		return (grille);
} */

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
		score_pref = INT_MIN;
	else
		score_pref = INT_MAX;
	return (score_pref);
}

int	blob(plateau grille, char joueur, int coups)
{
	int		i;
	int		score;
	int 	score_pref;
	char	joueur2;
	plateau	grille2;

	i = 0;
	score_pref = init_score_pref(joueur);
	joueur2 = 9 - (int)joueur + 158; // Inverse le cod ascii des caracteres
	while (i < grille.x)
	{
		if (coups > 1)
		{
			grille2 = clone(grille);
			place(&grille2, i, joueur);
			score = blob(grille2, joueur2, coups - 1);
			free(grille2.tab);
		}
		else
			score = scorer(grille, grille2, i);
		i++;

		if (joueur == 'X' && score_pref < score)
			score_pref = score;
		if (joueur == 'O' && score_pref > score)
			score_pref = score;
	}
	return (score_pref);
}
