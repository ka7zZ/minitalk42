/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghergut <aghergut@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 15:52:14 by aghergut          #+#    #+#             */
/*   Updated: 2024/12/19 18:33:33 by aghergut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

//including variadic header
# include <stdarg.h>
// including own headers
# include "../changechar/changechar.h"
# include "../checkchar/checkchar.h"
# include "../lists/lists.h"
# include "../memory/memory.h"
# include "../strtoint/strtoint.h"
# include "../strings/strings.h"
# include "../puts/puts.h"

// printf flags
typedef struct s_flags
{
	int				prec;
	int				precw;
	int				space;
	int				sign;
	int				left;
	int				zpad;
	int				alt;
	int				width;
}	t_flags;

const char	*ft_flagadd(va_list *args, t_flags *flags, const char *format);
void		ft_flagset(t_flags *flags);
int			ft_flagalt(t_flags *flags, char type);
int			ft_flagsign(t_flags *flags, char type, int n);
int			ft_flagspace(t_flags *flags, char type, int n);
int			ft_printchar(t_flags *flags, char ch);
int			ft_printint(t_flags *flags, int number, char type);
int			ft_printpxx(va_list *args, t_flags *flags, char type);
int			ft_printstr(t_flags *flags, char *content);
int			ft_printu(t_flags *flags, unsigned int number);
int			ft_printf(const char *format, ...);
int			ft_fill(int cond1, int cond2, char fill);
int			ft_gethex(unsigned long long mem, char type);
int			ft_memlen(unsigned long long mem);
int			ft_numlen(long n);

#endif
