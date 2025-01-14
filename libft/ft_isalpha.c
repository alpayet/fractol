/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpayet <alpayet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 00:42:14 by alpayet           #+#    #+#             */
/*   Updated: 2024/11/07 17:23:48 by alpayet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int c)
{
	if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
		return (1024);
	return (0);
}

/*#include <ctype.h>
int	main(void)
{
	int	i;

	i = -2;
	while (i != 128)
	{
		printf("%d", i);
		printf(" : %d", isalpha(i));
		printf(" : %d\n", ft_isalpha(i));
		i++;
	}
}*/