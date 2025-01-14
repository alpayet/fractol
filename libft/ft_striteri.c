/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpayet <alpayet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 23:28:58 by alpayet           #+#    #+#             */
/*   Updated: 2024/11/23 01:48:33 by alpayet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	int	i;

	i = 0;
	if (s == NULL || f == NULL)
		return ;
	while (s[i])
	{
		f(i, &(s[i]));
		i++;
	}
}
/*void	ft_next_letter(unsigned int i, char *a)
{
	*a = *a + 1;
}
int	main(void)
{
	char s[] = "abcde";
	ft_striteri(s, ft_next_letter);
	printf("%s", s);
}*/