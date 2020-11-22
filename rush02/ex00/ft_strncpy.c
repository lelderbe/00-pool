/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lelderbe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/26 23:32:16 by lelderbe          #+#    #+#             */
/*   Updated: 2020/09/27 16:47:51 by lelderbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_rush.h"

void	ft_strncpy(char *dst, char *src, int from, int count)
{
	int i;

	i = 0;
	while (src[from + i] && i < count)
	{
		dst[i] = src[from + i];
		i++;
	}
	dst[i] = '\0';
}
