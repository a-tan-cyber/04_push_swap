/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_is_sorted.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amtan <amtan@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/26 20:42:56 by amtan             #+#    #+#             */
/*   Updated: 2025/12/26 20:48:05 by amtan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_is_sorted(const t_stack *s)
{
	t_node	*cur;

	if (s->size < 2)
		return (1);
	cur = s->top;
	while (cur->next)
	{
		if (cur->rank > cur->next->rank)
			return (0);
		cur = cur->next;
	}
	return (1);
}
