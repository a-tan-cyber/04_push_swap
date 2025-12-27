/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amtan <amtan@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/27 19:09:49 by amtan             #+#    #+#             */
/*   Updated: 2025/12/27 19:11:27 by amtan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"
#include <stdlib.h>
#include <unistd.h>

int	checker_apply_line(t_stack *a, t_stack *b, const char *s);

static int	error_exit(t_stack *a, t_stack *b, int *vals)
{
	if (vals)
		free(vals);
	stack_clear(a);
	stack_clear(b);
	write(2, "Error\n", 6);
	return (1);
}

static int	build_a_from_argv(t_stack *a, int argc, char **argv)
{
	int		*vals;
	size_t	n;

	vals = NULL;
	if (!parse_args(argc, argv, &vals, &n))
		return (free(vals), 0);
	if (n > 1 && !rank_values(vals, n))
		return (free(vals), 0);
	if (!build_stack_from_vals(a, vals, n))
		return (free(vals), 0);
	free(vals);
	return (1);
}

static int	read_and_apply(t_stack *a, t_stack *b)
{
	char	*line;

	line = get_next_line(0);
	while (line)
	{
		if (!checker_apply_line(a, b, line))
			return (free(line), 0);
		free(line);
		line = get_next_line(0);
	}
	return (1);
}

static void	print_result(const t_stack *a, const t_stack *b)
{
	if (stack_is_sorted(a) && b->size == 0)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
}

int	main(int argc, char **argv)
{
	t_stack	a;
	t_stack	b;

	if (argc <= 1)
		return (0);
	stack_init(&a);
	stack_init(&b);
	if (!build_a_from_argv(&a, argc, argv))
		return (error_exit(&a, &b, NULL));
	if (!read_and_apply(&a, &b))
		return (error_exit(&a, &b, NULL));
	print_result(&a, &b);
	stack_clear(&a);
	stack_clear(&b);
	return (0);
}
