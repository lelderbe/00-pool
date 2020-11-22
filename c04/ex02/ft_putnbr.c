/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lelderbe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/14 12:48:29 by lelderbe          #+#    #+#             */
/*   Updated: 2020/09/14 18:24:19 by lelderbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putnbr(int nb)
{
	char	*digits;
	int		sign;

	digits = "0123456789";
	sign = 1;
	if (nb >= 10 || nb <= -10)
	{
		ft_putnbr(nb / 10);
	}
	else
	{
		if (nb < 0)
		{
			write(1, "-", 1);
		}
	}
	if (nb < 0)
	{
		sign = -1;
	}
	write(1, &digits[(nb % 10) * sign], 1);
}
