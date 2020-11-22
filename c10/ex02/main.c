/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lelderbe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/21 18:54:21 by lelderbe          #+#    #+#             */
/*   Updated: 2020/09/22 23:13:08 by lelderbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_tail.h"

char	*g_name;

void	ft_show_title(char *filename)
{
	ft_putstr("==> ");
	ft_putstr(filename);
	ft_putstr(" <==\n");
}

int		ft_puttailerrstr(char *filename)
{
	ft_puterrstr(g_name);
	ft_puterrstr(": ");
	ft_puterrstr(filename);
	ft_puterrstr(": ");
	ft_puterrstr(strerror(errno));
	ft_puterrstr("\n");
	return (errno);
}

int		ft_stdin(int size)
{
	char	buffer[1];
	char	*data;
	int		index;
	int		count;

	index = 0;
	data = malloc(sizeof(*data) * size);
	while ((count = read(0, buffer, 1)))
	{
		if (count == -1)
			return (ft_puttailerrstr(""));
		if (index < size - 1)
			data[index++] = buffer[0];
		else
		{
			ft_shift_data(data, size);
			data[index] = buffer[0];
		}
	}
	write(1, data, size);
	free(data);
	return (0);
}

int		ft_tail(char *filename, int count, int show_title)
{
	int		file;
	char	*buffer;
	int		filesize;

	if ((filesize = ft_get_filesize(filename)) == -1)
		return (-1);
	if ((file = open(filename, O_RDONLY)) == -1)
		return (ft_puttailerrstr(filename));
	ft_file_seek(file, filesize - count);
	if (show_title)
		ft_show_title(filename);
	if (filesize < count)
		count = filesize;
	buffer = malloc(sizeof(*buffer) * count);
	read(file, buffer, count);
	write(1, buffer, count);
	close(file);
	free(buffer);
	return (0);
}

int		main(int argc, char **argv)
{
	int i;
	int result;
	int count;
	int show_title;

	g_name = basename(argv[0]);
	result = 0;
	if (argc < 3 || ft_strcmp(argv[1], "-c") != 0)
		return (0);
	if ((count = ft_atoi(argv[2])) < 0)
		count = count * (-1);
	if (argc == 3)
		return (ft_stdin(count));
	i = 3;
	show_title = 0;
	if (argc > 4)
		show_title = 1;
	while (i < argc)
	{
		if (ft_tail(argv[i], count, show_title))
			result = 1;
		i++;
	}
	return (result);
}
