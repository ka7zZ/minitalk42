#ifndef MINITALK_H
# define MINITALK_H

#include <unistd.h>
#include <stdlib.h>
#include <signal.h>

void	ft_putchar_fd(char c, int fd);
void	ft_putnbr_fd(int n, int fd);
void	ft_putstr_fd(char *str, int fd);
void	*ft_memset(void *str, int c, size_t n);
int	    ft_isdigit(int c);
int	    ft_atoi(const char *str);

#endif
