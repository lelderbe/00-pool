/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lelderbe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/22 16:03:06 by lelderbe          #+#    #+#             */
/*   Updated: 2020/09/23 15:26:00 by lelderbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		*ft_map(int *tab, int length, int (*f)(int))
{
	int i;
	int *arr;

	arr = 0;
	if (length > 0)
	{
		if ((arr = (int *)malloc(sizeof(*arr) * length)))
		{
			i = 0;
			while (i < length)
			{
				arr[i] = f(tab[i]);
				i++;
			}
		}
	}
	return (arr);
}
