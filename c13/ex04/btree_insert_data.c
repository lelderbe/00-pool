/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_insert_data.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lelderbe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/25 21:31:54 by lelderbe          #+#    #+#             */
/*   Updated: 2020/09/25 23:15:47 by lelderbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

void	btree_insert_data(t_btree **root, void *item,
		int (*cmpf)(void *, void *))
{
	t_btree	*elem;

	if (*root)
	{
		if ((*cmpf)(item, (*root)->item) < 0)
			btree_insert_data((&(*root)->left), item, cmpf);
		else if ((*cmpf)(item, (*root)->item) > 0)
			btree_insert_data(&((*root)->right), item, cmpf);
		else
		{
			if ((*root)->right)
			{
				elem = (*root)->right;
				(*root)->right = btree_create_node(item);
				(*root)->right->right = elem;
			}
			else
			{
				(*root)->right = btree_create_node(item);
			}
		}
	}
	else
		*root = btree_create_node(item);
}
