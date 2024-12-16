/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghergut <aghergut@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 16:10:12 by aghergut          #+#    #+#             */
/*   Updated: 2024/10/16 16:10:21 by aghergut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "strings.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*res;
	size_t	i;
	size_t	length;

	if (!s)
		return (NULL);
	length = ft_strlen(s);
	res = malloc((len + 1) * sizeof(char));
	if (!res)
		return (NULL);
	if (start >= length || length == 0)
		return (free(res), NULL);
	if ((length - start) < len)
		len = length - start;
	i = -1;
	while (s[start + (++i)] != '\0' && i < len)
		res[i] = s[start + i];
	res[i] = '\0';
	return (res);
}

