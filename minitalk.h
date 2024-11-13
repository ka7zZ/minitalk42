#ifndef MINITALK_H
# define MINITALK_H

#include <unistd.h>
#include <signal.h>
#include <sys/types.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include "libft/libft.h"
#include "libft/ft_printf/ft_printf.h"

typedef struct Signals {
    unsigned char   ch;
	int             bits;
}   sigstate;

sigstate	data = {0, 0};
#endif
