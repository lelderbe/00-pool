/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lelderbe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/12 15:58:47 by lelderbe          #+#    #+#             */
/*   Updated: 2020/09/12 16:12:03 by lelderbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	char			*original;
	unsigned int	count;

	original = dest;
	count = 0;
	while (*src != '\0' && *dest != '\0' && count < size - 1)
	{
		*dest = *src;
		src++;
		dest++;
		count++;
	}
	*dest = '\0';
	return (count);
}
