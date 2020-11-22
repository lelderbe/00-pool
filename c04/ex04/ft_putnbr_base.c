/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lelderbe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/14 16:43:59 by lelderbe          #+#    #+#             */
/*   Updated: 2020/09/14 21:42:04 by lelderbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_digit(int num, char *base, int base_num)
{
	int sign;

	sign = 1;
	if (num < 0)
	{
		sign = -1;
	}
	if (num / base_num * sign > 0)
	{
		ft_print_digit(num / base_num, base, base_num);
	}
	write(1, &base[(num % base_num) * sign], 1);
}

void	ft_print_sign(int num)
{
	if (num < 0)
	{
		write(1, "-", 1);
	}
}

int		ft_check_base_is_valid(char *base, int length)
{
	int i;
	int j;
	int result;

	result = 1;
	if (length < 2)
		result = 0;
	i = 0;
	while (i < length - 1)
	{
		j = i + 1;
		while (j < length)
		{
			if (base[i] == base[j])
			{
				result = 0;
			}
			j++;
		}
		if (base[i] == '+' || base[i] == '-')
			result = 0;
		i++;
	}
	return (result);
}

int		ft_get_base_length(char *base)
{
	int result;

	result = 0;
	while (base[result] != '\0')
	{
		result++;
	}
	return (result);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int count;
	int base_is_valid;

	count = ft_get_base_length(base);
	base_is_valid = ft_check_base_is_valid(base, count);
	if (base_is_valid)
	{
		ft_print_sign(nbr);
		ft_print_digit(nbr, base, count);
	}
}
