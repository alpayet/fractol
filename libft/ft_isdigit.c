/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpayet <alpayet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 11:00:55 by alpayet           #+#    #+#             */
/*   Updated: 2024/11/07 13:58:35 by alpayet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (2048);
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
		printf(" : %d", isdigit(i));
		printf(" : %d\n", ft_isdigit(i));
		i++;
	}
}*/