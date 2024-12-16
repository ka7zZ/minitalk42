/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghergut <aghergut@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 14:56:31 by aghergut          #+#    #+#             */
/*   Updated: 2024/10/16 16:11:38 by aghergut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "puts.h"

void	ft_putnbr_fd(long n, int fd)
{
	char	c;

	if (n == -2147483648)
		write(fd, "-2147483648", 11);
	else if (n < 0)
	{
		write(fd, "-", 1);
		n *= -1;
	}
	if (n > 9)
		ft_putnbr_fd(n / 10, fd);
	if (n >= 0)
	{
		c = (n % 10) + '0';
		ft_putchar_fd(c, fd);
	}
}
