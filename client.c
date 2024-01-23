/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zech-chi <zech-chi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 12:12:27 by zech-chi          #+#    #+#             */
/*   Updated: 2024/01/23 18:40:55 by zech-chi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static pid_t	ft_check_and_get_pid(int ac, char **av)
{
	int		something_wrong;
	pid_t	pid;

	if (ac != 3)
	{
		ft_putstr_fd("The client takes two parameters\n", 2);
		exit(1);
	}
	something_wrong = 0;
	pid = ft_atoi_plus(av[1], &something_wrong);
	if (something_wrong || pid < 0)
	{
		ft_putstr_fd("Invalid server PID.\n", 2);
		exit(2);
	}
	return (pid);
}

static void	ft_send_byte(pid_t pid, unsigned char c)
{
	int	j;
	int	i;

	i = 8;
	while (--i >= 0)
	{
		j = 1 << i;
		if (c & j)
		{
			ft_putchar('1');
			kill(pid, SIGUSR2);
		}
		else
		{
			ft_putchar('0');
			kill(pid, SIGUSR1);
		}
	}
}

int	main(int ac, char **av)
{
	pid_t	pid;
	size_t	i;

	pid = ft_check_and_get_pid(ac, av);
	i = 0;
	while (av[2][i])
		ft_send_byte(pid, av[2][i++]);
	//kill(pid, SIGUSR1);
	//kill(pid, SIGUSR2);
	return (0);
}