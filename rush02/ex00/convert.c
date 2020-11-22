/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lelderbe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/27 11:08:01 by lelderbe          #+#    #+#             */
/*   Updated: 2020/09/27 20:32:39 by lelderbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_rush.h"

void	key_prepare(char *key)
{
	int	i;

	while (ft_strlen(key) > 1 && key[0] == '0')
	{
		i = 0;
		while (key[i])
		{
			key[i] = key[i + 1];
			i++;
		}
	}
}

int		convert0(char *key, t_elem **dict, t_list **answer)
{
	char	c;

	*answer = 0;
	key_prepare(key);
	if (get_value_by_key(key, dict))
	{
		if (ft_strlen(key) > 2)
		{
			c = key[1];
			key[1] = 0;
			ft_list_push_back(answer, get_value_by_key(key, dict));
			key[1] = c;
		}
		ft_list_push_back(answer, get_value_by_key(key, dict));
		return (0);
	}
	else
		return (convert(key, dict, answer));
}

int		check_zeros(char *key)
{
	int count;
	int i;

	i = 0;
	count = 0;
	while (i < ft_strlen(key))
	{
		if (key[i] != '0')
			count = 1;
		i++;
	}
	return (count);
}

int		get_suffix(char *key)
{
	int suffix;

	suffix = 0;
	if (ft_strlen(key) > 3)
	{
		if (ft_strlen(key) % 3 != 0)
			suffix = ft_strlen(key) / 3;
		else
			suffix = ft_strlen(key) / 3 - 1;
	}
	return (suffix);
}

int		convert(char *key, t_elem **dict, t_list **answer)
{
	char	part[4];
	int		i;
	int		suffix;

	if (check_zeros(key) != 1)
		return (0);
	suffix = get_suffix(key);
	if (ft_strlen(key) > 3)
	{
		if (ft_strlen(key) % 3)
			i = (ft_strlen(key) % 3);
		else
			i = 3;
		ft_strncpy(part, key, 0, i);
		if (do3(part, dict, suffix, answer) == -1)
			return (-1);
		while (i-- > 0)
			key++;
		return (convert(key, dict, answer));
	}
	else
	{
		ft_strncpy(part, key, 0, ft_strlen(key));
		if (do3(part, dict, suffix, answer) == -1)
			return (-1);
	}
	return (0);
}
