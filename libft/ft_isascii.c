/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpayet <alpayet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 11:14:06 by alpayet           #+#    #+#             */
/*   Updated: 2024/11/07 13:58:31 by alpayet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
		return (1);
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
		printf(" : %d", isascii(i));
		printf(" : %d\n", ft_isascii(i));
		i++;
	}
}*/