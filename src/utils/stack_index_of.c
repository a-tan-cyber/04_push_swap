/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_index_of.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amtan <amtan@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/26 22:12:15 by amtan             #+#    #+#             */
/*   Updated: 2025/12/26 23:12:10 by amtan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	stack_index_of_rank(const t_stack *s, int rank)
{
	t_node	*cur;
	size_t	i;

	cur = s->top;
	i = 0;
	while (cur)
	{
		if (cur->rank == rank)
			return (i);
		cur = cur->next;
		i++;
	}
	return (s->size);
}

size_t	stack_index_of_max(const t_stack *s)
{
	t_node	*cur;
	size_t	i;
	size_t	max_i;
	int		max_rank;

	cur = s->top;
	if (!cur)
		return (s->size);
	i = 0;
	max_i = 0;
	max_rank = cur->rank;
	while (cur)
	{
		if (cur->rank > max_rank)
		{
			max_rank = cur->rank;
			max_i = i;
		}
		cur = cur->next;
		i++;
	}
	return (max_i);
}

size_t	stack_index_of_min(const t_stack *s)
{
	t_node	*cur;
	size_t	i;
	size_t	min_i;
	int		min_rank;

	cur = s->top;
	if (!cur)
		return (s->size);
	i = 0;
	min_i = 0;
	min_rank = cur->rank;
	while (cur)
	{
		if (cur->rank < min_rank)
		{
			min_rank = cur->rank;
			min_i = i;
		}
		cur = cur->next;
		i++;
	}
	return (min_i);
}
