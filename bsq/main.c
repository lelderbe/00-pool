/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wstaedmo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 11:33:20 by wstaedmo          #+#    #+#             */
/*   Updated: 2020/09/30 17:43:46 by lelderbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_bsq.h"

int	main(int argc, char **argv)
{
	char	*filename;
	t_map	*map;
	int		i;

	filename = 0;
	i = (argc == 1) ? 0 : 1;
	while (argc > i)
	{
		if (argc != 1)
			filename = argv[i];
		if (!(map = get_map(filename)))
		{
			ft_puterrstr("map error\n");
		}
		else
		{
			bruteforce(map);
			map_print(map);
			map_free(map);
			if (argc == 1)
				return (0);
		}
		i++;
	}
	return (0);
}
