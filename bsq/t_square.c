/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_square.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lelderbe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 19:06:54 by lelderbe          #+#    #+#             */
/*   Updated: 2020/09/30 22:17:47 by lelderbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_bsq.h"

/*
** get a new square
*/

t_square	*get_new_square(void)
{
	t_square	*result;

	result = malloc(sizeof(*result));
	if (!result)
		return (0);
	result->x1 = -1;
	result->y1 = -1;
	result->dx = -1;
	return (result);
}

/*
** update square's data
*/

void		update_square_data(t_square *square, long x1, long y1, long dx)
{
	if (!square)
		return ;
	square->x1 = x1;
	square->y1 = y1;
	square->dx = dx;
}

/*
** check if square is valid
*/

int			square_valid(t_square *square)
{
	if (!square)
		return (0);
	if (square->x1 == -1)
		return (0);
	return (1);
}
