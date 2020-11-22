/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lelderbe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/20 10:27:21 by lelderbe          #+#    #+#             */
/*   Updated: 2020/09/20 20:39:01 by lelderbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_matrix.h"

void	ft_read_input_data(char *str, int data[INPUT_DATA])
{
	int i;

	i = 0;
	while (*str)
	{
		if (*str != ' ')
		{
			data[i] = *str - '0';
			i++;
		}
		str++;
	}
}

void	ft_print_input_data(int data[INPUT_DATA])
{
	int i;

	i = 0;
	while (i < INPUT_DATA)
	{
		ft_putnbr(data[i]);
		ft_putchar(' ');
		i++;
	}
	ft_putchar('\n');
}

int		check(int data[INPUT_DATA], int matrix[CELLS])
{
	int solved;
	int value;
	int i;
	int j;
	int max;
	int data_index;
	int sum;

	solved = 1;
	data_index = 0;
	i = 0;
	while (i < COLUMNS)
	{
		j = 0;
		value = 0;
		max = 0;
		sum = 0;
		while (j < COLUMNS)
		{
			sum = sum + matrix[i + j * COLUMNS];
			if (max < matrix[i + j * COLUMNS])
			{
				max = matrix[i + j * COLUMNS];
				value++;
			}
			j++;
		}
		if (data[data_index] != value)
			solved = 0;
		if (sum != SUM)
			solved = 0;
		i++;
		data_index++;
	}
	i = 0;
	while (i < COLUMNS)
	{
		value = 0;
		max = 0;
		j = COLUMNS - 1;
		sum = 0;
		while (j >= 0)
		{
			sum = sum + matrix[i + j * COLUMNS];
			if (max < matrix[i + j * COLUMNS])
			{
				max = matrix[i + j * COLUMNS];
				value++;
			}
			j--;
		}
		if (data[data_index] != value)
			solved = 0;
		if (sum != SUM)
			solved = 0;
		i++;
		data_index++;
	}
	i = 0;
	while (i < COLUMNS)
	{
		value = 0;
		max = 0;
		j = 0;
		sum = 0;
		while (j < COLUMNS)
		{
			sum = sum + matrix[i * COLUMNS + j];
			if (max < matrix[i * COLUMNS + j])
			{
				max = matrix[i * COLUMNS + j];
				value++;
			}
			j++;
		}
		if (data[data_index] != value)
			solved = 0;
		if (sum != SUM)
			solved = 0;
		i++;
		data_index++;
	}
	i = 0;
	while (i < COLUMNS)
	{
		value = 0;
		j = COLUMNS - 1;
		max = 0;
		sum = 0;
		while (j >= 0)
		{
			sum = sum + matrix[i * COLUMNS + j];
			if (max < matrix[i * COLUMNS + j])
			{
				max = matrix[i * COLUMNS + j];
				value++;
			}
			j--;
		}
		if (data[data_index] != value)
			solved = 0;
		if (sum != SUM)
			solved = 0;
		i++;
		data_index++;
	}
	return (solved);
}

int		solve(int x, int matrix[CELLS], int data[INPUT_DATA])
{
	int i;

	if (x == CELLS)
	{
		return (check(data, matrix));
	}
	i = 1;
	while (i <= COLUMNS)
	{
		matrix[x] = i;
		if (solve(x + 1, matrix, data))
		{
			return (1);
		}
		i++;
	}
	return (0);
}

int		main(int argc, char **argv)
{
	int matrix[CELLS];
	int data[INPUT_DATA];

	if (argc != 2)
		return (0);
	ft_read_input_data(argv[1], data);
	ft_clean_matrix(matrix);
	if (solve(0, matrix, data))
		ft_print_matrix(matrix);
	else
		ft_putstr("Error\n");
	return (0);
}
