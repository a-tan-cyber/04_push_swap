/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoull.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amtan <amtan@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 12:00:00 by amtan             #+#    #+#             */
/*   Updated: 2025/12/04 13:36:56 by amtan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned long long	ft_atoull(const char *nptr)
{
	unsigned long long	result;

	result = 0;
	while ((*nptr >= '\t' && *nptr <= '\r') || *nptr == ' ')
		nptr++;
	if (*nptr == '+')
		nptr++;
	if (*nptr == '-')
		return (0);
	while (*nptr >= '0' && *nptr <= '9')
	{
		result = result * 10 + (unsigned long long)(*nptr - '0');
		nptr++;
	}
	return (result);
}
