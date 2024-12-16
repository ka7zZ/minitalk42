/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghergut <aghergut@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 12:22:05 by aghergut          #+#    #+#             */
/*   Updated: 2024/10/15 18:11:19 by aghergut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "strings.h"

static int	back_idx(char const *s1, char const *set, int s1_len, int set_len)
{
	int	test;

	test = 0;
	while (s1_len >= 0)
	{
		while (set_len >= 0)
		{
			if (set[set_len] == s1[s1_len])
				test++;
			set_len--;
		}
		if (test == 0)
			return (s1_len);
		test = 0;
		set_len = ft_strlen(set) - 1;
		s1_len--;
	}
	return (0);
}

static int	front_idx(char const *s1, char const *set, int s1_i, int set_i)
{
	int	test;
	int	s1_len;

	test = 0;
	s1_len = ft_strlen(s1) - 1;
	while (s1_len >= 0)
	{
		while (set_i < (int) ft_strlen(set))
		{
			if (set[set_i] == s1[s1_i])
				test++;
			set_i++;
		}
		set_i = 0;
		if (test == 0)
			return (s1_i);
		test = 0;
		s1_i++;
		s1_len--;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*res;
	int		s1_len;
	int		f_idx;
	int		b_idx;

	s1_len = (int) ft_strlen(s1) - 1;
	f_idx = front_idx(s1, set, 0, 0);
	b_idx = back_idx(s1, set, s1_len, (int) ft_strlen(set) - 1);
	if (f_idx == 0 && b_idx == 0)
	{
		res = ft_substr(s1, 0, 0);
		return (res);
	}
	res = ft_substr(s1, front_idx(s1, set, 0, 0), b_idx - f_idx + 1);
	if (!res)
		return (NULL);
	return (res);
}
