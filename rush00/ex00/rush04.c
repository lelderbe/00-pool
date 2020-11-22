/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush04.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lelderbe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/13 13:58:31 by lelderbe          #+#    #+#             */
/*   Updated: 2020/09/13 13:59:18 by lelderbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

char	ft_get_char(int row, int column, int row_max, int column_max)
{
	char result;

	result = 'B';
	if (column > 1 && column < column_max && row > 1 && row < row_max)
	{
		result = ' ';
	}
	if ((row == 1 && column == 1) || (row == row_max && column == column_max))
	{
		result = 'A';
	}
	if (row == 1 && column == column_max && column != 1)
	{
		result = 'C';
	}
	if (row == row_max && column == 1 && row != 1)
	{
		result = 'C';
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
