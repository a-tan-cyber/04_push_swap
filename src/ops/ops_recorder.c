/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_recorder.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amtan <amtan@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/23 19:55:40 by amtan             #+#    #+#             */
/*   Updated: 2025/12/26 15:54:57 by amtan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"
#include <stdlib.h>
#include <unistd.h>

static int	ops_write_op(int fd, t_op op)
{
	if (op == OP_SA)
		return (write(fd, "sa\n", 3) == 3);
	if (op == OP_SB)
		return (write(fd, "sb\n", 3) == 3);
	if (op == OP_SS)
		return (write(fd, "ss\n", 3) == 3);
	if (op == OP_PA)
		return (write(fd, "pa\n", 3) == 3);
	if (op == OP_PB)
		return (write(fd, "pb\n", 3) == 3);
	if (op == OP_RA)
		return (write(fd, "ra\n", 3) == 3);
	if (op == OP_RB)
		return (write(fd, "rb\n", 3) == 3);
	if (op == OP_RR)
		return (write(fd, "rr\n", 3) == 3);
	if (op == OP_RRA)
		return (write(fd, "rra\n", 4) == 4);
	if (op == OP_RRB)
		return (write(fd, "rrb\n", 4) == 4);
	if (op == OP_RRR)
		return (write(fd, "rrr\n", 4) == 4);
	return (0);
}

int	ops_init(t_ops *ops)
{
	ops->buf = (uint8_t *)malloc(PS_OPS_INIT_CAP);
	if (!ops->buf)
		return (0);
	ops->len = 0;
	ops->cap = PS_OPS_INIT_CAP;
	return (1);
}

void	ops_free(t_ops *ops)
{
	free(ops->buf);
	ops->buf = NULL;
	ops->len = 0;
	ops->cap = 0;
}

int	ops_append(t_ops *ops, t_op op)
{
	uint8_t	*new_buf;
	size_t	new_cap;

	if (ops->len >= ops->cap)
	{
		new_cap = ops->cap;
		if (new_cap == 0)
			new_cap = PS_OPS_INIT_CAP;
		while (new_cap <= ops->len)
			new_cap *= 2;
		new_buf = (uint8_t *)malloc(new_cap);
		if (!new_buf)
			return (0);
		if (ops->buf && ops->len > 0)
			ft_memcpy(new_buf, ops->buf, ops->len);
		free(ops->buf);
		ops->buf = new_buf;
		ops->cap = new_cap;
	}
	ops->buf[ops->len] = (uint8_t)op;
	ops->len++;
	return (1);
}

int	ops_print_fd(const t_ops *ops, int fd)
{
	size_t	i;

	i = 0;
	while (i < ops->len)
	{
		if (!ops_write_op(fd, (t_op)ops->buf[i]))
			return (0);
		i++;
	}
	return (1);
}
