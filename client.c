/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghergut <aghergut@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 14:19:59 by aghergut          #+#    #+#             */
/*   Updated: 2024/12/20 12:27:24 by aghergut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	g_check;

void	ft_kill(pid_t pid, int signo)
{
	if (kill(pid, signo) < 0)
		ft_printf("Error sending the signal %d to process %d\n", signo, pid);
}

void	send_char(pid_t pid, char c)
{
	int	i;

	i = 8;
	while (i--)
	{
		g_check = 0;
		if ((c >> i) & 1)
			ft_kill(pid, SIGUSR2);
		else
			ft_kill(pid, SIGUSR1);
		usleep(100);
		while (!g_check)
			usleep(10);
	}
}

void	confirm(int signo)
{
	if (signo == SIGUSR2)
		g_check = 1;
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
	char	*ptr;

	if (argc != 3 || !argv[2][0])
		return (ft_printf("Wrong number of parameters!\n"));
	ptr = argv[1];
	while (ft_isdigit(*ptr))
		ptr++;
	if (*ptr != '\0')
		return (ft_printf("Wrong pid format!\n"));
	if (signal(SIGUSR2, &confirm) == SIG_ERR)
	{
		ft_putstr_fd("Failed to receive confirmation", 1);
		exit(EXIT_FAILURE);
	}
	handle_output(argv, (pid_t)ft_atoi(argv[1]));
	return (0);
}
