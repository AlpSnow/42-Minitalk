/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwallis <mwallis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 20:51:29 by mwallis           #+#    #+#             */
/*   Updated: 2024/12/19 16:17:51 by mwallis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	store_display_message_else(char *buffer, int *i, int c, char **message)
{
	char	*temp;

	buffer[*i] = c;
	(*i)++;
	if (*i >= 256)
	{
		buffer[*i] = '\0';
		if (*message != NULL)
		{
			temp = ft_strjoin(*message, buffer);
			free(*message);
			*message = temp;
		}
		else
			*message = ft_strdup(buffer);
		*i = 0;
	}
}

void	store_display_message(int c)
{
	static char	buffer[256];
	static int	i = 0;
	static char	*message = NULL;
	char		*temp;

	if (c == '\0')
	{
		buffer[i] = '\0';
		if (message != NULL)
		{
			temp = ft_strjoin(message, buffer);
			free(message);
			message = temp;
		}
		else
			message = ft_strdup(buffer);
		ft_printf("%s\n", message);
		ft_printf("\033[90m\nAwaiting next message...\033[0m\n");
		free(message);
		message = NULL;
		i = 0;
	}
	else
		store_display_message_else(buffer, &i, c, &message);
}

void	bit_to_byte(int signal, siginfo_t *info, void *context)
{
	static int	c;
	static int	bit;

	(void)context;
	if (signal == SIGUSR1)
	{
		c = c | (1 << bit);
	}
	bit++;
	if (bit == 8)
	{
		store_display_message(c);
		bit = 0;
		c = 0;
	}
	if (info && info->si_pid > 0)
		kill(info->si_pid, SIGUSR1);
}

int	main(int argc, char *argv[])
{
	int					pid;
	struct sigaction	s_sigaction;

	(void)argv;
	if (argc != 1)
	{
		write(2, "\033[91mError: No arguments required.\033[0m\n", 40);
		write(2, "\033[33mUsage: ./server\033[0m\n", 26);
		return (1);
	}
	pid = getpid();
	ft_printf("\033[94mServer PID:\033[0m \033[96m%d\033[0m\n", pid);
	ft_printf("\033[90mAwaiting your message...\033[0m\n");
	s_sigaction.sa_sigaction = bit_to_byte;
	s_sigaction.sa_flags = SA_SIGINFO;
	sigemptyset(&s_sigaction.sa_mask);
	sigaction(SIGUSR1, &s_sigaction, NULL);
	sigaction(SIGUSR2, &s_sigaction, NULL);
	while (1)
	{
		pause();
	}
	return (0);
}
