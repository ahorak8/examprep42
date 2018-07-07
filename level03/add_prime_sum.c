// Write a program that takes a positive integer as argument and displays the sum
// of all prime numbers inferior or equal to it followed by a newline.
//
// If the number of arguments is not 1, or the argument is not a positive number,
// just display 0 followed by a newline.
#include <unistd.h>

int     ft_atoi(const char *str)
{
        int     i;
        int     nbr;
        int     sign;

        i = 0;
        nbr = 0;
        sign = 1;
        if (str == '\0')
                return (0);
        while (str[i] == '\n' || str[i] == '\t' || str[i] =='\r' || str[i] == '\v' || str[i] == '\f' || str[i] == ' ')
                i++;
        if (str[i] == '-')
                sign = -1;
        if (str[i] == '-' || str[i] == '+')
                i++;
        while (str[i] && (str[i] >= '0') && (str[i] <= '9'))
        {
                nbr = (nbr * 10) + (str[i] - '0');
                i++;
        }
        return (nbr * sign);
}

void	ft_putnbr(int nbr)
{
	char	c;
	
	if (nbr < 0)
	{
		nbr = -nbr;
		write(1, "-", 1);
	}
	else if (nbr < 10)
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

int	is_prime(int nbr)
{
	int	i;

	i = 2;
	if (nbr <= 0)
		return (0);
	while (i <= (nbr / 2))
	{
		if (!(nbr % i))
			return (0);
		else
			i += 1;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	int	nbr;
	int	sum;

	if (argc == 2)
	{
		nbr = ft_atoi(argv[1]);
		sum = 0;
		while (nbr > 1)
		{
			if (is_prime(nbr))
				sum = sum + (nbr);
			nbr--;
		}
		ft_putnbr(sum);
	}
	write(1, "\n", 1);
	return (0);
}
