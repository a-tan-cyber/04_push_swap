/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amtan <amtan@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/26 12:09:14 by amtan             #+#    #+#             */
/*   Updated: 2025/12/26 15:53:58 by amtan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	op_pa(t_ctx *ctx)
{
	if (stack_push(&ctx->a, &ctx->b))
		return (ops_append(&ctx->ops, OP_PA));
	return (1);
}

int	op_pb(t_ctx *ctx)
{
	if (stack_push(&ctx->b, &ctx->a))
		return (ops_append(&ctx->ops, OP_PB));
	return (1);
}
