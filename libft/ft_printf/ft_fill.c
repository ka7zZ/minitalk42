/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghergut <aghergut@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 16:09:26 by aghergut          #+#    #+#             */
/*   Updated: 2024/10/16 16:25:16 by aghergut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_fill(int cond1, int cond2, char fill)
{
	int	temp;

	temp = cond2;
	if (cond1 > temp)
	{
		while (cond1 > temp++)
			write(1, &fill, 1);
		return (cond1 - cond2);
	}
	return (0);
}
