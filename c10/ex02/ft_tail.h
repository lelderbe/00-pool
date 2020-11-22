/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tail.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lelderbe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/22 20:56:55 by lelderbe          #+#    #+#             */
/*   Updated: 2020/09/22 22:50:38 by lelderbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_TAIL_H
# define FT_TAIL_H
# include <unistd.h>
# include <fcntl.h>
# include <string.h>
# include <errno.h>
# include <libgen.h>
# include <stdlib.h>
# define BUFF_SIZE 20

void	ft_puterrstr(char *str);
int		ft_get_filesize(char *filename);
int		ft_strcmp(char *s1, char *s2);
void	ft_putstr(char *str);
int		ft_atoi(char *str);
int		ft_file_seek(int file, int count);
void	ft_shift_data(char *data, int size);
int		ft_puttailerrstr(char *filename);

#endif
