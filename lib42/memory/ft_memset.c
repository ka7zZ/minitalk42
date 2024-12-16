/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghergut <aghergut@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 16:34:34 by aghergut          #+#    #+#             */
/*   Updated: 2024/10/15 17:42:00 by aghergut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "memory.h"

void	*ft_memset(void *str, int c, size_t n)
{
	unsigned char	*c_str;
	size_t			i;

	c_str = (unsigned char *)str;
	i = 0;
	while (i < n)
	{
		c_str[i] = (unsigned char)c;
		i++;
	}
	return (str = c_str);
}
