/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bruteforce.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lelderbe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 20:17:31 by lelderbe          #+#    #+#             */
/*   Updated: 2020/09/30 22:24:45 by lelderbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_bsq.h"

/*
** check, if this square doesn't intersect obstacles
*/

int			check_square_on_map(t_square *square, t_map *map)
{
	long x;
	long y;

	if (!square || !map)
		return (0);
	x = square->x1;
	while (x <= square->x1 + square->dx)
	{
		y = square->y1;
		while (y <= square->y1 + square->dx)
		{
			if (map->map[x][y] != map->empty)
			{
				return (0);
			}
			y++;
		}
		x++;
	}
	return (1);
}

/*
** find next square start from (x, y) with dx, increase dx by 1
*/

t_square	*find_square(long x, long y, t_map *map, long dx)
{
	t_square	*result;
	t_square	*square;

	result = get_new_square();
	square = get_new_square();
	if (!result || !square)
		return (0);
	while (x + dx < map->lines)
	{
		if (y + dx < map->columns)
		{
			update_square_data(square, x, y, dx);
			if (check_square_on_map(square, map))
				*result = *square;
			else
				break ;
		}
		dx++;
	}
	free(square);
	return (result);
}

/*
** print found maximum square on the map
*/

void		add_square_on_map(t_map *map, t_square *square)
{
	long x;
	long y;

	if (!square)
		return ;
	x = square->x1;
	while (x <= square->x1 + square->dx)
	{
		y = square->y1;
		while (y <= square->y1 + square->dx)
		{
			map->map[x][y] = map->full;
			y++;
		}
		x++;
	}
}

/*
** get next maximum square (or nothing)
*/

t_square	*check_next_cell(long x, long y, t_map *map, t_square *max_square)
{
	t_square	*next_square;

	if (max_square)
		next_square = find_square(x, y, map, max_square->dx + 1);
	else
		next_square = find_square(x, y, map, 0);
	if (square_valid(next_square))
	{
		free(max_square);
		max_square = next_square;
	}
	else
		free(next_square);
	return (max_square);
}

/*
** start bruteforce from top left (0, 0)
*/

void		bruteforce(t_map *map)
{
	long		i;
	long		j;
	t_square	*max_square;

	max_square = get_new_square();
	i = 0;
	while (i < map->lines)
	{
		j = 0;
		while (j < map->columns)
		{
			max_square = check_next_cell(i, j, map, max_square);
			j++;
		}
		i++;
	}
	add_square_on_map(map, max_square);
	free(max_square);
}
