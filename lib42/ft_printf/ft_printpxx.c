/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printpxx.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghergut <aghergut@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 10:18:55 by aghergut          #+#    #+#             */
/*   Updated: 2024/10/17 16:42:04 by aghergut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_nullcase(t_flags *flags)
{
	int	width;
	int	length;

	width = 0;
	length = 5;
	if (flags->zpad || (!flags->zpad && !flags->left && flags->width))
		width += ft_fill(flags->width, length, ' ');
	width += write(1, "(nil)", 5);
	if (flags->left)
		width += ft_fill(flags->width, length, ' ');
	return (width);
}

static int	ft_precpxx(t_flags *flags, unsigned long long mem, int len, char f)
{
	int	temp;

	temp = len;
	if (flags->prec && flags->precw < len)
		flags->precw = len;
	if ((flags->zpad || (!flags->zpad && !flags->left)) \
			&& flags->width > flags->precw)
	{
		if (f == 'p' && flags->sign)
			flags->precw += 1;
		len += ft_fill(flags->width, flags->precw + flags->alt, ' ');
		temp += flags->sign;
	}
	ft_flagsign(flags, f, 0);
	if (mem > 0)
		ft_flagalt(flags, f);
	len += ft_fill(flags->precw, temp, '0');
	ft_gethex(mem, f);
	if (flags->left)
		len += ft_fill(flags->width - flags->sign, len + flags->alt, ' ');
	return (len + flags->alt);
}

static int	ft_memcase(t_flags *flags, unsigned long long mem, char type)
{
	int	len;

	len = ft_memlen(mem);
	if (!len)
		flags->alt = 0;
	if (flags->prec)
		return (ft_precpxx(flags, mem, len, type));
	if (flags->width && !len)
		len = 1;
	if (flags->alt > 0)
		len += 2;
	if (!flags->zpad && !flags->left && flags->width)
		len += ft_fill(flags->width, len, ' ');
	ft_flagalt(flags, type);
	if (flags-> zpad)
		len += ft_fill(flags->width, len, '0');
	if (mem == 0)
		write(1, "0", 1);
	else
		ft_gethex(mem, type);
	if (flags->left)
		len += ft_fill(flags->width, len, ' ');
	return (len);
}

static int	ft_ptrcase(t_flags *flags, unsigned long long mem, char type)
{
	int	len;

	len = ft_memlen(mem);
	flags->alt = 2;
	len += ft_flagspace(flags, type, 0);
	if (flags->prec)
		return (ft_precpxx(flags, mem, len, type) + flags->sign);
	if (!flags->zpad && !flags->left && flags->width)
		len += ft_fill(flags->width, len + flags->alt, ' ');
	len += ft_flagsign(flags, type, 0);
	len += ft_flagalt(flags, type);
	if (flags->zpad)
		len += ft_fill(flags->width, len, '0');
	ft_gethex(mem, type);
	if (flags->left)
		len += ft_fill(flags->width, len, ' ');
	return (len);
}

int	ft_printpxx(va_list *args, t_flags *flags, char type)
{
	unsigned long long	cast1;
	unsigned int		cast2;

	if (type == 'p')
	{
		cast1 = (unsigned long long)va_arg(*args, void *);
		if (cast1 == 0)
			return (ft_nullcase(flags));
		return (ft_ptrcase(flags, cast1, type));
	}
	cast2 = (unsigned long long)va_arg(*args, unsigned int);
	if (cast2 == 0 && !flags->width && !flags->prec)
		return (write(1, "0", 1));
	return (ft_memcase(flags, cast2, type));
}
