/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghergut <aghergut@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 16:34:26 by aghergut          #+#    #+#             */
/*   Updated: 2024/10/15 17:17:37 by aghergut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "memory.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*string1;
	unsigned char	*string2;
	size_t			i;

	string1 = (unsigned char *)s1;
	string2 = (unsigned char *)s2;
	i = 0;
	while (i < n && string1[i] == string2[i])
		i++;
	if (i == n)
		return (0);
	return (string1[i] - string2[i]);
}
