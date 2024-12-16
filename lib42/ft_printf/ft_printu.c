/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printu.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghergut <aghergut@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 10:20:34 by aghergut          #+#    #+#             */
/*   Updated: 2024/10/16 16:27:17 by aghergut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_precu(t_flags *flags, unsigned int number)
{
	int	length;
	int	temp;

	length = ft_numlen(number);
	if (!flags->precw && !number)
		length = 0;
	temp = length;
	if ((flags->precw || number) && flags->precw > length)
		length = flags->precw;
	if (flags->zpad || (!flags->zpad && !flags->left && flags->width))
		length += ft_fill(flags->width, length, ' ');
	ft_fill(flags->precw, temp, '0');
	ft_putuint(number, temp);
	if (flags->left)
		length += ft_fill(flags->width, length, ' ');
	return (length);
}

int	ft_printu(t_flags *flags, unsigned int number)
{
	int		length;
	int		temp;

	length = ft_numlen(number);
	temp = length;
	if (flags->prec)
		return (ft_precu(flags, number));
	if (flags->zpad)
		length += ft_fill(flags->width, length, '0');
	if (!flags->zpad && !flags->left && flags->width)
		length += ft_fill(flags->width, length, ' ');
	ft_putuint(number, temp);
	if (flags->left)
		length += ft_fill(flags->width, length, ' ');
	return (length);
}
