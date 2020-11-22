/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lelderbe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/10 21:29:22 by lelderbe          #+#    #+#             */
/*   Updated: 2020/09/24 13:04:22 by lelderbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putnbr(int nb)
{
	char c;
	char sign;

	sign = '-';
	if (nb >= 10 || nb <= -10)
	{
		ft_putnbr(nb / 10);
	}
	if (nb < 0)
	{
		c = '0' + (-1) * (nb % 10);
	}
	else
	{
		c = '0' + nb % 10;
	}
	if (nb < 0 && nb > -10)
	{
		write(1, &sign, 1);
	}
	write(1, &c, 1);
}
