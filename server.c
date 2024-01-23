/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zech-chi <zech-chi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 12:12:30 by zech-chi          #+#    #+#             */
/*   Updated: 2024/01/23 13:14:04 by zech-chi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

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
	ft_putstr_fd("Server PID : ", 1);
	ft_putnbr(getpid());
	ft_putchar('\n');
	signal(SIGUSR1, ft_handle_0);
	signal(SIGUSR2, ft_handle_1);
	while (1);
	return (0);
}