/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lelderbe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/16 11:02:35 by lelderbe          #+#    #+#             */
/*   Updated: 2020/09/16 11:19:54 by lelderbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_iterative_power(int nb, int power)
{
	int result;
	int i;

	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	result = nb;
	i = 1;
	while (i < power)
	{
		result = result * nb;
		i++;
	}
	return (result);
}
