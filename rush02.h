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
struct	plt
{
	char	*tab;
	int		x;
	int		y;
	int		score;
} typedef plateau;

int	get_score(plateau grille, plateau grille2, int pos);
#endif
