/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iel-amra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 12:50:26 by iel-amra          #+#    #+#             */
/*   Updated: 2021/11/05 15:50:13 by iel-amra         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	int	i;
	int	len;

	len = 0;
	while (dst[len] && len < (int) dstsize)
		len++;
	i = 0;
	while (src[i] && i < (int) dstsize - len - 1)
	{
		dst[len + i] = src[i];
		i++;
	}
	if ((int) dstsize != len)
		dst[len + i] = '\0';
	while (src[i])
		i++;
	return (len + i);
}
