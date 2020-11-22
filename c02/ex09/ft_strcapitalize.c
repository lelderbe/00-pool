/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lelderbe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/12 15:14:55 by lelderbe          #+#    #+#             */
/*   Updated: 2020/09/12 15:47:16 by lelderbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strlowcase(char *str)
{
	char *original;

	original = str;
	while (*str != '\0')
	{
		if (*str >= 'A' && *str <= 'Z')
		{
			*str = *str + 32;
		}
		str++;
	}
	return (original);
}

char	*ft_strcapitalize(char *str)
{
	char	*original;
	int		do_transform;

	original = str;
	ft_strlowcase(str);
	do_transform = 1;
	while (*str != '\0')
	{
		if (*str >= 'a' && *str <= 'z')
		{
			*str = *str - 32 * do_transform;
			do_transform = 0;
		}
		else if (*str >= '0' && *str <= '9')
		{
			do_transform = 0;
		}
		else
		{
			do_transform = 1;
		}
		str++;
	}
	return (original);
}
