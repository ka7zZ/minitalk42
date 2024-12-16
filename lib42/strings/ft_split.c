/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghergut <aghergut@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 18:58:07 by aghergut          #+#    #+#             */
/*   Updated: 2024/10/16 16:11:10 by aghergut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "strings.h"

static int	count_arrays(char *str, char c)
{
	int	word;

	word = 0;
	while (*str)
	{
		if (!*str)
			return (word);
		while (*str == c)
			str++;
		if (*str)
			word++;
		while (*str != c && *str)
			str++;
	}
	return (word);
}

static void	free_memory(char **s, int pos)
{
	while (pos > 0)
		free(s[--pos]);
	free(s);
}

static char	**assign(char **sp, int pos, char *s, char c)
{
	size_t		sub_len;
	size_t		start;

	start = 0;
	while (start < ft_strlen(s))
	{
		sub_len = 0;
		while (s[start] != c && s[start] != 0)
		{
			sub_len++;
			start++;
		}
		if ((s[start] == c && sub_len > 0) || start == ft_strlen(s))
		{
			sp[pos] = ft_substr(s, start - sub_len, sub_len);
			if (sp[pos++] == 0)
			{
				free_memory(sp, pos - 1);
				return (NULL);
			}
		}
		start++;
	}
	return (sp);
}

char	**ft_split(char *str, char c)
{
	char	**splits;
	int		words;

	words = count_arrays(str, c);
	splits = (char **) ft_calloc(words + 1, sizeof(char *));
	if (!splits)
		return (0);
	if (str == NULL)
		return (splits);
	splits = assign(splits, 0, str, c);
	return (splits);
}
