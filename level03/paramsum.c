// Write a program that displays the number of arguments passed to it, followed by a newline.
// If there are no arguments, just display a 0 followed by a newline
#include <unistd.h>

void	ft_putnbr(int nbr)
{
	char c;
	
	if (nbr < 10)
	{
		c = nbr + '0';
		write(1, &c, 1);
	}
	else
	{
		ft_putnbr(nbr / 10);
		ft_putnbr(nbr % 10);
	}
}

int	main(int argc, char **argv)
{
	ft_putnbr(argc - 1);
	write(1, "\n", 1);
	return (0);
}
