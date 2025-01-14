/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpayet <alpayet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 22:18:02 by alpayet           #+#    #+#             */
/*   Updated: 2024/11/23 23:57:21 by alpayet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	int		i;
	int		sign;
	long	n;

	i = 0;
	n = 0;
	sign = 1;
	while ((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == 32)
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sign = -sign;
		i++;
	}
	while (nptr[i] >= 48 && nptr[i] <= 57)
	{
		if (n > (10 * n + nptr[i] - 48) && sign == 1)
			return (-1);
		if (n > (10 * n + nptr[i] - 48) && sign == -1)
			return (0);
		n = 10 * n + nptr[i] - 48;
		i++;
	}
	return (sign * n);
}

/*#include <stdlib.h>
int	main(void)
{
	printf("vrai %d\n", atoi("-9223372036854775809"));
	printf("toi %d", ft_atoi("-9223372036854775809"));
}*/
