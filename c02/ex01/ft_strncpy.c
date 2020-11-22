/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lelderbe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/11 20:19:39 by lelderbe          #+#    #+#             */
/*   Updated: 2020/09/11 20:37:28 by lelderbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	char			*original;
	unsigned int	count;

	original = dest;
	count = 0;
	while (count < n)
	{
		*dest = *src;
		if (*src != '\0')
		{
			src++;
		}
		dest++;
		count++;
	}
	return (original);
}
