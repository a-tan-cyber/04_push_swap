/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ctx_init_free.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amtan <amtan@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/26 16:56:01 by amtan             #+#    #+#             */
/*   Updated: 2025/12/26 17:01:04 by amtan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ctx_init(t_ctx *ctx)
{
	stack_init(&ctx->a);
	stack_init(&ctx->a);
	return (ops_init(&ctx->ops));
}

void	ctx_free(t_ctx *ctx)
{
	stack_clear(&ctx->a);
	stack_clear(&ctx->b);
	ops_free(&ctx->ops);
}
