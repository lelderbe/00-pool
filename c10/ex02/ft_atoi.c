/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lelderbe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/14 13:43:48 by lelderbe          #+#    #+#             */
/*   Updated: 2020/09/14 16:37:49 by lelderbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	next_char(char c)
{
	int next_char;

	next_char = 0;
	if (c == ' ' || c == '\t' || c == '\n' \
			|| c == '\v' || c == '\f' || c == '\r' || c == '+')
	{
		next_char = 1;
	}
	return (next_char);
}

int	ft_atoi(char *str)
{
	int result;
	int sign;
	int only_digits_allowed;

	result = 0;
	sign = 1;
	only_digits_allowed = 0;
	while (*str)
	{
		if (!next_char(*str) || only_digits_allowed)
		{
			if (*str >= '0' && *str <= '9')
			{
				result = result * 10 + (*str - 48);
				only_digits_allowed = 1;
			}
			else if (*str == '-' && !only_digits_allowed)
				sign = sign * (-1);
			else
				break ;
		}
		str++;
	}
	return (result * sign);
}
