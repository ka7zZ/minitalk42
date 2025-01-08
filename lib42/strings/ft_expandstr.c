/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_expandstr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghergut <aghergut@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 17:21:08 by aghergut          #+#    #+#             */
/*   Updated: 2024/12/19 18:35:27 by aghergut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_expandstr(char *str, int ch)
{
	char	*new;
	size_t	i;

	if (ch == '\0')
		return (str);
	if (!str)
	{
		new = (char *)malloc(2 * sizeof(char));
		if (!new)
			return (NULL);
		new[0] = ch;
		new[1] = '\0';
		return (new);
	}
	i = -1;
	new = (char *)malloc((ft_strlen(str) + 2) * sizeof(char));
	if (!new)
		return (NULL);
	while (str[++i])
		new[i] = str[i];
	new[i++] = ch;
	new[i] = '\0';
	free(str);
	return (new);
}
