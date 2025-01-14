/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpayet <alpayet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 00:32:44 by alpayet           #+#    #+#             */
/*   Updated: 2024/11/07 14:13:52 by alpayet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *dest, size_t n)
{
	ft_memset(dest, '\0', n);
}

/*#include <string.h>
int	main(void)
{
	int	dest[] = {1,2,3,4,5,6};
	int	i;

	i = 0;
	ft_bzero(dest, 9);
	while (i != 6)
	{
		printf("%d \n", dest[i]);
		i++;
	}
}*/