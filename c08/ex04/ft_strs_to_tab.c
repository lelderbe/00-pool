/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lelderbe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/19 17:57:45 by lelderbe          #+#    #+#             */
/*   Updated: 2020/09/19 21:34:28 by lelderbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_str.h"
#include <stdlib.h>

int					ft_strlen(char *str)
{
	int result;

	result = 0;
	while (*str)
	{
		result++;
		str++;
	}
	return (result);
}

void				ft_strcpy(char *dst, char *src)
{
	while (*src)
	{
		*dst = *src;
		src++;
		dst++;
	}
	*dst = '\0';
}

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	int			i;
	t_stock_str	*result;

	if (!(result = malloc(sizeof(*result) * (ac + 1))))
		return (result);
	i = 0;
	while (i < ac)
	{
		result[i].size = ft_strlen(av[i]);
		if (!(result[i].str = malloc(sizeof(char *) * (result[i].size + 1))))
			return (0);
		ft_strcpy(result[i].str, av[i]);
		if (!(result[i].copy = malloc(sizeof(char *) * (result[i].size + 1))))
			return (0);
		ft_strcpy(result[i].copy, av[i]);
		i++;
	}
	result[i].size = 0;
	result[i].str = 0;
	result[i].copy = 0;
	return (result);
}
