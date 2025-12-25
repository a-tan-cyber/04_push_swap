/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amtan <amtan@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/24 22:26:38 by amtan             #+#    #+#             */
/*   Updated: 2025/12/25 12:58:46 by amtan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"
#include <stdlib.h>

#define WHITESPACE "\t\v\n\f\r "

static size_t	split_len(char **split)
{
	size_t	count;

	count = 0;
	while (split[count])
		count++;
	return (count);
}

static int	free_split(char **split)
{
	size_t	i;

	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
	return (0);
}

static int	count_all_tokens(int argc, char **argv, size_t *out_n)
{
	size_t	total;
	int		i;
	char	**split;
	size_t	len;

	total = 0;
	i = 1;
	while (i < argc)
	{
		split = ft_split_set(argv[i], WHITESPACE);
		if (!split)
			return (0);
		len = split_len(split);
		free_split(split);
		if (!len)
			return (0);
		total += len;
		i++;
	}
	*out_n = total;
	return (1);
}

static int	fill_all_values(int argc, char **argv, int *vals)
{
	int		arg_idx;
	size_t	vals_idx;
	size_t	split_idx;
	char	**split;

	arg_idx = 1;
	vals_idx = 0;
	while (arg_idx < argc)
	{
		split = ft_split_set(argv[arg_idx], WHITESPACE);
		if (!split)
			return (0);
		split_idx = 0;
		while (split[split_idx])
		{
			if (!atoi_strict(split[split_idx], &vals[vals_idx]))
				return (free_split(split));
			split_idx++;
			vals_idx++;
		}
		free_split(split);
		arg_idx++;
	}
	return (1);
}

int	parse_args(int argc, char **argv, int **out_vals, size_t *out_n)
{
	int	*vals;

	if (!count_all_tokens(argc, argv, out_n))
		return (0);
	vals = malloc((*out_n) * (sizeof(int)));
	if (!vals)
		return (0);
	if (!fill_all_values(argc, argv, vals))
	{
		free(vals);
		return (0);
	}
	*out_vals = vals;
	return (1);
}
