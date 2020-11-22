/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_advanced_sort_string_tab.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lelderbe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/23 19:57:06 by lelderbe          #+#    #+#             */
/*   Updated: 2020/09/23 22:12:18 by lelderbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

void	ft_advanced_sort_string_tab(char **tab, int (*cmp)(char *, char *))
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
			if (cmp(tab[j], tab[j + 1]) > 0)
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
