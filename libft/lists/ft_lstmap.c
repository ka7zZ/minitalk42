/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghergut <aghergut@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 13:46:05 by aghergut          #+#    #+#             */
/*   Updated: 2024/10/17 13:45:48 by aghergut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lists.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*temp;
	char	*f_content;

	if (!lst || !del || !f)
		return (NULL);
	new = NULL;
	while (lst != NULL)
	{
		f_content = f(lst->content);
		temp = ft_lstnew(f_content);
		if (!temp)
			return (del(f_content), ft_lstclear(&new, del), NULL);
		if (new == NULL)
			new = temp;
		else
			ft_lstadd_back(&new, temp);
		lst = lst->next;
	}
	ft_lstadd_back(&new, lst);
	return (new);
}
