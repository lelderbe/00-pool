/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_back.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lelderbe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/24 18:01:07 by lelderbe          #+#    #+#             */
/*   Updated: 2020/09/27 18:34:05 by lelderbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_rush.h"

void	ft_list_push_back(t_list **begin_list, void *data)
{
	t_list	*list;

	list = *begin_list;
	if (list == 0)
	{
		list = ft_create_list_elem(data);
		*begin_list = list;
		return ;
	}
	while (list->next)
	{
		list = list->next;
	}
	list->next = ft_create_list_elem(data);
}
