/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghergut <aghergut@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 19:14:37 by aghergut          #+#    #+#             */
/*   Updated: 2024/10/16 16:11:35 by aghergut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "puts.h"

void	ft_putendl_fd(char *s, int fd)
{
	char	ch;

	ch = '\n';
	if (*s)
		ft_putstr_fd(s, fd);
	write(fd, &ch, 1);
}
