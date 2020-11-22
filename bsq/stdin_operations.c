/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stdin_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lelderbe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 12:26:39 by lelderbe          #+#    #+#             */
/*   Updated: 2020/09/30 22:14:32 by lelderbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_bsq.h"

/*
** add count data to dst from src
*/

void	ft_stradd(char *dst, char *src, long from, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		dst[from + i] = src[i];
		i++;
	}
	dst[from + i] = 0;
}

/*
** read stdin and return data as char*
*/

char	*get_stdin_contents(void)
{
	char	*result;
	char	*tmp;
	long	count;
	long	size;
	char	buffer[100];

	result = 0;
	size = 0;
	while ((count = read(0, buffer, 100)))
	{
		if (count == -1)
			return (0);
		size = size + count;
		tmp = malloc(sizeof(*tmp) * (size + 1));
		if (result)
		{
			ft_strcpy(tmp, result);
			free(result);
		}
		ft_stradd(tmp, buffer, ft_strlen(tmp), count);
		result = tmp;
	}
	ft_putstr("\n");
	return (result);
}
