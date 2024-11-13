#include "minitalk.h"
int global_check = 0;

void	ft_kill(pid_t pid, int signo)
{
	if (kill(pid, signo) < 0)
		ft_printf("Error sending the signal %d to process %d\n", signo, pid);
}

void    send_char(pid_t pid, char c)
{
    int i = 8;
	
    while (i--)
	{
        global_check = 0;
		if ((c >> i) & 1)
			ft_kill(pid, SIGUSR2);
		else
			ft_kill(pid, SIGUSR1);
		usleep(100);
        while (!global_check)
            usleep(10);
	}
}

void	handle_input(int signo)
{
	static int	number = 0;

	if (signo == SIGUSR1)
        ft_printf("Received string %d!\n", ++number);
	global_check = 1;
}

void	handle_output(char **input, pid_t pid)
{
	int	i;
	int	j;
	
	i = 1;
	while (input[++i])
	{
		j = 0;
		while (input[i][j] != '\0')
		{    
			send_char(pid, input[i][j]);
			j++;
		}
		send_char(pid, '\0');
	}
}

int	main(int argc, char **argv) 
{
	char				*ptr;
	
	if (argc < 3 || !argv[2][0])
		return (ft_printf("Not enough values!\n"));
	ptr = argv[1];
	while (ft_isdigit(*ptr))
		ptr++;
	if (*ptr != '\0')
		return (ft_printf("Wrong pid format!\n"));
	signal(SIGUSR1, &handle_input);
    signal(SIGUSR2, &handle_input);
	handle_output(argv, (pid_t)ft_atoi(argv[1]));
	return (0);
}
