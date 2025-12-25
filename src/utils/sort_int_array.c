/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_int_array.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amtan <amtan@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/25 13:36:50 by amtan             #+#    #+#             */
/*   Updated: 2025/12/25 13:57:36 by amtan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_int_array(int *a, size_t n)
{
	size_t	i;
	size_t	j;
	int		key;

	i = 1;
	while (i < n)
	{
		key = a[i];
		j = i;
		while (j > 0 && a[j - 1] > key)
		{
			a[j] = a[j - 1];
			j--;
		}
		a[j] = key;
		i++;
	}
}
