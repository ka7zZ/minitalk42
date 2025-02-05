/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghergut <aghergut@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 15:15:18 by aghergut          #+#    #+#             */
/*   Updated: 2024/10/15 17:43:01 by aghergut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strchr(const char *str, int ch)
{
	char	c;

	c = ch;
	while (*str != c)
	{
		if (*str == '\0')
			return (0);
		str++;
	}
	return ((char *)str);
}
