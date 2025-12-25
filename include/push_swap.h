/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amtan <amtan@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/23 19:52:48 by amtan             #+#    #+#             */
/*   Updated: 2025/12/25 12:41:54 by amtan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stddef.h>
# include <stdint.h>

# define OPS_INIT_CAP 16384

typedef enum e_op
{
	OP_SA = 0,
	OP_SB = 1,
	OP_SS = 2,
	OP_PA = 3,
	OP_PB = 4,
	OP_RA = 5,
	OP_RB = 6,
	OP_RR = 7,
	OP_RRA = 8,
	OP_RRB = 9,
	OP_RRR = 10
}	t_op;

typedef struct s_ops
{
	uint8_t	*buf;
	size_t	len;
	size_t	cap;
}	t_ops;

int		ops_init(t_ops *ops);
void	ops_free(t_ops *ops);
int		ops_append(t_ops *ops, t_op op);
int		ops_print_fd(const t_ops *ops, int fd);
int		atoi_strict(const char *s, int *out);
int		parse_args(int argc, char **argv, int **out_vals, size_t *out_n);

#endif