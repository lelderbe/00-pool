/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lelderbe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/12 16:33:15 by lelderbe          #+#    #+#             */
/*   Updated: 2020/09/12 20:53:18 by lelderbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr_non_printable(char *str)
{
	char *hex;

	hex = "0123456789abcdef";
	while (*str != '\0')
	{
		if (*str < 32 || *str > 126)
		{
			write(1, "\\", 1);
			write(1, (hex + *str / 16), 1);
			write(1, (hex + *str % 16), 1);
		}
		else
		{
			write(1, str, 1);
		}
		str++;
	}
}
