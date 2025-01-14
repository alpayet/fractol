/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpayet <alpayet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 23:10:39 by alpayet           #+#    #+#             */
/*   Updated: 2024/11/24 05:46:45 by alpayet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*str_fct;
	int		i;

	if (s == NULL || f == NULL)
		return (NULL);
	str_fct = malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (str_fct == NULL)
		return (NULL);
	i = 0;
	while (s[i])
	{
		str_fct[i] = f(i, s[i]);
		i++;
	}
	str_fct[i] = '\0';
	return (str_fct);
}
/* char	ft_a(unsigned int i, char a)
{
	return('a' + i);
}
int	main(void)
{
	printf("%s", ft_strmapi("abcde", ft_a));
} */
