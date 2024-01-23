/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zech-chi <zech-chi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 12:12:30 by zech-chi          #+#    #+#             */
/*   Updated: 2024/01/23 19:21:14 by zech-chi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	ft_print_server_header()
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

void	ft_handle_0(int sig)
{
	sig = sig -1 + 1;
	ft_putchar('0');
}

void	ft_handle_1(int sig)
{
	sig = sig -1 + 1;
	ft_putchar('1');
}

int	main(void)
{
	ft_print_server_header();
	while (1)
	{
		signal(SIGUSR1, ft_handle_0);
		signal(SIGUSR2, ft_handle_1);
		usleep(400);
	}
	return (0);
}