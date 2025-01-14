/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpayet <alpayet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 18:56:27 by alpayet           #+#    #+#             */
/*   Updated: 2024/11/23 16:16:39 by alpayet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t				i;
	const unsigned char	*s1_char;
	const unsigned char	*s2_char;

	s1_char = s1;
	s2_char = s2;
	i = 0;
	while (i < n)
	{
		if (s1_char[i] != s2_char[i])
			return (s1_char[i] - s2_char[i]);
		i++;
	}
	return (0);
}

/*#include <string.h>
int	main(void)
{
	int	s1[] = {1, 2, 3, 4, 5};
	int	s2[] = {1, 2, 3, 0, 5};

	printf("%d", ft_memcmp(s1, s2, 20));
}*/