/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_filesize.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lelderbe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/22 22:29:54 by lelderbe          #+#    #+#             */
/*   Updated: 2020/09/22 22:37:05 by lelderbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_tail.h"

int		ft_get_filesize(char *filename)
{
	char	buffer[1];
	int		count;
	int		result;
	int		file;

	if ((file = open(filename, O_RDONLY)) == -1)
	{
		ft_puttailerrstr(filename);
		return (-1);
	}
	result = 0;
	while ((count = read(file, buffer, 1)))
	{
		if (count == -1)
		{
			ft_puttailerrstr(filename);
			close(file);
			return (-1);
		}
		result++;
	}
	close(file);
	return (result);
}
