/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_string_tab.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lelderbe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/23 15:49:43 by lelderbe          #+#    #+#             */
/*   Updated: 2020/09/23 22:07:14 by lelderbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_strcmp(char *s1, char *s2)
{
	int result;

	result = 0;
	while (*s1 != '\0' && *s2 != '\0')
	{
		if (*s1 != *s2)
			break ;
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

int		get_tab_length(char **tab)
{
	int length;

	length = 0;
	while (*tab)
	{
		length++;
		tab++;
	}
	return (length);
}

void	ft_sort_string_tab(char **tab)
{
	int		i;
	int		j;
	char	*ptr;
	int		length;

	length = get_tab_length(tab);
	if (length < 2)
		return ;
	i = 0;
	while (i < length)
	{
		j = 0;
		while (j < length - 1 - i)
		{
			if (ft_strcmp(tab[j], tab[j + 1]) > 0)
			{
				ptr = tab[j + 1];
				tab[j + 1] = tab[j];
				tab[j] = ptr;
			}
			j++;
		}
		i++;
	}
}
