/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghergut <aghergut@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 17:00:47 by aghergut          #+#    #+#             */
/*   Updated: 2024/10/15 18:11:06 by aghergut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "strings.h"

void	ft_strncat(char *dest, char *src, size_t n)
{
	size_t	i;
	size_t	dest_index;

	if (dest && src && n > 0)
	{
		i = 0;
		dest_index = strlen(dest);
		while (*src && (i < n))
			dest[dest_index++] = src[i++];
		dest[dest_index] = '\0';
	}
}
