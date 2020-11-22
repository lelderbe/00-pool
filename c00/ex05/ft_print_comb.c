/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lelderbe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/10 16:16:11 by lelderbe          #+#    #+#             */
/*   Updated: 2020/09/10 20:39:09 by lelderbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_value(char a, char b, char c, int count)
{
	char delimiter[2];

	delimiter[0] = ',';
	delimiter[1] = ' ';
	if (count)
	{
		write(1, &delimiter, 2);
	}
	write(1, &a, 1);
	write(1, &b, 1);
	write(1, &c, 1);
}

void	ft_print_comb(void)
{
	int		count;
	char	a;
	char	b;
	char	c;

	count = 0;
	a = '0';
	while (a <= '9')
	{
		b = a + 1;
		while (b <= '9')
		{
			c = b + 1;
			while (c <= '9')
			{
				ft_print_value(a, b, c, count++);
				c++;
			}
			b++;
		}
		a++;
	}
}
