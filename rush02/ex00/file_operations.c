/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lelderbe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/26 19:35:39 by lelderbe          #+#    #+#             */
/*   Updated: 2020/09/27 16:46:33 by lelderbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_rush.h"

int		get_file_size(char *filename)
{
	int		file;
	int		count;
	int		bytes;
	char	buf[100];

	bytes = 0;
	file = open(filename, O_RDONLY);
	if (file == -1)
	{
		return (0);
	}
	while ((count = read(file, buf, 100)))
	{
		if (count != -1)
		{
			bytes = bytes + count;
		}
		else
		{
			break ;
		}
	}
	close(file);
	return (bytes);
}

int		get_file_rows_count(char *filename)
{
	int		file;
	int		count;
	int		rows;
	char	buf[1];

	rows = 0;
	file = open(filename, O_RDONLY);
	if (file == -1)
		return (0);
	while ((count = read(file, buf, 1)))
	{
		if (count != -1)
		{
			if (buf[0] == '\n')
				rows++;
		}
		else
		{
			break ;
		}
	}
	close(file);
	return (rows);
}

char	*get_file_contents(char *filename)
{
	char	*result;
	int		file;
	int		size;
	int		count;

	size = get_file_size(filename);
	file = open(filename, O_RDONLY);
	if (file == -1)
	{
		return (0);
	}
	result = malloc(sizeof(*result) * (size + 1));
	count = read(file, result, size);
	if (count == -1 || count != size)
		return (0);
	result[count] = '\0';
	return (result);
}
