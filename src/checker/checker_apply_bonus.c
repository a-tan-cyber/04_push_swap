/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_apply.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amtan <amtan@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/27 19:00:54 by amtan             #+#    #+#             */
/*   Updated: 2025/12/27 19:08:18 by amtan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

static int	eq3(const char *s, const char *lit)
{
	return (ft_strncmp(s, lit, 3) == 0 && s[3] == '\0');
}

static int	eq4(const char *s, const char *lit)
{
	return (ft_strncmp(s, lit, 4) == 0 && s[4] == '\0');
}

static int	apply_short(t_stack *a, t_stack *b, const char *s)
{
	if (eq3(s, "sa\n"))
		return (stack_swap(a), 1);
	if (eq3(s, "sb\n"))
		return (stack_swap(b), 1);
	if (eq3(s, "ss\n"))
		return (stack_swap(a), stack_swap(b), 1);
	if (eq3(s, "pa\n"))
		return (stack_push(a, b), 1);
	if (eq3(s, "pb\n"))
		return (stack_push(b, a), 1);
	if (eq3(s, "ra\n"))
		return (stack_rotate(a), 1);
	if (eq3(s, "rb\n"))
		return (stack_rotate(b), 1);
	if (eq3(s, "rr\n"))
		return (stack_rotate(a), stack_rotate(b), 1);
	return (0);
}

int	checker_apply_line(t_stack *a, t_stack *b, const char *s)
{
	if (apply_short(a, b, s))
		return (1);
	if (eq4(s, "rra\n"))
		return (stack_rev_rotate(a), 1);
	if (eq4(s, "rrb\n"))
		return (stack_rev_rotate(b), 1);
	if (eq4(s, "rrr\n"))
		return (stack_rev_rotate(a), stack_rev_rotate(b), 1);
	return (0);
}
