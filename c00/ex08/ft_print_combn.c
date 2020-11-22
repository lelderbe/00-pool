#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	print_comb(int nbr, int n, int delimiter)
{
	if (delimiter)
	{
		ft_putchar(',');
		ft_putchar(' ');
	}
	if (nbr / 10)
	{
		print_comb(nbr / 10, n - 1, 0);
	}
	else if (n - 1)
	{
		ft_putchar('0');
	}
	ft_putchar('0' + (nbr % 10));
}

int		check_comb(int nbr, int n)
{
	while (nbr / 10)
	{
		if (nbr % 10 <= (nbr / 10) % 10)
			return (0);
		nbr = nbr / 10;
		n--;
	}
	if (n > 2)
		return (0);
	return (1);
}

void	ft_print_combn(int n)
{
	int i;
	int max;
	int delimiter;

	delimiter = 0;
	max = 1;
	i = 0;
	while (i < n)
	{
		max = max * 10;
		i++;
	}
	i = 0;
	while (i < max)
	{
		if (check_comb(i, n))
		{
			print_comb(i, n, delimiter);
			delimiter = 1;
		}
		i++;
	}
}
