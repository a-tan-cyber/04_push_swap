/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rank_values.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amtan <amtan@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/25 15:15:29 by amtan             #+#    #+#             */
/*   Updated: 2025/12/25 16:11:23 by amtan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"
#include <stdlib.h>

static int	*copy_int_array(const int *src, size_t n)
{
	int	*dst;

	dst = malloc(n * sizeof(int));
	if (!dst)
		return (NULL);
	ft_memcpy(dst, src, n * sizeof(int));
	return (dst);
}

static size_t	bsearch_index(const int *sorted, size_t n, int value)
{
	size_t	lo;
	size_t	hi;
	size_t	mid;

	lo = 0;
	hi = n;
	while (lo < hi)
	{
		mid = lo + (hi - lo) / 2;
		if (sorted[mid] == value)
			return (mid);
		if (sorted[mid] < value)
			lo = mid + 1;
		else
			hi = mid;
	}
	return (n);
}

static int	apply_ranks(int *vals, size_t n, const int *sorted)
{
	size_t	i;
	size_t	rank;

	i = 0;
	while (i < n)
	{
		rank = bsearch_index(sorted, n, vals[i]);
		if (rank == n)
			return (0);
		vals[i] = rank;
		i++;
	}
	return (1);
}

int	rank_values(int *vals, size_t n)
{
	int	*tmp;

	tmp = copy_int_array(vals, n);
	if (!tmp)
		return (0);
	sort_int_array(tmp, n);
	if (has_duplicates(tmp, n))
	{
		free(tmp);
		return (0);
	}
	if (!apply_ranks(vals, n, tmp))
	{
		free(tmp);
		return (0);
	}
	free(tmp);
	return (1);
}
