/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwallis <mwallis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 19:59:58 by mwallis           #+#    #+#             */
/*   Updated: 2024/12/18 19:04:03 by mwallis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	g_can_send;

int	is_numeric(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

void	pursue(int signal)
{
	(void)signal;
	g_can_send = 1;
}

void	send_bits(int pid, char c)
{
	int	bit;

	bit = 0;
	while (bit < 8)
	{
		g_can_send = 0;
		if ((c & (1 << bit)) != 0)
		{
			if (kill(pid, SIGUSR1) == -1)
				return ((void)(write(2, ERROR_SIG1, 41)));
		}
		else
		{
			if (kill(pid, SIGUSR2) == -1)
				return ((void)(write(2, ERROR_SIG2, 41)));
		}
		while (g_can_send == 0)
			usleep(100);
		bit++;
	}
}

void	sigaction_setup(void)
{
	struct sigaction	confirmation;

	confirmation.sa_handler = pursue;
	confirmation.sa_flags = 0;
	sigemptyset(&confirmation.sa_mask);
	sigaction(SIGUSR1, &confirmation, NULL);
}

int	main(int argc, char *argv[])
{
	int	i;
	int	pid;

	sigaction_setup();
	i = 0;
	g_can_send = 1;
	if (argc == 3)
	{
		pid = ft_atoi(argv[1]);
		if (!is_numeric(argv[1]) || pid <= 0)
			return (write(2, "\033[91mError! Invalid PID.\033[0m\n", 30), 1);
		while (argv[2][i] != '\0')
		{
			send_bits(pid, argv[2][i]);
			i++;
		}
		send_bits(pid, '\0');
	}
	else
	{
		write(2, "\033[91mError! Usage: ./client <PID> <MESSAGE>\033[0m\n", 51);
		return (1);
	}
	return (0);
}
