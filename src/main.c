/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amtan <amtan@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/24 15:29:59 by amtan             #+#    #+#             */
/*   Updated: 2025/12/25 17:05:37 by amtan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>
#include <unistd.h>

int	main(int argc, char **argv)
{
	int		*vals;
	size_t	n;

	if (argc <= 1)
		return (0);
	if (!parse_args(argc, argv, &vals, &n))
	{
		write(2, "Error\n", 6);
		return (1);
	}
	if (n < 2)
	{
		free(vals);
		return (0);
	}
	if (!rank_values(vals, n))
	{
		free(vals);
		write(2, "Error\n", 6);
		return (2);
	}
	free(vals);
	return (0);
}
