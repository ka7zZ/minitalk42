/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghergut <aghergut@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 14:04:50 by aghergut          #+#    #+#             */
/*   Updated: 2024/10/15 18:11:10 by aghergut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"strings.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*cs1;
	unsigned char	*cs2;
	size_t			i;

	if (s1 && s2)
	{
		i = 0;
		cs1 = (unsigned char *)s1;
		cs2 = (unsigned char *)s2;
		while (cs1[i] == cs2[i] && i < n - 1 && cs1[i] != '\0')
			i++;
		if (i == n)
			return (0);
		return (cs1[i] - cs2[i]);
	}
	return (0);
}
