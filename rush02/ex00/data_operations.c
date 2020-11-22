/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lelderbe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/27 16:26:59 by lelderbe          #+#    #+#             */
/*   Updated: 2020/09/27 19:09:34 by lelderbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_rush.h"

t_elem	*create_elem(char *key, char *value)
{
	t_elem	*result;

	if ((result = malloc(sizeof(*result))))
	{
		result->key = key;
		result->value = value;
	}
	return (result);
}

char	*get_value_by_key(char *key, t_elem **dict)
{
	char	*result;
	int		i;

	result = 0;
	i = 0;
	while (dict[i])
	{
		if (ft_strcmp(dict[i]->key, key) == 0 && !result)
		{
			result = dict[i]->value;
		}
		i++;
	}
	return (result);
}

char	*get_value_by_length(int length, t_elem **dict)
{
	char	*result;
	int		i;

	result = 0;
	i = 0;
	while (dict[i])
	{
		if (ft_strlen(dict[i]->key) == length && !result)
		{
			result = dict[i]->value;
		}
		i++;
	}
	return (result);
}

void	print_list(t_list **answer)
{
	t_list	*elem;

	elem = *answer;
	while (elem)
	{
		ft_putstr(elem->data);
		ft_putstr(" ");
		elem = elem->next;
	}
	ft_putstr("\n");
}

void	free_data(t_elem **dict)
{
	int i;

	i = 0;
	while (dict[i])
	{
		free(dict[i]->key);
		free(dict[i]->value);
		free(dict[i]);
		i++;
	}
	free(dict);
}
