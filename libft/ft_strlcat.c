/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpayet <alpayet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 20:41:24 by alpayet           #+#    #+#             */
/*   Updated: 2024/11/22 02:08:05 by alpayet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (dst[i])
		i++;
	while ((size != 0) && ((i + j) < (size - 1)) && (src[j] != '\0'))
	{
		dst[i + j] = src[j];
		j++;
	}
	dst[i + j] = '\0';
	if (size < i)
		return (ft_strlen(src) + size);
	return (i + ft_strlen(src));
}

/*#include <string.h>
int	main(void)
{
	char dest[20] = "Bonjour, ";
    char *src = "42";
	printf("%d", ft_strlcat(dest, src, 7));
	printf("%s", dest);
}*/