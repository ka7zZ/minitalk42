/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strtoint.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghergut <aghergut@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 17:35:19 by aghergut          #+#    #+#             */
/*   Updated: 2024/10/15 18:07:07 by aghergut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITOSTR_H
# define ITOSTR_H

# include "../strings/strings.h"

//int to str
char	*ft_itoa(int n);
//str to int
int     ft_atoi(const char *str);

#endif