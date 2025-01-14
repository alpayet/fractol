/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpayet <alpayet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 21:16:41 by alpayet           #+#    #+#             */
/*   Updated: 2024/11/24 20:11:27 by alpayet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_numof_set_start(char const *s1, char const *set)
{
	int	i;

	i = 0;
	while (s1[i])
	{
		if (ft_strchr(set, s1[i]) == NULL)
			return (i);
		i++;
	}
	return (i);
}

static int	ft_numof_set_end(char const *s1, char const *set)
{
	int		i;
	size_t	len;

	i = 0;
	len = ft_strlen(s1);
	while (s1[i])
	{
		if (ft_strchr(set, s1[len - 1 - i]) == NULL)
			return (i);
		i++;
	}
	return (i);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int			index;
	size_t		size_s1_trim;

	if (s1 == NULL || set == NULL)
		return (NULL);
	if ((size_t)ft_numof_set_start(s1, set) == ft_strlen(s1))
		size_s1_trim = 0;
	else
	{
		size_s1_trim = ft_strlen(s1) - (ft_numof_set_start(s1, set)
				+ ft_numof_set_end(s1, set));
	}
	index = ft_numof_set_start(s1, set);
	return (ft_substr(s1, index, size_s1_trim));
}

/* int	main(void)
{
	printf("%s", ft_strtrim(" bonjour aurevoir  ", " "));
} */
