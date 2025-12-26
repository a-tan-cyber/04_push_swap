/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amtan <amtan@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/26 12:09:32 by amtan             #+#    #+#             */
/*   Updated: 2025/12/26 16:16:31 by amtan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	op_sa(t_ctx *ctx)
{
	if (stack_swap(&ctx->a))
		return (ops_append(&ctx->ops, OP_SA));
	return (1);
}

int	op_sb(t_ctx *ctx)
{
	if (stack_swap(&ctx->b))
		return (ops_append(&ctx->ops, OP_SB));
	return (1);
}

int	op_ss(t_ctx *ctx)
{
	int	sa;
	int	sb;

	sa = stack_swap(&ctx->a);
	sb = stack_swap(&ctx->b);
	if (sa && sb)
		return (ops_append(&ctx->ops, OP_SS));
	else if (sa)
		return (ops_append(&ctx->ops, OP_SA));
	else if (sb)
		return (ops_append(&ctx->ops, OP_SB));
	return (1);
}
