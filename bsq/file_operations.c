/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lelderbe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 14:13:15 by lelderbe          #+#    #+#             */
/*   Updated: 2020/09/30 22:15:05 by lelderbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_bsq.h"

long	get_file_size(char *filename)
{
	int		file;
	long	count;
	long	bytes;
	char	buf[1024];

	bytes = 0;
	file = open(filename, O_RDONLY);
	if (file == -1)
	{
		return (-1);
	}
	while ((count = read(file, buf, 1024)))
	{
		if (count != -1)
		{
			bytes = bytes + count;
		}
		else
		{
			return (-1);
		}
	}
	close(file);
	return (bytes);
}

char	*get_file_contents(char *filename)
{
	char	*result;
	int		file;
	long	size;
	long	count;

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
