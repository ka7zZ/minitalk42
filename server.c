#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <string.h>

int    handle_signal(int signo, siginfo_t *info, void *context)
{
	static unsigned char     ch = 0;
	static int               idx = 0;
    pid_t                    client_pid;

	if (signo == SIGUSR1)
    	ch <<= 1;	
    else if (signo == SIGUSR2)
        ch = (ch << 1) | 1;
    else
        write(1, "Wrong signal!\n", 1);
    idx++;
	if (idx == 8)
	{
        kill(info->si_pid, SIGUSR1);
        write (1, &ch, 1);
        idx = 0;
	}
}

int main() 
{
	struct sigaction handler;
	int     test = 0;
	printf("Server PID: %d\n", getpid());

	handler.sa_handler = (void (*)(int))handle_signal;
	sigemptyset(&handler.sa_mask);
	handler.sa_flags = SA_SIGINFO;

	sigaction(SIGUSR1, &handler, NULL);
    sigaction(SIGUSR2, &handler, NULL);

	while (1) {
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