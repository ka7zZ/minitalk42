#include <signal.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char *argv[]) 
{
	pid_t           server_pid;
	int             i = 1;
	int             j = 0;
	unsigned char   sending;
	int             bits = 8;
	// int             new_idx = 0;
	// char            bits_str[bits + 1];

	printf("Enter the server PID: ");
	scanf("%d", &server_pid);
	printf("argc - %d \n", argc);
	while (--argc)
	{
		while (argv[i][j] != '\0')
		{
			// bits_str[bits] = '\0';
			// sending SIGNALS depending on the bit 
			while (bits-- > 0)
			{
				sending = argv[i][j] >> bits & 1;
				// bits_str[new_idx++] = sending + '0'; 
				if (sending == 0)
				    kill(server_pid, SIGUSR1);
				if (sending == 1)
				    kill(server_pid, SIGUSR2);
				usleep(5000);					
			}
			// new_idx = 0;
			bits = 8;
			// escribing in char
			// while (bits--)
			// {
			// 	sending <<= 1;
			// 	if (bits_str[new_idx] == '1')
			// 		sending |= 1;
			// 	new_idx++;
			// }
			// new_idx = 0;
			// bits = 8;
			// printf("sending char --->> %c\n", sending);
			// printf("argv[%d][%d] --->> %c\n", i, j, argv[i][j]);
			j++;
		}
		j = 0;
		i++;
	}
	return 0;
}
