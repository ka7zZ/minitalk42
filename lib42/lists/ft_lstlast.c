/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghergut <aghergut@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 13:45:10 by aghergut          #+#    #+#             */
/*   Updated: 2024/10/15 18:08:55 by aghergut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lists.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*temp;

	if (lst == NULL)
		return (NULL);
	while (lst != NULL)
	{
		temp = lst;
		lst = lst->next;
	}
	lst = temp;
	return (lst);
}
