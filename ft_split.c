/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iel-amra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 14:52:19 by iel-amra          #+#    #+#             */
/*   Updated: 2021/11/05 20:27:09 by iel-amra         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	nb_mots(char const *s, char c)
{
	int	nb_m;

	nb_m = 0;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s)
			nb_m++;
		while (*s && *s != c)
			s++;
	}
	return (nb_m);
}

int	*nb_lettres(char const *s, char c, int nb_m)
{
	int	i;
	int	*nb_l;

	i = 0;
	nb_l = malloc((nb_m) * sizeof(int));
	if (nb_l == (void *) 0)
		return ((void *) 0);
	while (i < nb_m)
	{
		nb_l[i] = 0;
		while (*s == c)
			s++;
		while (*s && *s != c)
		{
			nb_l[i]++;
			s++;
		}
		i++;
	}
	return (nb_l);
}

void	fill_tab(char const *s, char c, char **tab, int nb_m)
{
	int		i;
	int		j;

	i = 0;
	while (i < nb_m)
	{
		while (*s == c)
			s++;
		j = 0;
		while (*s && *s != c)
		{
			tab[i][j] = *s;
			s++;
			j++;
		}
		tab[i][j] = '\0';
		i++;
	}
	tab[i] = (void *) 0;
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		*nb_l;
	int		nb_m;
	char	**tab;

	if (!s)
		return ((void *) 0);
	i = 0;
	nb_m = nb_mots(s, c);
	nb_l = nb_lettres(s, c, nb_m);
	tab = malloc((nb_m + 1) * sizeof(char *));
	if (tab == (void *) 0 || nb_l == (void *) 0)
		return ((void *) 0);
	while (i < nb_m)
	{
		tab[i] = malloc((nb_l[i] + 1) * sizeof(char));
		if (tab[i] == (void *) 0)
			return ((void *) 0);
		i++;
	}
	free(nb_l);
	fill_tab(s, c, tab, nb_m);
	return (tab);
}
