/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghergut <aghergut@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 17:02:50 by aghergut          #+#    #+#             */
/*   Updated: 2024/12/20 12:05:36 by aghergut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	g_check;

void	ft_handle_char(char **str, char ch, pid_t pid)
{
	if (ch == '\0')
	{
		ft_putstr_fd(*str, 1);
		free(*str);
		*str = NULL;
		write(1, "\n", 1);
		kill(pid, SIGUSR1);
	}
	else
		*str = ft_expandstr(*str, ch);
}

void	ft_handle(int signo, siginfo_t *info, void *context)
{
	static unsigned char	ch;
	static char				*str;
	static int				bits;

	(void)context;
	if (!g_check)
	{
		bits = 8;
		ch = 0;
		g_check = 1;
	}
	if (signo == SIGUSR1 && g_check)
		ch = ch << 1;
	else if (signo == SIGUSR2 && g_check)
		ch = (ch << 1) | 1;
	bits--;
	if (!bits && g_check)
	{
		ft_handle_char(&str, (char)ch, info->si_pid);
		g_check = 0;
	}
	kill(info->si_pid, SIGUSR2);
}

void	ft_setup(void)
{
	struct sigaction	handler;

	handler.sa_sigaction = ft_handle;
	sigemptyset(&handler.sa_mask);
	handler.sa_flags = SA_SIGINFO | SA_RESTART | SA_NODEFER;
	if (sigaction(SIGUSR1, &handler, 0) < 0)
	{
		ft_putstr_fd("Failed to receive SIGUSR1", 1);
		exit(EXIT_FAILURE);
	}
	if (sigaction(SIGUSR2, &handler, 0) < 0)
	{
		ft_putstr_fd("Failed to receive SIGUSR2", 1);
		exit(EXIT_FAILURE);
	}
}

int	main(void)
{
	ft_printf("Server PID: %d\n", getpid());
	ft_setup();
	while (1)
		pause();
	return (0);
}
