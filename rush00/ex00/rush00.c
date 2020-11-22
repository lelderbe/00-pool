/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lelderbe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/13 13:21:14 by lelderbe          #+#    #+#             */
/*   Updated: 2020/09/13 13:25:30 by lelderbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

char	ft_get_char(int row, int column, int row_max, int column_max)
{
	char result;

	result = 'o';
	if (column > 1 && column < column_max && row > 1 && row < row_max)
	{
		result = ' ';
	}
	else if (row == 1 || row == row_max)
	{
		if (column > 1 && column < column_max)
		{
			result = '-';
		}
	}
	else if (column == 1 || column == column_max)
	{
		if (row > 1 && row <= row_max)
		{
			result = '|';
		}
	}
	return (result);
}

void	rush(int x, int y)
{
	int row;
	int column;

	row = 1;
	while (row <= y)
	{
		column = 1;
		while (column <= x)
		{
			ft_putchar(ft_get_char(row, column, y, x));
			column++;
		}
		ft_putchar('\n');
		row++;
	}
}
