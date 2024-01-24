/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zech-chi <zech-chi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 19:39:12 by zech-chi          #+#    #+#             */
/*   Updated: 2024/01/24 19:39:37 by zech-chi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk.h"

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
			if (kill(pid, SIGUSR2) == -1)
			{
				ft_putstr_fd("Can't send the signal\n", 2);
				exit(3);
			}
		}
		else
		{
			if (kill(pid, SIGUSR1) == -1)
			{
				ft_putstr_fd("Can't send the signal\n", 2);
				exit(4);
			}
		}
		usleep(1000);
	}
}

int	main(int ac, char **av)
{
	int		something_wrong;
	pid_t	pid;
	size_t	i;

	if (ac != 3)
		return (ft_putstr_fd("The client takes two parameters\n", 2), 0);
	something_wrong = 0;
	pid = ft_atoi_plus(av[1], &something_wrong);
	if (something_wrong || pid < 0)
		return (ft_putstr_fd("Invalid server PID.\n", 2), 0);
	i = 0;
	while (av[2][i])
		ft_send_byte(pid, av[2][i++]);
	return (0);
}
