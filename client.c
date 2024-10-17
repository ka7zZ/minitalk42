#include <signal.h>
#include <fcntl.h>
#include "libft/ft_printf/ft_printf.h"
#include "libft/libft.h"

void    handle_input(int signo)
{
    static int  number = 0;

    if (signo == SIGUSR1)
        ft_printf("Received letter %d!\n", ++number);
    else
        number = 0;
}

void    handle_output(char **input, pid_t pid)
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
                usleep(300);
            }
            bits = 8;
            j++;
        }
        j = 0;
        i++;
    }
}

int main(int argc, char **argv) 
{
    char                *ptr;
    struct sigaction    sa;
    
    if (argc < 3 || !argv[2][0])
        return (ft_printf("Not enough values!\n"));
    ptr = argv[1];
    while (ft_isdigit(*ptr))
        ptr++;
    if (*ptr != '\0')
        return (ft_printf("Wrong pid format!\n"));
    
    sa.sa_handler = handle_input;
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = SA_RESTART;

    sigaction(SIGUSR1, &sa, NULL);

    handle_output(argv, (pid_t)ft_atoi(argv[1]));

    return (0);
}
