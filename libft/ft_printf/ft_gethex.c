/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gethex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghergut <aghergut@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 14:12:00 by aghergut          #+#    #+#             */
/*   Updated: 2024/10/16 16:25:37 by aghergut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_printhex(unsigned long long n, char *base)
{
	size_t	base_length;

	base_length = ft_strlen(base);
	if (n >= base_length)
	{
		ft_printhex(n / base_length, base);
		n = n % base_length;
	}
	ft_putchar_fd(base[n], 1);
}

int	ft_gethex(unsigned long long n, char type)
{
	int					count;
	unsigned long long	temp;
	char				*base;

	count = 0;
	temp = n;
	if (type == 'p' || type == 'x')
		base = "0123456789abcdef";
	else
		base = "0123456789ABCDEF";
	if (n == 0)
		return (0);
	ft_printhex(temp, base);
	while (n > 0)
	{
		n /= 16;
		count++;
	}
	return (count);
}
