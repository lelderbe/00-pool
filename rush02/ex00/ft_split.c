/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lelderbe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/26 23:34:57 by lelderbe          #+#    #+#             */
/*   Updated: 2020/09/27 16:59:52 by lelderbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_rush.h"

int		get_char_count(char *str, char c)
{
	int		count;
	int		i;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == c)
			count++;
		i++;
	}
	return (count);
}

char	**ft_split(char *str, char delimiter)
{
	char	**result;
	int		i;
	int		from;
	int		count;
	int		lines;
	int		k;

	count = get_char_count(str, delimiter);
	if (count == 0)
		return (0);
	lines = count + 1;
	result = malloc(sizeof(*result) * (lines + 1));
	i = 0;
	from = 0;
	count = 0;
	k = 0;
	while (str[i])
	{
		if (str[i] != delimiter)
			count++;
		else
		{
			result[k] = malloc(sizeof(**result) * (count + 1));
			ft_strncpy(result[k], str, from, count);
			from = from + count + 1;
			count = 0;
			k++;
		}
		i++;
	}
	if (count != 0)
	{
		result[k] = malloc(sizeof(**result) * (count + 1));
		ft_strncpy(result[k], str, from, count);
		k++;
	}
	if (k <= lines)
		result[k + 1] = 0;
	return (result);
}
