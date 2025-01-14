/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpayet <alpayet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 11:21:15 by alpayet           #+#    #+#             */
/*   Updated: 2024/11/07 13:58:38 by alpayet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isprint(int c)
{
	if (c >= 32 && c <= 126)
		return (16384);
	return (0);
}

/*#include <ctype.h>
int	main(void)
{
	int	i;

	i = -2;
	while (i != 129)
	{
		printf("%d", i);
		printf(" : %d", isprint(i));
		printf(" : %d\n", ft_isprint(i));
		i++;
	}
}*/