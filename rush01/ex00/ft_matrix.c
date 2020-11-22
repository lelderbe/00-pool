/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_matrix.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lelderbe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/20 10:20:34 by lelderbe          #+#    #+#             */
/*   Updated: 2020/09/20 20:26:12 by lelderbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_matrix.h"

void	ft_clean_matrix(int matrix[CELLS])
{
	int i;

	i = 0;
	while (i < CELLS)
	{
		matrix[i] = 0;
		i++;
	}
}

void	ft_print_matrix(int matrix[CELLS])
{
	int i;

	i = 0;
	while (i < CELLS)
	{
		ft_putnbr(matrix[i]);
		ft_putchar(' ');
		i++;
		if (i % COLUMNS == 0)
			ft_putchar('\n');
	}
	ft_putchar('\n');
}
