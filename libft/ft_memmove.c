/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpayet <alpayet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 17:37:27 by alpayet           #+#    #+#             */
/*   Updated: 2024/11/22 01:45:37 by alpayet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t			i;
	char			*dest_char;
	const char		*src_char;

	dest_char = dest;
	src_char = src;
	i = 0;
	if (dest <= src)
		ft_memcpy(dest, src, n);
	else
	{
		while (i < n)
		{
			dest_char[(n - 1) - i] = src_char[(n - 1) - i];
			i++;
		}
	}
	return (dest);
}

/*#include <string.h>
int	main(void)
{
	char	dest[] = "abcdefg";
	memmove(NULL ,dest + 3,2);
	printf("%s", dest);
}*/