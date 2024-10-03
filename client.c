#include <signal.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

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

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
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

void handle_input(char **input, pid_t pid)
{
    int             i = 2;
	int             j = 0;
    int             bits = 8;
    unsigned char   send;

    while (input[i])
    {
        while (input[i][j] != '\0')
        {
            while (bits-- > 0)
            {
                send = input[i][j] >> bits & 1;
                if (send == 0)
                    kill(pid, SIGUSR1);
                if(send == 1)
                    kill(pid, SIGUSR2);
                usleep(3000);
            }
            bits = 8;
            j++;
        }
        j = 0;
        i++;
    }
}

int main(int argc, char *argv[]) 
{
    char    *ptr;

	if (argc < 3 || !argv[2][0])
        return (ft_putstr_fd("Not enough values!\n", 1), 0);
    ptr = argv[1];
    while (ft_isdigit(*ptr))
        ptr++;
    if (*ptr != '\0')
        return (ft_putstr_fd("Wrong pid format!\n", 1), 0);
    handle_input(argv, (pid_t)ft_atoi(argv[1]));
    return (0);
}

