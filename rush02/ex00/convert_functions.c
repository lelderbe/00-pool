/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_functions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lelderbe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/27 19:02:13 by lelderbe          #+#    #+#             */
/*   Updated: 2020/09/27 20:16:31 by lelderbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_rush.h"

int		try3(char *str, t_elem **dict, t_list **answer)
{
	char	c;
	char	*value;

	if (ft_strlen(str) == 3)
	{
		if (str[0] != '0')
		{
			c = str[1];
			str[1] = 0;
			value = get_value_by_key(str, dict);
			if (!value)
				return (-1);
			ft_list_push_back(answer, value);
			str[1] = c;
			value = get_value_by_length(3, dict);
			if (!value)
				return (-1);
			ft_list_push_back(answer, value);
		}
		str++;
	}
	return (0);
}

int		try2(char *str, t_elem **dict, t_list **answer)
{
	char	*value;
	char	c;

	if (str[0] == '0')
		return (1);
	if (str[0] == '1' || (str[0] != 1 && str[1] == '0'))
	{
		if (!(value = get_value_by_key(str, dict)))
			return (-1);
	}
	else
	{
		c = str[1];
		str[1] = '0';
		if (!(value = get_value_by_key(str, dict)))
			return (-1);
		ft_list_push_back(answer, value);
		str[1] = c;
		return (1);
	}
	ft_list_push_back(answer, value);
	return (0);
}

int		try_suffix(t_elem **dict, int suffix, t_list **answer)
{
	char	*value;

	if (suffix)
	{
		if (!(value = get_value_by_length(suffix * 3 + 1, dict)))
			return (-1);
		ft_list_push_back(answer, value);
	}
	return (0);
}

int		do3(char *str, t_elem **dict, int suffix, t_list **answer)
{
	char	*value;
	int		result;

	if (ft_strlen(str) == 3)
	{
		if (try3(str, dict, answer) == -1)
			return (-1);
		str++;
	}
	if (ft_strlen(str) == 2)
	{
		if ((result = try2(str, dict, answer)) == -1)
			return (-1);
		str = str + result;
	}
	if (ft_strlen(str) == 1 && str[0] != '0')
	{
		if (!(value = get_value_by_key(str, dict)))
			return (-1);
		ft_list_push_back(answer, value);
	}
	if (try_suffix(dict, suffix, answer) == -1)
		return (-1);
	return (0);
}
