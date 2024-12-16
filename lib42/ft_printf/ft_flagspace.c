/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flagspace.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghergut <aghergut@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 15:59:34 by aghergut          #+#    #+#             */
/*   Updated: 2024/10/16 16:25:35 by aghergut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_flagspace(t_flags *flags, char type, int n)
{
	if (flags->space == 1 && ft_strchr("pid", type))
	{
		if (type == 'p' || n >= 0)
		{
			ft_putchar_fd(' ', 1);
			return (1);
		}
	}
	return (0);
}
