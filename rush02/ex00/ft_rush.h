/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rush.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lelderbe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/26 13:27:48 by lelderbe          #+#    #+#             */
/*   Updated: 2020/09/27 19:29:15 by lelderbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_RUSH_H
# define FT_RUSH_H
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>

typedef	struct	s_elem
{
	char		*key;
	char		*value;
}				t_elem;

typedef	struct	s_list
{
	char			*data;
	struct s_list	*next;
}				t_list;

t_elem			**dict_init(char *filename);
void			dict_print(t_elem **dict);
int				get_file_rows_count(char *filename);
int				get_file_size(char *filename);
char			*get_file_contents(char *filename);
void			ft_strncpy(char *dst, char *src, int from, int count);
char			**ft_split(char *str, char c);
int				ft_strcmp(char *s1, char *s2);
int				convert(char *key, t_elem **dict, t_list **answer);
int				ft_strlen(char *str);
void			ft_putstr(char *str);
int				convert0(char *key, t_elem **dict, t_list **answer);
char			*get_value_by_key(char *key, t_elem **dict);
char			*get_value_by_length(int length, t_elem **dict);
void			free_data(t_elem **dict);
t_elem			*create_elem(char *key, char *value);
t_list			*ft_create_list_elem(void *data);
void			ft_list_push_back(t_list **begin_list, void *data);
void			print_list(t_list **answer);
int				do3(char *str, t_elem **dict, int suffix, t_list **answer);

#endif
