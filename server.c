
#include <signal.h>
#include <sys/types.h>
#include <fcntl.h>
#include "libft/ft_printf/ft_printf.h"
#include "libft/libft.h"

void	reverse_char(unsigned char *ch)
{
	unsigned char   result = 0;
	int             i = 8;

	while (i--)
	{
		result = (result << 1) | (*ch & 1);
		*ch >>= 1;
	}
	*ch = result;
}
void    handle_signal(int signo, siginfo_t *info, void *context)
{
	static unsigned char     ch = 0;
	static int               idx = 0;

	
	(void)context;
	if (signo == SIGUSR1)
    	ch <<= 1;
    else if (signo == SIGUSR2)
        ch = (ch << 1) | 1;
	idx++;
	if (idx == 8)
	{
		if (ch == '\0')
        	kill(info->si_pid, SIGUSR1);
		reverse_char(&ch);
		write(1, &ch, 1);
        ch = 0;
		idx = 0;
	}
}

int main() 
{
	struct sigaction sa;

	ft_printf("Server PID: %d\n", getpid());

	sa.sa_handler = (void (*)(int))handle_signal;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = SA_SIGINFO;

	if (sigaction(SIGUSR1, &sa, NULL) < 0)
		return (ft_printf("Error: sigaction SIGUSR1\n"));
    if (sigaction(SIGUSR2, &sa, NULL) < 0)
		return (ft_printf("Error: sigaction SIGUSR2\n"));
	while (1)
	{
		pause();
	}
	return 0;
}

/*
typedef struct LinkedList{
	pid_t pid;                      // Client's PID
	struct sigaction central;
} minitalk;

void char_value(char *bits_received)
{
	int length = strlen(bits_received);
	int idx = 0;
	unsigned char   ch = 0;

	while (length--)
	{
		ch <<= 1;
		if (bits_received[idx] == '1')
			ch |= 1;
		idx++;
	}
	write(1, &ch, 1);

}
*/