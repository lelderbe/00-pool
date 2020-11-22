/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_map.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lelderbe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 19:20:02 by lelderbe          #+#    #+#             */
/*   Updated: 2020/09/30 22:17:23 by lelderbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_bsq.h"

/*
** check incoming map data
*/

int		valid_map_data(char **data)
{
	if (!valid_count_arguments_and_unique(data))
		return (0);
	if (!valid_first_number(data))
		return (0);
	if (!valid_lines_count(data))
		return (0);
	if (!valid_lines_length_equal(data))
		return (0);
	if (!valid_only_right_chars(data))
		return (0);
	return (1);
}

/*
** data is OK, fill map structure
*/

void	fill_map_obj(t_map *map, char **data)
{
	long	length;
	char	c;

	length = ft_strlen(data[0]);
	c = data[0][length - 3];
	data[0][length - 3] = 0;
	map->lines = ft_atoi(data[0]);
	data[0][length - 3] = c;
	map->empty = data[0][ft_strlen(data[0]) - 3];
	map->obstacle = data[0][ft_strlen(data[0]) - 2];
	map->full = data[0][ft_strlen(data[0]) - 1];
	map->columns = ft_strlen(data[1]);
	map->map = &data[1];
	map->data_ptr_for_free = data;
}

/*
** get a next map
*/

t_map	*get_map(char *filename)
{
	t_map	*result;
	char	*file_contents;
	char	**data;

	if (filename)
		file_contents = get_file_contents(filename);
	else
		file_contents = get_stdin_contents();
	if (!file_contents)
		return (0);
	data = ft_split(file_contents, '\n');
	free(file_contents);
	if (!data)
		return (0);
	if (!(result = malloc(sizeof(*result))))
		return (0);
	if (valid_map_data(data))
		fill_map_obj(result, data);
	else
	{
		free_split(data);
		free(result);
		result = 0;
	}
	return (result);
}

/*
** free map resources
*/

void	map_free(t_map *map)
{
	free_split(map->data_ptr_for_free);
	free(map);
}

/*
** print map
*/

void	map_print(t_map *map)
{
	long i;
	long j;

	if (!map && !(map->map))
		return ;
	i = 0;
	while (map->map[i])
	{
		j = 0;
		while (map->map[i][j])
		{
			ft_putchar(map->map[i][j]);
			j++;
		}
		i++;
		ft_putchar('\n');
	}
}
