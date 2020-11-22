/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lelderbe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/23 11:21:30 by lelderbe          #+#    #+#             */
/*   Updated: 2020/09/23 21:40:45 by lelderbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "do_op.h"

int		ft_get_operation_index(char op)
{
	if (op == '+')
		return (0);
	else if (op == '-')
		return (1);
	else if (op == '*')
		return (2);
	else if (op == '/')
		return (3);
	else if (op == '%')
		return (4);
	return (-1);
}

int		ft_check_correct(int op, int y)
{
	int result;

	result = 1;
	if (op == 3 && y == 0)
	{
		ft_putstr("Stop : division by zero\n");
		result = 0;
	}
	if (op == 4 && y == 0)
	{
		ft_putstr("Stop : modulo by zero\n");
		result = 0;
	}
	return (result);
}

int		main(int argc, char **argv)
{
	int (*f[5])(int, int);
	int x;
	int y;
	int op_index;
	int result;

	if (argc != 4)
		return (0);
	f[0] = &sum;
	f[1] = &minus;
	f[2] = &mult;
	f[3] = &div;
	f[4] = &mod;
	x = ft_atoi(argv[1]);
	y = ft_atoi(argv[3]);
	op_index = ft_get_operation_index(*argv[2]);
	result = 0;
	if (!ft_check_correct(op_index, y))
		return (0);
	if (op_index != -1)
		result = f[op_index](x, y);
	ft_putnbr(result);
	ft_putstr("\n");
	return (0);
}
