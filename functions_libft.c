#include "minitalk.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putnbr_fd(int n, int fd)
{
	char	c;

	if (n == -2147483648)
		write(fd, "-2147483648", 11);
	else if (n < 0)
	{
		write(fd, "-", 1);
		n *= -1;
	}
	if (n > 9)
		ft_putnbr_fd(n / 10, fd);
	if (n >= 0)
	{
		c = (n % 10) + '0';
		ft_putchar_fd(c, fd);
	}
}

void	ft_putstr_fd(char *str, int fd)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		write(fd, &str[i], 1);
		i++;
	}
}

void	*ft_memset(void *str, int c, size_t n)
{
	unsigned char	*c_str;
	size_t			i;

	c_str = (unsigned char *)str;
	i = 0;
	while (i < n)
	{
		c_str[i] = (unsigned char)c;
		i++;
	}
	return (str = c_str);
}

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	ft_atoi(const char *str)
{
	int	number;
	int	kind;

	number = 0;
	kind = 0;
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	if (*str == '-')
	{
		kind = 1;
		str++;
	}
	else if (*str == '+')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		number *= 10;
		number += *str - 48;
		str++;
	}
	if (kind % 2 == 1)
		return (-number);
	return (number);
}