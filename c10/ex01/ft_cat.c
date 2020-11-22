/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cat.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lelderbe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/21 14:05:34 by lelderbe          #+#    #+#             */
/*   Updated: 2020/09/22 21:32:48 by lelderbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cat.h"

char *g_name;

int		ft_putcaterrstr(char *filename)
{
	ft_puterrstr(g_name);
	ft_puterrstr(": ");
	ft_puterrstr(filename);
	ft_puterrstr(": ");
	ft_puterrstr(strerror(errno));
	ft_puterrstr("\n");
	return (errno);
}

int		ft_check_filename(char *filename)
{
	int i;
	int count;

	i = 0;
	count = 0;
	while (filename[i])
	{
		count++;
		i++;
	}
	if (count == 1 && *filename == '-')
		return (1);
	return (0);
}

int		ft_cat_stdin(void)
{
	int		count;
	int		file;
	char	buffer[BUFF_SIZE];

	file = 0;
	while ((count = read(file, buffer, BUFF_SIZE)))
	{
		if (count == -1)
			return (ft_putcaterrstr(""));
		write(1, buffer, count);
	}
	return (0);
}

int		ft_cat(char *filename)
{
	int		count;
	int		file;
	char	buffer[BUFF_SIZE];
	int		error_num;

	if (ft_check_filename(filename))
		return (ft_cat_stdin());
	if ((file = open(filename, O_RDONLY)) == -1)
		return (ft_putcaterrstr(filename));
	while ((count = read(file, buffer, BUFF_SIZE)))
	{
		if (count == -1)
		{
			error_num = ft_putcaterrstr(filename);
			close(file);
			return (error_num);
		}
		write(1, buffer, count);
	}
	if (close(file) == -1)
		return (ft_putcaterrstr(filename));
	return (0);
}

int		main(int argc, char **argv)
{
	int i;
	int result;

	g_name = basename(argv[0]);
	result = 0;
	if (argc == 1)
		return (ft_cat_stdin());
	i = 1;
	while (i < argc)
	{
		if (ft_cat(argv[i]))
			result = 1;
		i++;
	}
	return (result);
}
