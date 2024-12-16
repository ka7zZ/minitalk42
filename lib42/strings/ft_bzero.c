/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghergut <aghergut@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 16:32:16 by aghergut          #+#    #+#             */
/*   Updated: 2024/10/15 18:10:06 by aghergut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "strings.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*cast;
	size_t			i;

	cast = (unsigned char *) s;
	i = 0;
	while (i < n)
	{
		cast[i] = 0;
		i++;
	}
	s = cast;
}
