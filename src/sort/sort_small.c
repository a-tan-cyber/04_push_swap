/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amtan <amtan@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/26 21:15:33 by amtan             #+#    #+#             */
/*   Updated: 2025/12/27 00:48:25 by amtan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	sort_2(t_ctx *ctx)
{
	if (ctx->a.top->rank > ctx->a.top->next->rank)
		return (op_sa(ctx));
	return (1);
}

static int	sort_3(t_ctx *ctx)
{
	size_t	idx;

	idx = stack_index_of_max(&ctx->a);
	if (idx == ctx->a.size)
		return (0);
	if (idx == 0)
	{
		if (!op_ra(ctx))
			return (0);
	}
	else if (idx == 1)
	{
		if (!op_rra(ctx))
			return (0);
	}
	if (ctx->a.top->rank > ctx->a.top->next->rank)
		return (op_sa(ctx));
	return (1);
}

static int	sort_4(t_ctx *ctx)
{
	if (!rotate_rank_to_top_a(ctx, 0))
		return (0);
	if (!op_pb(ctx))
		return (0);
	if (!sort_3(ctx))
		return (0);
	if (!op_pa(ctx))
		return (0);
	return (1);
}

static int	sort_5(t_ctx *ctx)
{
	if (!rotate_rank_to_top_a(ctx, 0))
		return (0);
	if (!op_pb(ctx))
		return (0);
	if (!rotate_rank_to_top_a(ctx, 1))
		return (0);
	if (!op_pb(ctx))
		return (0);
	if (!sort_3(ctx))
		return (0);
	if (!op_pa(ctx))
		return (0);
	if (!op_pa(ctx))
		return (0);
	return (1);
}

int	sort_small(t_ctx *ctx)
{
	if (ctx->a.size == 2)
		return (sort_2(ctx));
	else if (ctx->a.size == 3)
		return (sort_3(ctx));
	else if (ctx->a.size == 4)
		return (sort_4(ctx));
	else if (ctx->a.size == 5)
		return (sort_5(ctx));
	return (1);
}
