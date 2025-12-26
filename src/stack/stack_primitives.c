/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_primitives.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amtan <amtan@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/26 10:20:59 by amtan             #+#    #+#             */
/*   Updated: 2025/12/26 11:58:18 by amtan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_swap(t_stack *s)
{
	int		tmp;

	if (s->size < 2)
		return (0);
	tmp = s->top->rank;
	s->top->rank = s->top->next->rank;
	s->top->next->rank = tmp;
	return (1);
}

int	stack_push(t_stack *dst, t_stack *src)
{
	t_node	*popped;

	popped = stack_pop_top(src);
	if (!popped)
		return (0);
	stack_push_top(dst, popped);
	return (1);
}

int	stack_rotate(t_stack *s)
{
	t_node	*popped;

	if (s->size < 2)
		return (0);
	popped = stack_pop_top(s);
	if (!popped)
		return (0);
	stack_push_bottom(s, popped);
	return (1);
}

int	stack_rev_rotate(t_stack *s)
{
	t_node	*popped;

	if (s->size < 2)
		return (0);
	popped = stack_pop_bottom(s);
	if (!popped)
		return (0);
	stack_push_top(s, popped);
	return (1);
}
