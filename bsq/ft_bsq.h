/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bsq.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wstaedmo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 11:18:36 by wstaedmo          #+#    #+#             */
/*   Updated: 2020/09/30 22:24:35 by lelderbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_BSQ_H
# define FT_BSQ_H

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>

typedef struct	s_square
{
	long		x1;
	long		y1;
	long		dx;
}				t_square;

typedef struct	s_map
{
	char		**map;
	char		empty;
	char		obstacle;
	char		full;
	long		lines;
	long		columns;
	char		**data_ptr_for_free;
}				t_map;

t_map			*get_map(char *filename);
void			map_free(t_map *map);
void			map_print(t_map *map);
void			bruteforce(t_map *map);
void			ft_putstr(char *str);
void			ft_putchar(char c);
long			get_file_size(char *filename);
char			*get_file_contents(char *filename);
char			*ft_strcpy(char *dest, char *src);
t_square		*get_new_square(void);
void			update_square_data(t_square *square, long x1, long y1, long dx);
int				square_valid(t_square *square);
char			**ft_split(char *str, char sep);
long			ft_strlen(char *str);
long			ft_atoi(char *str);
void			free_split(char **str);
char			*get_stdin_contents(void);
int				valid_lines_length_equal(char **data);
int				valid_lines_count(char **data);
int				valid_count_arguments_and_unique(char **data);
int				valid_first_number(char **data);
int				valid_only_right_chars(char **data);
void			ft_puterrstr(char *str);

#endif
