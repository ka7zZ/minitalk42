/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putuint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghergut <aghergut@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 11:14:34 by aghergut          #+#    #+#             */
/*   Updated: 2024/10/16 16:11:43 by aghergut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "puts.h"

void	ft_putuint(unsigned int value, int length)
{
	if (length > 0)
	{
		ft_putuint(value / 10, length - 1);
		ft_putnbr_fd(value % 10, 1);
	}
}
