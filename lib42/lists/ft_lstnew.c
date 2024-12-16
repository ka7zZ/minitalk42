/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghergut <aghergut@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 13:46:10 by aghergut          #+#    #+#             */
/*   Updated: 2024/10/16 15:33:49 by aghergut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lists.h"

t_list	*ft_lstnew(char *content)
{
	t_list	*node;

	node = (t_list *) malloc(sizeof(t_list));
	if (!node)
		return (NULL);
	if (content)
	{
		node->content = content;
		node->next = NULL;
		return (node);
	}
	node->content = NULL;
	node->next = NULL;
	return (node);
}
