/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghergut <aghergut@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 14:57:32 by aghergut          #+#    #+#             */
/*   Updated: 2024/10/15 18:11:12 by aghergut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "strings.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t n)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (needle[0] == 0)
		return ((char *) haystack);
	while (haystack[i] != '\0' && i < n)
	{
		j = 0;
		while (haystack[i + j] == needle[j] && i + j < n)
		{
			if (needle[j + 1] == '\0')
				return ((char *) &haystack[i]);
			j++;
		}
		i++;
	}
	return (NULL);
}
