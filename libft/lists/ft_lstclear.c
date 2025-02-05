/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghergut <aghergut@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 13:45:40 by aghergut          #+#    #+#             */
/*   Updated: 2024/10/15 18:09:00 by aghergut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lists.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*ptr;
	t_list	*temp;

	if (lst)
	{
		ptr = *lst;
		while (ptr != NULL)
		{
			temp = ptr->next;
			if (del)
				del(ptr->content);
			free(ptr);
			ptr = temp;
		}
		*lst = NULL;
	}
}
