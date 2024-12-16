/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghergut <aghergut@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 12:05:02 by aghergut          #+#    #+#             */
/*   Updated: 2024/10/16 15:32:27 by aghergut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_strjoin_free(char const *s1, char const *s2)
{
	size_t	i;
	size_t	join_i;
	char	*join;

	if (!s2)
		return (NULL);
	if (!s1)
	{
		join = ft_substr(s2, 0, ft_strlen(s2));
		if (!join)
			return (free((void *)s2), NULL);
		return (free((void *)s2), join);
	}
	join = (char *)malloc((ft_strlen(s1) + ft_strlen(s2) +1) * sizeof(char));
	if (!join)
		return (free((void *)s1), free((void *)s2), NULL);
	join_i = -1;
	while (s1[++join_i] != '\0')
		join[join_i] = s1[join_i];
	i = 0;
	while (s2[i] != '\0')
		join[join_i++] = s2[i++];
	join[join_i] = '\0';
	return (free((void *)s1), free((void *)s2), join);
}

static int	ft_append_nodes(t_list **lst, int fd, int *reading)
{
	char	*line;

	line = malloc(BUFFER_SIZE + 1);
	if (!line)
		return (ft_lstclear(lst, free), 0);
	while (*reading > 0)
	{
		*reading = read(fd, line, BUFFER_SIZE);
		if (*reading < 0)
			return (free(line), ft_lstclear(lst, free), *lst = NULL, -1);
		if (*reading == 0)
			break ;
		line[*reading] = '\0';
		if (line && ft_strlen(line) > 0)
			ft_lstadd_back(lst, ft_lstnew(ft_substr(line, 0, ft_strlen(line))));
		if (ft_strchr(line, '\n'))
			break ;
	}
	return (free(line), *reading);
}

static char	*ft_line(t_list **h, t_list *buf, char *res)
{
	size_t	idx;
	char	*ptr;

	while (*h)
	{
		buf = (*h)->next;
		if ((*h)->content && ft_strchr((*h)->content, '\n'))
		{
			idx = ft_strchr((*h)->content, '\n') - (*h)->content + 1;
			res = ft_strjoin_free(res, ft_substr((*h)->content, 0, idx));
			if (idx == ft_strlen((*h)->content))
				return (ft_lstclear(h, free), res);
			ptr = ft_substr((*h)->content, idx, ft_strlen((*h)->content) - idx);
			free((*h)->content);
			(*h)->content = ft_substr(ptr, 0, ft_strlen(ptr));
			return (free(ptr), res);
		}
		else
			res = ft_strjoin_free(res, (*h)->content);
		free(*h);
		*h = buf;
	}
	return (res);
}

char	*get_next_line(int fd)
{
	static t_list	*head[OPEN_MAX];
	t_list		*ptr;
	char			*buffer;
	int				reading;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	ptr = head[fd];
	reading = 1;
	if (!ptr || ft_strchr(ptr->content, '\n') == NULL)
		ft_append_nodes(&ptr, fd, &reading);
	if (reading < 0)
		return (NULL);
	buffer = ft_line(&ptr, NULL, NULL);
	if (buffer == NULL)
		return (ft_lstclear(&ptr, free), ptr = NULL, NULL);
	head[fd] = ptr;
	return (buffer);
}
