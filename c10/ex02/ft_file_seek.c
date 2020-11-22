/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_file_seek.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lelderbe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/22 22:34:58 by lelderbe          #+#    #+#             */
/*   Updated: 2020/09/22 22:35:16 by lelderbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_tail.h"

int		ft_file_seek(int file, int count)
{
	char	buffer[1];
	int		i;

	i = 0;
	while (i < count)
	{
		read(file, buffer, 1);
		i++;
	}
	return (0);
}
