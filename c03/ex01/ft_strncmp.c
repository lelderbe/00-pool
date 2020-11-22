/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lelderbe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/12 18:28:01 by lelderbe          #+#    #+#             */
/*   Updated: 2020/09/12 18:33:53 by lelderbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	int				result;
	unsigned int	count;

	result = 0;
	count = 1;
	while (*s1 != '\0' && *s2 != '\0' && count < n)
	{
		if (*s1 != *s2)
		{
			break ;
		}
		s1++;
		s2++;
		count++;
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
