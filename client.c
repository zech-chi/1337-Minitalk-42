/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zech-chi <zech-chi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 12:12:27 by zech-chi          #+#    #+#             */
/*   Updated: 2024/01/23 12:53:11 by zech-chi         ###   ########.fr       */
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

int	main(int ac, char **av)
{
	pid_t pid;

	pid = ft_check_and_get_pid(ac, av);
	kill(pid, SIGUSR1);
	return (0);
}