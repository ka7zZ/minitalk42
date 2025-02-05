/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghergut <aghergut@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 16:50:14 by aghergut          #+#    #+#             */
/*   Updated: 2024/10/15 18:11:16 by aghergut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "strings.h"

char	*ft_strrchr(const char *str, int ch)
{
	char	*res;
	int		i;

	res = (char *) str;
	i = ft_strlen(res);
	while (i >= 0)
	{
		if (res[i] == (char)ch)
			return (res + i);
		i--;
	}
	return (0);
}
