/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_new.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amtan <amtan@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/25 20:11:19 by amtan             #+#    #+#             */
/*   Updated: 2025/12/25 22:01:38 by amtan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

t_node	*node_new(int rank)
{
	t_node	*node;

	node = malloc(sizeof(t_node));
	if (!node)
		return (NULL);
	node->rank = rank;
	node->next = NULL;
	node->prev = NULL;
	return (node);
}
