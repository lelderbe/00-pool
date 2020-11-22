/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lelderbe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/21 13:16:53 by lelderbe          #+#    #+#             */
/*   Updated: 2020/09/22 17:37:58 by lelderbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_display_file.h"

void	ft_display_file(char *filename)
{
	int		count;
	int		file;
	char	buffer[BUFF_SIZE];

	file = open(filename, O_RDONLY);
	if (file == -1)
	{
		ft_puterrstr("Cannot read file.\n");
		return ;
	}
	while ((count = read(file, buffer, BUFF_SIZE)))
	{
		if (count == -1)
		{
			ft_puterrstr("Cannot read file.\n");
			break ;
		}
		write(1, buffer, count);
	}
	close(file);
}
