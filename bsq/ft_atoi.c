/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wstaedmo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/14 13:35:47 by wstaedmo          #+#    #+#             */
/*   Updated: 2020/09/30 22:25:09 by lelderbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

long	ft_atoi(char *str)
{
	int		c;
	int		neg;
	long	numbers;

	c = 0;
	neg = 0;
	numbers = 0;
	while (str[c] == ' ' || str[c] == '\n' || str[c] == '\t' ||
			str[c] == '\v' || str[c] == '\f' || str[c] == '\r')
		c++;
	while (str[c] == '+' || str[c] == '-')
	{
		if (str[c] == '-')
			neg++;
		c++;
	}
	while (str[c] <= '9' && str[c] >= '0')
	{
		numbers = numbers * 10 + (str[c] - 48);
		c++;
	}
	if (neg % 2 != 0)
		return (numbers * -1);
	else
		return (numbers);
}
