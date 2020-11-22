/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wstaedmo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 13:03:11 by wstaedmo          #+#    #+#             */
/*   Updated: 2020/09/30 22:12:31 by lelderbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_bsq.h"

long	count_lines(char *str, char sep)
{
	long i;
	long count;

	count = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == sep)
			count++;
		i++;
	}
	return (count);
}

char	**fill(char *str, char **result, char sep)
{
	long	i;
	long	j;
	long	z;
	long	lines;

	i = 0;
	j = 0;
	z = 0;
	lines = count_lines(str, sep);
	while (j < lines)
	{
		if (str[i] != sep)
		{
			result[j][z] = str[i];
			z++;
		}
		else
		{
			result[j][z] = '\0';
			j++;
			z = 0;
		}
		i++;
	}
	return (result);
}

char	**ft_split(char *str, char sep)
{
	long	i;
	long	z;
	long	count;
	char	**result;
	long	lines;

	i = 0;
	z = 0;
	count = 0;
	lines = count_lines(str, sep);
	result = (char**)malloc(sizeof(*result) * (lines + 1));
	while (z < lines)
	{
		if (str[i] != sep)
			count++;
		else
		{
			result[z] = (char*)malloc(sizeof(**result) * (count + 1));
			z++;
			count = 0;
		}
		i++;
	}
	result[lines] = 0;
	return (fill(str, result, sep));
}

void	free_split(char **str)
{
	long	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}
