/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghergut <aghergut@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 10:21:19 by aghergut          #+#    #+#             */
/*   Updated: 2024/10/16 16:25:54 by aghergut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_printnum(int number)
{
	if (number == -2147483648)
		ft_putstr_fd("2147483648", 1);
	else if (number < 0)
		ft_putnbr_fd(number * (-1), 1);
	else
		ft_putnbr_fd(number, 1);
}

static int	ft_precdi(t_flags *flags, char type, int n)
{
	int	len;
	int	temp;

	len = ft_numlen(n);
	if (!flags->precw && !n)
		len = 0;
	temp = len;
	if ((flags->precw || n) && len > flags->precw)
		flags->precw = len;
	if (n < 0)
		len++;
	if (len > temp)
		flags->sign = 1;
	if (flags->zpad || (!flags->zpad && !flags->left && flags->width))
		len += ft_fill(flags->width, flags->precw + flags->sign, ' ');
	ft_flagsign(flags, type, n);
	len += ft_fill(flags->precw, temp, '0');
	if (flags->precw || n)
		ft_printnum(n);
	if (flags->left)
		len += ft_fill(flags->width, len, ' ');
	return (len);
}

int	ft_printint(t_flags *flags, int number, char type)
{
	int	length;

	length = ft_numlen(number);
	length += ft_flagspace(flags, type, number);
	if (flags->prec)
		return (ft_precdi(flags, type, number));
	if (number < 0)
		flags->sign = 1;
	if (!flags->zpad && !flags->left && flags->width)
	{
		if (number < 0)
			length += ft_fill(flags->width, length + 1, ' ');
		else
			length += ft_fill(flags->width, length, ' ');
	}
	length += ft_flagsign(flags, type, number);
	if (flags->zpad)
		length += ft_fill(flags->width, length, '0');
	ft_printnum(number);
	if (flags->left)
		length += ft_fill(flags->width, length, ' ');
	return (length);
}
