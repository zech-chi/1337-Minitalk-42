/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zech-chi <zech-chi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 12:12:30 by zech-chi          #+#    #+#             */
/*   Updated: 2024/01/25 18:08:52 by zech-chi         ###   ########.fr       */
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
	static int	count;
	static int	c;

	if (sig == SIGUSR1)
	{
		c *= 2;
		count++;
	}
	else if (sig == SIGUSR2)
	{
		c *= 2;
		c += 1;
		count++;
	}
	if (count == 8)
	{
		ft_putchar(c);
		c = 0;
		count = 0;
	}
	(void)(info);
	(void)(ucontext);
}

int	main(void)
{
	struct sigaction	sa;

	ft_print_server_header();
	sa.sa_flags = 0;
	sa.sa_sigaction = ft_handler;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		usleep(100);
	return (0);
}
