/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_rev_rotate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amtan <amtan@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/26 12:09:23 by amtan             #+#    #+#             */
/*   Updated: 2025/12/26 16:08:51 by amtan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	op_rra(t_ctx *ctx)
{
	if (stack_rev_rotate(&ctx->a))
		return (ops_append(&ctx->ops, OP_RRA));
	return (1);
}

int	op_rrb(t_ctx *ctx)
{
	if (stack_rev_rotate(&ctx->b))
		return (ops_append(&ctx->ops, OP_RRB));
	return (1);
}

int	op_rrr(t_ctx *ctx)
{
	int	rra;
	int	rrb;

	rra = stack_rev_rotate(&ctx->a);
	rrb = stack_rev_rotate(&ctx->b);
	if (rra && rrb)
		return (ops_append(&ctx->ops, OP_RRR));
	else if (rra)
		return (ops_append(&ctx->ops, OP_RRA));
	else if (rrb)
		return (ops_append(&ctx->ops, OP_RRB));
	return (1);
}
