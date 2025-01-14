/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpayet <alpayet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 11:09:15 by alpayet           #+#    #+#             */
/*   Updated: 2024/11/22 00:45:49 by alpayet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	if ((c >= '0' && c <= '9') || (c >= 'A' && c <= 'Z')
		|| (c >= 'a' && c <= 'z'))
		return (8);
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
		printf(" : %d", isalnum(i));
		printf(" : %d\n", ft_isalnum(i));
		i++;
	}
}*/