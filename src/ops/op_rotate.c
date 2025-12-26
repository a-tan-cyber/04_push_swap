/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amtan <amtan@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/26 12:09:20 by amtan             #+#    #+#             */
/*   Updated: 2025/12/26 16:12:49 by amtan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	op_ra(t_ctx *ctx)
{
	if (stack_rotate(&ctx->a))
		return (ops_append(&ctx->ops, OP_RA));
	return (1);
}

int	op_rb(t_ctx *ctx)
{
	if (stack_rotate(&ctx->b))
		return (ops_append(&ctx->ops, OP_RB));
	return (1);
}

int	op_rr(t_ctx *ctx)
{
	int	ra;
	int	rb;

	ra = stack_rotate(&ctx->a);
	rb = stack_rotate(&ctx->b);
	if (ra && rb)
		return (ops_append(&ctx->ops, OP_RR));
	else if (ra)
		return (ops_append(&ctx->ops, OP_RA));
	else if (rb)
		return (ops_append(&ctx->ops, OP_RB));
	return (1);
}
