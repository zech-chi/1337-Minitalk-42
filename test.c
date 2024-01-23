#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	print_bits(unsigned char octet)
{
	int	j;
	int	i;

	i = 8;
	while (--i >= 0)
	{
		j = 1 << i;
		if (octet & j)
			ft_putchar('1');
		else
			ft_putchar('0');
	}
}

int	main(int ac, char **av)
{
	if (ac != 2)
		return (0);
	print_bits(av[1][0]);
	return (0);
}