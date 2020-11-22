/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lelderbe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/12 19:23:07 by lelderbe          #+#    #+#             */
/*   Updated: 2020/09/13 16:20:53 by lelderbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_strstr(char *str, char *to_find)
{
	char	*result;
	int		i;
	int		found;

	found = 0;
	if (*to_find == '\0')
		return (str);
	while (*str != '\0' && !found)
	{
		i = 0;
		found = 1;
		while ((*(to_find + i) != '\0') && found)
		{
			if (*(str + i) != *(to_find + i))
				found = 0;
			i++;
		}
		if (found)
			result = str;
		str++;
	}
	if (!found)
		result = 0;
	return (result);
}
