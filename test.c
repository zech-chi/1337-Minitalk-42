#include <stdio.h>
#include <signal.h>

void	ft_handle(int sig)
{
	printf("copy that %d\n", sig);
}

int	main()
{
	signal(SIGINT, ft_handle);
	signal(SIGTSTP, ft_handle);
	while (1);
	return (0);
}