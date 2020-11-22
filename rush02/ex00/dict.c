/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lelderbe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/26 17:37:30 by lelderbe          #+#    #+#             */
/*   Updated: 2020/09/27 19:27:19 by lelderbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_rush.h"

t_elem	**dict_init(char *filename)
{
	t_elem	**result;
	char	**rows;
	char	**pair;
	int		i;
	int		count;

	rows = ft_split(get_file_contents(filename), '\n');
	count = 0;
	i = 0;
	while (rows[i++])
	{
		count++;
		//i++;
	}
	result = malloc(sizeof(*result) * (count + 1));
	i = 0;
	while (*rows)
	{
		pair = ft_split(*rows, ':');
		if (pair)
		{
			result[i] = create_elem(pair[0], pair[1]);
			i++;
		}
		rows++;
	}
	return (result);
}

void	dict_print(t_elem **dict)
{
	int i;

	i = 0;
	while (dict[i])
	{
		ft_putstr(dict[i]->key);
		ft_putstr(" : ");
		ft_putstr(dict[i]->value);
		ft_putstr("\n");
		i++;
	}
}
