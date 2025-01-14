/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpayet <alpayet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 17:57:56 by alpayet           #+#    #+#             */
/*   Updated: 2024/11/23 16:16:21 by alpayet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*s_char;
	size_t				i;

	c = (unsigned char)c;
	s_char = s;
	i = 0;
	while (i < n)
	{
		if (s_char[i] == c)
			return ((void *)(s + i));
		i++;
	}
	return (NULL);
}

/*#include <string.h>
int	main(void)
{
	int	dest[] = {1,2,3,44,5,6};
	int	i;
	int	*dest_chr;

	dest_chr = ft_memchr(dest, 44, sizeof(dest));
	i = 0;
	while (i != 3)
	{
		printf("%d \n", dest_chr[i]);
		i++;
	}
}*/