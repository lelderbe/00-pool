/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lelderbe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/10 20:44:14 by lelderbe          #+#    #+#             */
/*   Updated: 2020/09/10 21:25:35 by lelderbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_value(char a1, char a2, char b1, char b2)
{
	char delimiter[2];
	char space;

	delimiter[0] = ',';
	delimiter[1] = ' ';
	space = ' ';
	if (!(a1 == '0' && a2 == '0' && b1 == '0' && b2 == '1'))
	{
		write(1, &delimiter, 2);
	}
	write(1, &a1, 1);
	write(1, &a2, 1);
	write(1, &space, 1);
	write(1, &b1, 1);
	write(1, &b2, 1);
}

void	ft_print_comb2(void)
{
	char a1;
	char a2;
	char b1;
	char b2;

	a1 = '0' - 1;
	while (++a1 <= '9')
	{
		a2 = '0' - 1;
		while (++a2 <= '9')
		{
			b1 = a1 - 1;
			while (++b1 <= '9')
			{
				b2 = '0' - 1;
				while (++b2 <= '9')
				{
					if ((a1 == b1 && a2 < b2) || (a1 < b1))
						ft_print_value(a1, a2, b1, b2);
				}
			}
		}
	}
}
