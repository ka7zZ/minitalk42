/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghergut <aghergut@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 13:45:22 by aghergut          #+#    #+#             */
/*   Updated: 2024/10/15 18:09:04 by aghergut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lists.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*temp;

	if (lst != NULL)
	{
		if (ft_lstsize(*lst) > 0)
		{
			temp = *lst;
			while (temp->next != NULL)
				temp = temp->next;
			temp->next = new;
		}
		else
			*lst = new;
	}
	else
		*lst = new;
}
