/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lelderbe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/12 17:38:21 by lelderbe          #+#    #+#             */
/*   Updated: 2020/09/12 18:26:56 by lelderbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strcmp(char *s1, char *s2)
{
	int result;

	result = 0;
	while (*s1 != '\0' && *s2 != '\0')
	{
		if (*s1 != *s2)
		{
			break ;
		}
		s1++;
		s2++;
	}
	if (*s1 < *s2)
	{
		result = -1;
	}
	else if (*s1 > *s2)
	{
		result = 1;
	}
	return (result);
}
