/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpayet <alpayet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 22:55:11 by alpayet           #+#    #+#             */
/*   Updated: 2024/11/24 00:06:23 by alpayet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*a;

	if (nmemb == 0 || size == 0)
		return (malloc(0));
	if (nmemb > (SIZE_MAX / size))
		return (NULL);
	a = malloc(nmemb * size);
	if (a == NULL)
		return (NULL);
	ft_bzero(a, nmemb * size);
	return (a);
}

/*int	main(void)
{
	int	*tab;
	unsigned long	i;

	tab = (int *)ft_calloc(4294967295, 1);
	i = 4294967295;
	printf("%p", tab);

}*/