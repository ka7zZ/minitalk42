/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghergut <aghergut@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 14:47:32 by aghergut          #+#    #+#             */
/*   Updated: 2024/10/15 10:55:23 by aghergut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_memlen(unsigned long long mem)
{
	int	base_len;
	int	count;

	base_len = 16;
	count = 0;
	while (mem > 0)
	{
		mem /= base_len;
		count++;
	}
	return (count);
}
