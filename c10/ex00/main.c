/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lelderbe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/21 14:39:45 by lelderbe          #+#    #+#             */
/*   Updated: 2020/09/22 10:52:26 by lelderbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_display_file.h"

int		main(int argc, char **argv)
{
	if (argc < 2)
		ft_puterrstr("File name missing.\n");
	else if (argc > 2)
		ft_puterrstr("Too many arguments.\n");
	else
		ft_display_file(argv[1]);
	return (0);
}
