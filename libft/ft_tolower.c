/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpayet <alpayet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 23:04:19 by alpayet           #+#    #+#             */
/*   Updated: 2024/11/07 13:59:08 by alpayet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		c = c + 32;
	if (c >= -128 && c <= -2)
		c = 256 + c;
	return (c);
}

/*#include <ctype.h>
int	main(void)
{
	int	i;

	i = -250;
	while (i != 300)
	{
		printf("%d", i);
		printf(" : %d", tolower(i));
		printf(" : %d \n", ft_tolower(i));
		if (tolower(i) == ft_tolower(i))
			printf(" ok \n");
		i++;
	}
}*/