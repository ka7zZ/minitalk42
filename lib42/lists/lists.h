/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghergut <aghergut@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 17:20:24 by aghergut          #+#    #+#             */
/*   Updated: 2024/10/16 15:57:58 by aghergut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_H
# define LIST_H

# include <stdlib.h>
# include <stddef.h>

# include "../libft.h"

// lists
typedef struct s_list
{
	char			*content;
	struct s_list	*next;
}	t_list;

// new
t_list	*ft_lstnew(char *content);
// size
size_t	ft_lstsize(t_list *lst);
// getting last element
t_list	*ft_lstlast(t_list *lst);
// adding
void	ft_lstadd_front(t_list **lst, t_list *new);
void	ft_lstadd_back(t_list **lst, t_list *new);
// deleting
void	ft_lstdelone(t_list *lst, void (*del)(void*));
void	ft_lstclear(t_list **lst, void (*del)(void*));
// change content
void	ft_lstiter(t_list *lst, void (*f)(void *));
// duplicate list
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

#endif