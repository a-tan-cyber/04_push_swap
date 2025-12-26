/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amtan <amtan@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/24 15:29:59 by amtan             #+#    #+#             */
/*   Updated: 2025/12/26 17:36:35 by amtan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>
#include <unistd.h>

int	main(int argc, char **argv)
{
	int		*vals;
	size_t	n;
	t_ctx	ctx;

	if (argc <= 1)
		return (0);
	if (!parse_args(argc, argv, &vals, &n))
		return (write_error_ret_1());
	if (n < 2)
		return (free_vals_ret_0(vals));
	if (!rank_values(vals, n))
		return (free_vals_write_error_ret_1(vals));
	if (!ctx_init(&ctx))
		return (free_vals_write_error_ret_1(vals));
	if (!build_stack_from_vals(&ctx.a, vals, n))
		return (free_vals_write_error_ret_1(vals));
	if (!push_swap_run(&ctx))
		return (free_vals_write_error_ret_1(vals));
	if (!ops_print_fd(&ctx.ops, 1))
		return (free_vals_write_error_ret_1(vals));
	ctx_free(&ctx);
	return (free_vals_ret_0(vals));
}
