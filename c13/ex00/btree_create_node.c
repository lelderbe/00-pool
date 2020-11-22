/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_create_node.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lelderbe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/25 16:55:53 by lelderbe          #+#    #+#             */
/*   Updated: 2020/09/25 20:03:10 by lelderbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

t_btree	*btree_create_node(void *item)
{
	t_btree	*result;

	result = 0;
	if ((result = (t_btree *)malloc(sizeof(*result))))
	{
		result->left = NULL;
		result->right = NULL;
		result->item = item;
	}
	return (result);
}
