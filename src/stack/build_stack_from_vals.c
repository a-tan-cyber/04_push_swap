/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_stack_from_vals.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amtan <amtan@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/26 00:02:25 by amtan             #+#    #+#             */
/*   Updated: 2025/12/26 01:03:27 by amtan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	build_stack_from_vals(t_stack *a, const int *vals, size_t n)
{
	size_t	i;
	t_node	*new;

	i = 0;
	while (i < n)
	{
		new = node_new(vals[i]);
		if (!new)
		{
			stack_clear(a);
			return (0);
		}
		stack_push_bottom(a, new);
		i++;
	}
	return (1);
}
