/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghergut <aghergut@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 12:15:51 by aghergut          #+#    #+#             */
/*   Updated: 2024/10/15 18:11:03 by aghergut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "strings.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char				*res;
	unsigned int		i;

	if (!s && !f)
		return (NULL);
	res = ft_calloc(ft_strlen(s) + 1, sizeof(char));
	if (!res)
		return (NULL);
	if (s && f)
	{
		i = 0;
		while (s[i] != '\0')
		{
			res[i] = f(i, s[i]);
			i++;
		}
	}
	else
		res = NULL;
	return (res);
}
