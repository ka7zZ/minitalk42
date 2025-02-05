/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghergut <aghergut@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 19:17:03 by aghergut          #+#    #+#             */
/*   Updated: 2024/10/15 18:10:15 by aghergut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "strings.h"

char	*ft_strdup(const char *s)
{
	char	*res;
	size_t	i;

	i = 0;
	if (s)
	{
		res = ft_calloc(ft_strlen(s) + 1, sizeof(char));
		if (!res)
			return (0);
		while (i < ft_strlen(s))
		{
			res[i] = s[i];
			i++;
		}
		return (res);
	}
	return (NULL);
}
