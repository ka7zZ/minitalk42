/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghergut <aghergut@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 12:05:38 by aghergut          #+#    #+#             */
/*   Updated: 2024/12/16 15:20:02 by aghergut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# define OPEN_MAX 1024

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>

# include "../changechar/changechar.h"
# include "../checkchar/checkchar.h"
# include "../lists/lists.h"
# include "../memory/memory.h"
# include "../strtoint/strtoint.h"
# include "../strings/strings.h"
# include "../puts/puts.h"

char	*get_next_line(int fd);

#endif
