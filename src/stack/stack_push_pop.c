/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_push_pop.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amtan <amtan@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/25 20:11:15 by amtan             #+#    #+#             */
/*   Updated: 2025/12/25 23:43:30 by amtan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stack_push_top(t_stack *s, t_node *node)
{
	node->prev = NULL;
	node->next = s->top;
	if (s->top)
		s->top->prev = node;
	else
		s->bottom = node;
	s->top = node;
	s->size++;
}

void	stack_push_bottom(t_stack *s, t_node *node)
{
	node->next = NULL;
	node->prev = s->bottom;
	if (s->bottom)
		s->bottom->next = node;
	else
		s->top = node;
	s->bottom = node;
	s->size++;
}

t_node	*stack_pop_top(t_stack *s)
{
	t_node	*popped;

	popped = s->top;
	if (!popped)
		return (NULL);
	s->top = popped->next;
	if (s->top)
		s->top->prev = NULL;
	else
		s->bottom = NULL;
	popped->next = NULL;
	popped->prev = NULL;
	s->size--;
	return (popped);
}
