/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_chunks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amtan <amtan@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/27 00:55:15 by amtan             #+#    #+#             */
/*   Updated: 2025/12/27 12:42:41 by amtan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static size_t	chunk_size(size_t n)
{
	size_t	delta;

	delta = n / 20 + 7;
	if (delta < 1)
		delta = 1;
	return (delta);
}

static int	chunks_push_a_to_b(t_ctx *ctx, size_t delta)
{
	size_t	threshold;
	size_t	top_rank;

	threshold = 0;
	while (ctx->a.size > 0)
	{
		top_rank = (size_t)ctx->a.top->rank;
		if (top_rank <= threshold + delta)
		{
			if (!op_pb(ctx))
				return (0);
			if (top_rank <= threshold)
			{
				if (!op_rb(ctx))
					return (0);
			}
			threshold++;
		}
		else
		{
			if (!op_ra(ctx))
				return (0);
		}
	}
	return (1);
}

static int	chunks_pull_b_to_a(t_ctx *ctx)
{
	size_t	max_idx;

	while (ctx->b.size > 0)
	{
		max_idx = stack_index_of_max(&ctx->b);
		if (!rotate_index_to_top_b(ctx, max_idx))
			return (0);
		if (!op_pa(ctx))
			return (0);
	}
	return (1);
}

int	sort_chunks(t_ctx *ctx)
{
	size_t	initial_n;
	size_t	delta;

	initial_n = ctx->a.size;
	delta = chunk_size(initial_n);
	if (!chunks_push_a_to_b(ctx, delta))
		return (0);
	if (!chunks_pull_b_to_a(ctx))
		return (0);
	return (1);
}
