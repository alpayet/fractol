/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpayet <alpayet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 15:57:46 by alpayet           #+#    #+#             */
/*   Updated: 2024/11/23 16:30:51 by alpayet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t				i;
	unsigned char		*dest_char;
	const unsigned char	*src_char;

	dest_char = dest;
	src_char = src;
	i = 0;
	while (i < n)
	{
		dest_char[i] = src_char[i];
		i++;
	}
	return (dest);
}

/*#include <string.h>
int	main(void)
{
	char	dest[] = "abcdefg";
	int	src[]= {1,12,3,4};
	printf("%s\n", dest);
	ft_memcpy(dest, src, 16);
	printf("%d", dest[0]);
}*/