/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghergut <aghergut@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 13:46:15 by aghergut          #+#    #+#             */
/*   Updated: 2024/10/16 15:33:52 by aghergut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lists.h"

size_t	ft_lstsize(t_list *lst)
{
	size_t	count;

	if (lst)
	{
		count = 0;
		while (lst != NULL)
		{
			count++;
			lst = lst->next;
		}
		return (count);
	}
	return (0);
}
