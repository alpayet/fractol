/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpayet <alpayet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 14:28:51 by alpayet           #+#    #+#             */
/*   Updated: 2024/11/11 12:15:10 by alpayet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;
	int	buff;

	i = 0;
	buff = -1;
	c = (char)c;
	while (s[i])
	{
		if (s[i] == c)
			buff = i;
		i++;
	}
	if (c == '\0')
		return ((char *)(s + i));
	if (buff != -1)
		return ((char *)(s + buff));
	return (0);
}

/*#include <string.h>
int	main(void)
{
	//printf("%s", strrchr("abcdaf", 256));
	printf("%s", ft_strrchr("abcdaf", 356));
}*/