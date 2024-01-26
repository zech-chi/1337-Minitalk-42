/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zech-chi <zech-chi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 19:39:20 by zech-chi          #+#    #+#             */
/*   Updated: 2024/01/26 17:05:08 by zech-chi         ###   ########.fr       */
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
	ft_putstr_fd("bonus               PID : ", 1);
	ft_putnbr(getpid());
	ft_putchar('\n');
	ft_putstr_fd("░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n", 1);
	ft_putstr_fd("\033[0m", 1);
}

static void	ft_check_end_msg(int *c, pid_t client_pid)
{
	if (*c == 0)
	{
		if (kill(client_pid, SIGUSR1) == -1)
		{
			ft_putstr_fd("Can't send the signal\n", 2);
			exit(3);
		}
	}
	*c = 0;
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
		ft_check_end_msg(&c, client_pid);
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
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		usleep(100);
	return (0);
}
