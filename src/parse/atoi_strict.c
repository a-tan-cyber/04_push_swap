/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi_strict.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amtan <amtan@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/24 21:10:46 by amtan             #+#    #+#             */
/*   Updated: 2025/12/25 11:51:41 by amtan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <limits.h>

static int	parse_sign(const char **s, int *sign)
{
	*sign = 1;
	if (**s == '-' || **s == '+')
	{
		if (**s == '-')
			*sign = -1;
		(*s)++;
	}
	if (**s < '0' || **s > '9')
		return (0);
	return (1);
}

int	atoi_strict(const char *s, int *out)
{
	long	result;
	long	limit;
	int		sign;
	int		d;

	if (!s || !out || !parse_sign(&s, &sign))
		return (0);
	limit = INT_MAX;
	if (sign < 0)
		limit = -(long)INT_MIN;
	result = 0;
	while (*s >= '0' && *s <= '9')
	{
		d = *s - '0';
		if (result > (limit - d) / 10)
			return (0);
		result = result * 10 + d;
		s++;
	}
	if (*s)
		return (0);
	*out = (int)(result * sign);
	return (1);
}
