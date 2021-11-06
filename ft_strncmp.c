/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iel-amra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 13:53:10 by iel-amra          #+#    #+#             */
/*   Updated: 2021/11/05 15:04:29 by iel-amra         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i]
		&& (unsigned char)s1[i] == (unsigned char)s2[i] && i < (int) n - 1)
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
