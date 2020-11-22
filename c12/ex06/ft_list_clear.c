/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_clear.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lelderbe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/24 18:53:30 by lelderbe          #+#    #+#             */
/*   Updated: 2020/09/24 22:37:23 by lelderbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_clear(t_list *begin_list, void (*free_fct)(void *))
{
	t_list	*elem;

	while (begin_list)
	{
		elem = begin_list;
		begin_list = begin_list->next;
		free_fct(elem->data);
		elem->next = NULL;
		free(elem);
	}
	elem = NULL;
}
