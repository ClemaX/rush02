/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iel-amra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 11:09:08 by iel-amra          #+#    #+#             */
/*   Updated: 2021/11/05 17:43:01 by iel-amra         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char				*new;
	unsigned int		i;

	if (!s)
		return ((void *) 0);
	if (start >= (unsigned int) ft_strlen(s))
		start = (unsigned int) ft_strlen(s);
	i = ft_strlen(s + start);		
	if (i >= (unsigned int) len)
		new = malloc((unsigned int) len + 1);
	else
		new = malloc(i + 1);
	if (new == (void *) 0)
		return ((void *) 0);
	i = 0;
	while (i < (unsigned int) len && s[i])
	{
		new[i] = s[start + i];
		i++;
	}
	new[i] = '\0';
	return (new);
}
