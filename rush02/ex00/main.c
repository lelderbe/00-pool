/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lelderbe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/26 13:37:15 by lelderbe          #+#    #+#             */
/*   Updated: 2020/09/27 20:32:22 by lelderbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_rush.h"

int		check_args(int argc, char **argv)
{
	int i;
	int j;

	if (argc == 1)
		return (-1);
	if (argc == 2)
		i = 1;
	if (argc == 3)
		i = 2;
	if (argc == 2 || argc == 3)
	{
		j = 0;
		while (argv[i][j])
		{
			if (argv[i][j] < '0' && argv[i][j] > '9')
				return (-1);
			j++;
		}
	}
	return (0);
}

int		main(int argc, char **argv)
{
	char	*filename;
	char	*number;
	t_elem	**dict;
	t_list	**answer;

	if (check_args(argc, argv) == -1)
	{
		ft_putstr("Error\n");
		return (0);
	}
	answer = malloc(sizeof(*answer));
	filename = "numbers.dict";
	number = argv[1];
	if (argc == 3)
	{
		filename = argv[1];
		number = argv[2];
	}
	dict = dict_init(filename);
	if (convert0(number, dict, answer) == -1)
		ft_putstr("Dict Error\n");
	else
		print_list(answer);
	free_data(dict);
	return (0);
}
