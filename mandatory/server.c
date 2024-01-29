/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zech-chi <zech-chi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 12:12:30 by zech-chi          #+#    #+#             */
/*   Updated: 2024/01/27 16:24:59 by zech-chi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk.h"

static void	ft_print_server_header(void)
{
	ft_putstr_fd("\033[38;2;255;165;0m", 1);
	ft_putstr_fd("  ██████ ▓█████  ██▀███   ██▒   █▓▓█████  ██▀███  \n", 1);
	ft_putstr_fd("▒██    ▒ ▓█   ▀ ▓██ ▒ ██▒▓██░   █▒▓█   ▀ ▓██ ▒ ██▒\n", 1);
	ft_putstr_fd("░ ▓██▄   ▒███   ▓██ ░▄█ ▒ ▓██  █▒░▒███   ▓██ ░▄█ ▒\n", 1);
	ft_putstr_fd("  ▒   ██▒▒▓█  ▄ ▒██▀▀█▄    ▒██ █░░▒▓█  ▄ ▒██▀▀█▄  \n", 1);
	ft_putstr_fd("▒██████▒▒░▒████▒░██▓ ▒██▒   ▒▀█░  ░▒████▒░██▓ ▒██▒\n", 1);
	ft_putstr_fd("▒ ▒▓▒ ▒ ░░░ ▒░ ░░ ▒▓ ░▒▓░   ░ ▐░  ░░ ▒░ ░░ ▒▓ ░▒▓░\n", 1);
	ft_putstr_fd("░ ░▒  ░ ░ ░ ░  ░  ░▒ ░ ▒░   ░ ░░   ░ ░  ░  ░▒ ░ ▒░\n", 1);
	ft_putstr_fd("░  ░  ░     ░     ░░   ░      ░░     ░     ░░   ░ \n", 1);
	ft_putstr_fd("      ░     ░  ░   ░           ░     ░  ░   ░     \n", 1);
	ft_putstr_fd("                              ░                   \n", 1);
	ft_putstr_fd("                    PID : ", 1);
	ft_putnbr(getpid());
	ft_putchar('\n');
	ft_putstr_fd("░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n", 1);
	ft_putstr_fd("\033[0m", 1);
}

static void	ft_handler(int sig, siginfo_t *info, void *ucontext)
{
	static int		count;
	static int		c;
	static pid_t	client_pid;

	if (client_pid == 0)
		client_pid = info->si_pid;
	else if (client_pid != info->si_pid)
	{
		c = 0;
		count = 0;
		client_pid = info->si_pid;
	}
	if (sig == SIGUSR1 || sig == SIGUSR2)
	{
		c *= 2;
		c += 1 * (sig == SIGUSR2);
		count++;
	}
	if (count == 8)
	{
		ft_putchar(c);
		c = 0;
		count = 0;
	}
	(void)(ucontext);
}

int	main(void)
{
	struct sigaction	sa;

	ft_print_server_header();
	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = ft_handler;
	if (sigaction(SIGUSR1, &sa, NULL) == -1)
	{
		ft_putstr_fd("something went wrong\n", 2);
		exit(4);
	}
	if (sigaction(SIGUSR2, &sa, NULL) == -1)
	{
		ft_putstr_fd("something went wrong\n", 2);
		exit(5);
	}
	while (1)
		pause();
	return (0);
}
