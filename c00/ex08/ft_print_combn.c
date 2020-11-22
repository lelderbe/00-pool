/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lelderbe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/10 22:04:01 by lelderbe          #+#    #+#             */
/*   Updated: 2020/09/10 22:51:53 by lelderbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_print(int value, int size)
{



	if (value == 0 && size == 1)
	{
		return 0;
	}
	else
	{
		write(1, value, 1);
		return value;
	}

	if (size == 1)
	{

		if (value == 0) {
			write(1, 0, 1);
		} 
	}

	if (ft_print(value / 10, size - 1) != -1) {
		
	}
}

void	ft_print_combn(int n)
{

	



	char arr[n];
	int count;

	count = 0;
	while (count < n)
	{
		arr[coint] = '0';
		count++;
	}

	while (arr[0] <= '9')
	{
		arr[n - 1] = arr[n - 1] + 1;
	}

	count = 0;
	while (count < 100)
	{
		
	}

	
}
