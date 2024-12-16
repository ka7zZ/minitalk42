/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghergut <aghergut@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 17:32:12 by aghergut          #+#    #+#             */
/*   Updated: 2024/10/15 17:33:22 by aghergut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUT_H
# define PUT_H

# include <unistd.h>

void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(long n, int fd);
void    ft_putuint(unsigned int value, int length);

#endif
