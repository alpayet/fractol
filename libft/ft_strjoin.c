/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpayet <alpayet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 20:49:43 by alpayet           #+#    #+#             */
/*   Updated: 2024/11/23 16:19:48 by alpayet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char		*s1_s2_conc;
	size_t		size_s1_s2_conc;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	size_s1_s2_conc = ft_strlen(s1) + ft_strlen(s2) + 1;
	s1_s2_conc = malloc(sizeof(char) * size_s1_s2_conc);
	if (s1_s2_conc == NULL)
		return (NULL);
	s1_s2_conc[0] = '\0';
	ft_strlcat(s1_s2_conc, s1, size_s1_s2_conc);
	ft_strlcat(s1_s2_conc, s2, size_s1_s2_conc);
	return (s1_s2_conc);
}

/*int	main(void)
{
	printf("%s\n", ft_strjoin("abcd", "efgh"));
	printf("%s", ft_strjoin("abcd", ""));
}*/
