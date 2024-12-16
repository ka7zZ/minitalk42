/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghergut <aghergut@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 16:31:19 by aghergut          #+#    #+#             */
/*   Updated: 2024/10/15 18:10:23 by aghergut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "strings.h"

size_t	ft_strlcat(char	*dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	len_dst;
	size_t	len_src;

	len_dst = ft_strlen(dst);
	len_src = ft_strlen(src);
	if (len_dst > size)
		return (size + len_src);
	i = ft_strlen(dst);
	j = 0;
	while (i < size && src[j] != '\0')
		dst[i++] = src[j++];
	if (len_dst + len_src >= size)
	{
		if (len_dst < size)
			dst[size - 1] = '\0';
		return (len_dst + len_src);
	}
	dst[i] = '\0';
	return (ft_strlen(dst));
}
