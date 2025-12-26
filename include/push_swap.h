/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amtan <amtan@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/23 19:52:48 by amtan             #+#    #+#             */
/*   Updated: 2025/12/26 15:37:06 by amtan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stddef.h>
# include <stdint.h>

# ifndef PS_OPS_INIT_CAP
#  define PS_OPS_INIT_CAP 16384
# endif

typedef struct s_node
{
	struct s_node	*prev;
	int				rank;
	struct s_node	*next;
}	t_node;

typedef struct s_stack
{
	t_node	*top;
	t_node	*bottom;
	size_t	size;
}	t_stack;

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

typedef struct s_ctx
{
	t_stack	a;
	t_stack	b;
	t_ops	ops;
}	t_ctx;

/* src/ops/op_push.c */
int		op_pa(t_ctx *ctx);
int		op_pb(t_ctx *ctx);
/* src/ops/op_rev_rotate.c */
int		op_rra(t_ctx *ctx);
int		op_rrb(t_ctx *ctx);
int		op_rrr(t_ctx *ctx);
/* src/ops/op_rotate.c */
int		op_ra(t_ctx *ctx);
int		op_rb(t_ctx *ctx);
int		op_rr(t_ctx *ctx);
/* src/ops/op_swap.c */
int		op_sa(t_ctx *ctx);
int		op_sb(t_ctx *ctx);
int		op_ss(t_ctx *ctx);
/* src/ops/ops_recorder.c */
int		ops_init(t_ops *ops);
void	ops_free(t_ops *ops);
int		ops_append(t_ops *ops, t_op op);
int		ops_print_fd(const t_ops *ops, int fd);

/* src/parse/ */
int		atoi_strict(const char *s, int *out);
int		has_duplicates(const int *sorted, size_t n);
int		parse_args(int argc, char **argv, int **out_vals, size_t *out_n);
int		rank_values(int *vals, size_t n);

/* src/stack/ */
int		build_stack_from_vals(t_stack *a, const int *vals, size_t n);
t_node	*node_new(int rank);
void	stack_clear(t_stack *s);
void	stack_init(t_stack *s);
/* src/stack/stack_primitives.c */
int		stack_swap(t_stack *s);
int		stack_push(t_stack *dst, t_stack *src);
int		stack_rotate(t_stack *s);
int		stack_rev_rotate(t_stack *s);
/* src/stack/stack_push_pop.c */
void	stack_push_top(t_stack *s, t_node *node);
void	stack_push_bottom(t_stack *s, t_node *node);
t_node	*stack_pop_top(t_stack *s);
t_node	*stack_pop_bottom(t_stack *s);

/* src/utils/ */
void	sort_int_array(int *a, size_t n);

#endif