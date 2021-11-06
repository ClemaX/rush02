/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iel-amra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 14:39:21 by iel-amra          #+#    #+#             */
/*   Updated: 2021/11/05 20:23:28 by iel-amra         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	int	i;

	i = 0;
	while (((unsigned char *)s1)[i] == ((unsigned char *)s2)[i]
		&& i < (int)n - 1)
		i++;
	return (((unsigned char *) s1)[i] - ((unsigned char *) s2)[i]);
}
