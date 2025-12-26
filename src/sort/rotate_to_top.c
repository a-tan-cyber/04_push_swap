/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_to_top.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amtan <amtan@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/26 23:38:17 by amtan             #+#    #+#             */
/*   Updated: 2025/12/27 00:08:09 by amtan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	rotate_index_to_top_a(t_ctx *ctx, size_t idx)
{
	size_t	i;

	if (idx >= ctx->a.size)
		return (1);
	i = 0;
	if (idx <= ctx->a.size / 2)
	{
		while (i < idx)
		{
			if (!op_ra(ctx))
				return (0);
			i++;
		}
	}
	else
	{
		while (i < ctx->a.size - idx)
		{
			if (!op_rra(ctx))
				return (0);
			i++;
		}
	}
	return (1);
}

int	rotate_index_to_top_b(t_ctx *ctx, size_t idx)
{
	size_t	i;

	if (idx >= ctx->b.size)
		return (1);
	i = 0;
	if (idx <= ctx->b.size / 2)
	{
		while (i < idx)
		{
			if (!op_rb(ctx))
				return (0);
			i++;
		}
	}
	else
	{
		while (i < ctx->b.size - idx)
		{
			if (!op_rrb(ctx))
				return (0);
			i++;
		}
	}
	return (1);
}

int	rotate_rank_to_top_a(t_ctx *ctx, int rank)
{
	size_t	idx;

	idx = stack_index_of_rank(&ctx->a, rank);
	if (idx == ctx->a.size)
		return (0);
	return (rotate_index_to_top_a(ctx, idx));
}

int	rotate_rank_to_top_b(t_ctx *ctx, int rank)
{
	size_t	idx;

	idx = stack_index_of_rank(&ctx->b, rank);
	if (idx == ctx->b.size)
		return (0);
	return (rotate_index_to_top_b(ctx, idx));
}
