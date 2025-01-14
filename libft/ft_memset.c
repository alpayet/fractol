/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpayet <alpayet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 11:32:47 by alpayet           #+#    #+#             */
/*   Updated: 2024/11/22 02:07:22 by alpayet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *dest, int value, size_t n)
{
	size_t			i;
	unsigned char	*dest_char;

	value = (unsigned char)value;
	dest_char = dest;
	i = 0;
	while (i < n)
	{
		dest_char[i] = value;
		i++;
	}
	return (dest);
}

/*#include <string.h>
int	main(void)
{
	int	dest[] = {1,2,3,4,5,6};
	int	i;

	i = 0;
	ft_memset(dest, 'A', 9);
	while (i != 6)
	{
		printf("%d \n", dest[i]);
		i++;
	}
}*/
