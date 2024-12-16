/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strings.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghergut <aghergut@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 16:59:34 by aghergut          #+#    #+#             */
/*   Updated: 2024/10/16 16:11:18 by aghergut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRING_H
# define STRING_H

# include <stdlib.h>
# include <stddef.h>
# include <unistd.h>
# include <string.h>

//including own library's headers
# include "../memory/memory.h"

// string length
size_t	ft_strlen(const char *s);
// setting null char
void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t n, size_t size);
// finding char
char	*ft_strchr(const char *str, int ch);
char	*ft_strrchr(const char *str, int ch);
// finding sequence
char	*ft_strnstr(const char *haystack, const char *needle, size_t n);
// comparing
int		ft_strncmp(const char *s1, const char *s2, size_t n);
// new
char	*ft_strdup(const char *s);
char	*ft_substr(char const *s, unsigned int start, size_t len);
// trimming 
char	*ft_strtrim(char const *s1, char const *set);
// concatenating & copying
void	ft_strncat(char *dest, char *src, size_t n);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
size_t	ft_strlcat(char *dst, const char *src, size_t size);
char	*ft_strjoin(char const *s1, char const *s2);
// splitting 
char	**ft_split(char *s, char c);
// advanced
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));

#endif