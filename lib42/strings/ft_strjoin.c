/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghergut <aghergut@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 19:19:18 by aghergut          #+#    #+#             */
/*   Updated: 2024/10/15 18:10:40 by aghergut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "strings.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*res;
	size_t	len;

	if (s1 && s2)
	{
		len = ft_strlen(s1) + ft_strlen(s2) + 1;
		res = (char *) malloc(len * sizeof(char));
		if (res == NULL)
			return (NULL);
		ft_bzero(res, len);
		res = ft_memcpy(res, s1, ft_strlen(s1));
		ft_strlcat(res, s2, len);
		return (res);
	}
	return (0);
}
