#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <string.h>

typedef struct LinkedList{
	pid_t pid;                      // Client's PID
	struct sigaction sa_sigusr1;    // Action for SIGUSR1
	struct sigaction sa_sigusr2;    // Action for SIGUSR2
} SignalHandler;

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

void    handle_signal(int signo)
{
	static char     received[9] = {0};
	static int      idx = 0;

	received[8] = '\0';
	idx += 0;
	if (signo == SIGUSR1)
		received[idx++] = '0';	
	if (signo == SIGUSR2)
		received[idx++] = '1';
	if (idx == 8)
	{
		char_value(received);
		idx = 0;
		memset(received, 0, 8);
	}
}

int main() 
{
	SignalHandler handler;
	
	// Initialize handler
	handler.pid = getpid();  // Server's PID
	printf("Server PID: %d\n", handler.pid);

	// Set up signal handlers
	handler.sa_sigusr1.sa_handler = handle_signal;
	sigemptyset(&handler.sa_sigusr1.sa_mask);
	handler.sa_sigusr1.sa_flags = 0;

	handler.sa_sigusr2.sa_handler = handle_signal;
	sigemptyset(&handler.sa_sigusr2.sa_mask);
	handler.sa_sigusr2.sa_flags = 0;

	sigaction(SIGUSR1, &handler.sa_sigusr1, NULL);
	sigaction(SIGUSR2, &handler.sa_sigusr2, NULL);

	printf("Server PID: %d", handler.pid);
	// Wait for signals
	while (1) {
		pause();  // Wait for signals
	}

	return 0;
}