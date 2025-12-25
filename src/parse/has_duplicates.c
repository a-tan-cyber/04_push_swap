/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   has_duplicates.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amtan <amtan@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/24 23:16:42 by amtan             #+#    #+#             */
/*   Updated: 2025/12/25 14:11:24 by amtan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int has_duplicates(const int *sorted, size_t n)
{
	size_t	i;

	i = 0;
	while (i + 1 < n)
	{
		if (sorted[i] == sorted[i + 1])
			return (1);
		i++;
	}
	return (0);
}
