/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wstaedmo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 12:42:50 by wstaedmo          #+#    #+#             */
/*   Updated: 2020/09/30 22:19:40 by lelderbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_bsq.h"

/*
** check lines length (must be equal)
*/

int		valid_lines_length_equal(char **data)
{
	long	i;
	long	length;

	length = ft_strlen(data[1]);
	i = 2;
	while (data[i])
	{
		if (ft_strlen(data[i]) != length)
			return (0);
		i++;
	}
	return (1);
}

/*
** check lines count
*/

int		valid_lines_count(char **data)
{
	long	i;
	long	length;
	long	lines;
	char	c;

	length = ft_strlen(data[0]);
	c = data[0][length - 3];
	data[0][length - 3] = 0;
	lines = ft_atoi(data[0]);
	data[0][length - 3] = c;
	if (lines == 0)
		return (0);
	i = 0;
	while (data[i + 1])
		i++;
	if (lines != i)
		return (0);
	return (1);
}

/*
** check arguments (count, unique)
*/

int		valid_count_arguments_and_unique(char **data)
{
	long	length;
	char	empty;
	char	obstacle;
	char	full;

	length = ft_strlen(data[0]);
	if (length < 4)
		return (0);
	empty = data[0][length - 3];
	obstacle = data[0][length - 2];
	full = data[0][length - 1];
	if (empty == obstacle || empty == full || obstacle == full)
		return (0);
	return (1);
}

/*
** check number in first line (count lines in map)
*/

int		valid_first_number(char **data)
{
	long	length;
	long	i;

	length = ft_strlen(data[0]);
	i = 0;
	while (i < length - 3)
	{
		if (data[0][i] < '0' || data[0][i] > '9')
			return (0);
		i++;
	}
	return (1);
}

/*
** check lines for forbidden characters
*/

int		valid_only_right_chars(char **data)
{
	long	i;
	long	j;
	char	empty;
	char	obstacle;

	empty = data[0][ft_strlen(data[0]) - 3];
	obstacle = data[0][ft_strlen(data[0]) - 2];
	i = 1;
	while (data[i] != '\0')
	{
		j = 0;
		while (data[i][j] != '\0')
		{
			if (data[i][j] != empty && data[i][j] != obstacle)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
