/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_vals_write_error.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amtan <amtan@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/26 17:13:13 by amtan             #+#    #+#             */
/*   Updated: 2025/12/26 17:36:56 by amtan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	free_vals_ret_0(int *vals)
{
	free(vals);
	return (0);
}

int	write_error_ret_1(void)
{
	write(2, "Error\n", 6);
	return (1);
}

int	free_vals_write_error_ret_1(int *vals)
{
	free_vals_ret_0(vals);
	return (write_error_ret_1());
}
