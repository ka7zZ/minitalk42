#include "minitalk.h"
int global_check = 0;

void	ft_handle(int signo, siginfo_t *info, void *context)
{
    static unsigned char    ch;
    static int              bits;
	
    (void)context;
    if (!global_check)
    {
        bits = 8;
        ch = 0;
        global_check = 1;
    }
    if (signo == SIGUSR1 && global_check)
		ch = ch << 1;
    else if (signo == SIGUSR2 && global_check)
		ch = (ch << 1) | 1;
    bits--;
    if (!bits && global_check)
    {
        if (ch == '\0')
        {
            write(1, "\n", 1);
            kill(info->si_pid, SIGUSR1);
        }
        else
            ft_putchar_fd(ch, 1);     
        global_check = 0;
    }
    kill(info->si_pid, SIGUSR2);
}

void    ft_setup()
{
	struct sigaction	handler;

	handler.sa_sigaction = ft_handle;
	sigemptyset(&handler.sa_mask);
	handler.sa_flags = SA_SIGINFO | SA_RESTART | SA_NODEFER;

	if (sigaction(SIGUSR1, &handler, 0) < 0)
	{
		perror("Failed to receive SIGUSR1");
		exit(EXIT_FAILURE);
	}
	if (sigaction(SIGUSR2, &handler, 0) < 0)
	{
		perror("Failed to receive SIGUSR2");
		exit(EXIT_FAILURE);
	}
}

int main(void) 
{
	printf("Server PID: %d\n", getpid());	
	ft_setup();
	while (1) 
		pause();
	return 0;
}

/*TIMER MS:  
#include <time.h>

Global:		struct timespec start_time, end_time;
Variabile:
	Main:
			clock_gettime(CLOCK_REALTIME, &start_time);
	
	Inceputul functiei:
			long long start_ms = 0;
			if (start_ms == 0)
			 	start_ms = (start_time.tv_sec * 1000LL) + (start_time.tv_nsec / 1000000);
	
	Sfarsitul functiei:
			clock_gettime(CLOCK_REALTIME, &end_time);
			long long end_ms = (end_time.tv_sec * 1000LL) + (end_time.tv_nsec / 1000000);
			printf("Time: %lld ms\n", end_ms - start_ms);
*/

/*TESTING:    

SIGUSR1:	
	write(1, "sigusr1 -->> ", 13);
	ft_putchar_fd(data->ch, 1);
	write(1, "\n", 1);

SIGUSR2:
	write(1, "sigusr2 -->> ", 13);
	ft_putchar_fd(data->ch, 1);
	write(1, "\n", 1);

AFTER SU1 & SU2
	write(1, "after ifs -->> ", 15);
	ft_putchar_fd(data->ch, 1);
	write(1, "\n", 1);

INSIDE OF CONSTRUCTED CHAR
	write(1, "bits:\n", 6);
	ft_putnbr_fd(data->bits, 1);
	write(1, "\n", 1);
	write(1, "char:\n", 6);
	ft_putchar_fd(data->ch, 1);
	write(1, "\n", 1);
	print_bits(data->ch);
*/

/*PRINT BITS FUNC

void 	print_bits(unsigned char ch)
{
	unsigned char	bit;
	int 			length = 8;

	while (length--)
	{
		bit = ((ch >> length) & 1) + '0';
		write(1, &bit, 1);
	}
	write(1, "\n", 1);
}
*/
