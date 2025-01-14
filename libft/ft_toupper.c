/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpayet <alpayet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 22:30:39 by alpayet           #+#    #+#             */
/*   Updated: 2024/11/09 20:19:07 by alpayet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		c = c - 32;
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
		printf(" : %d", toupper(i));
		printf(" : %d \n", ft_toupper(i));
		if (toupper(i) == ft_toupper(i))
			printf(" ok \n");
		i++;
	}
}*/