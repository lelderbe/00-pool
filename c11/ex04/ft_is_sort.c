/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lelderbe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/22 17:02:38 by lelderbe          #+#    #+#             */
/*   Updated: 2020/09/22 19:08:59 by lelderbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_is_sort(int *tab, int length, int (*f)(int, int))
{
	int i;
	int less;
	int greater;

	i = 0;
	less = 0;
	greater = 0;
	if (length > 0)
	{
		while (i < length - 1)
		{
			if (f(tab[i], tab[i + 1]) < 0)
				less++;
			else if (f(tab[i], tab[i + 1]) > 0)
				greater++;
			i++;
		}
	}
	if (less != 0 && greater != 0)
		return (0);
	return (1);
}
