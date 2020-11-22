/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_list_elem.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lelderbe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/27 17:45:53 by lelderbe          #+#    #+#             */
/*   Updated: 2020/09/27 18:17:08 by lelderbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_rush.h"

t_list	*ft_create_list_elem(void *data)
{
	t_list	*result;

	result = 0;
	if ((result = (t_list *)malloc(sizeof(*result))))
	{
		result->data = data;
		result->next = NULL;
	}
	return (result);
}
