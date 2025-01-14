/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpayet <alpayet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 18:53:39 by alpayet           #+#    #+#             */
/*   Updated: 2024/11/10 15:27:08 by alpayet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_len_int(long n)
{
	int	count;
	int	i;

	count = 1;
	i = 1;
	while (n / i >= 10)
	{
		count++;
		i = 10 * i;
	}
	return (count);
}

static void	ft_fill_str(long n, char *n_str, int len)
{
	n_str[len - 1] = (n % 10) + '0';
	if (n >= 0 && n <= 9)
		return ;
	ft_fill_str(n / 10, n_str, len - 1);
}

char	*ft_itoa(int n)
{
	long	n_alt;
	char	*n_str;

	n_alt = (long)n;
	if (n_alt < 0)
	{
		n_str = malloc((ft_len_int(-n_alt) + 2) * sizeof(char));
		if (n_str == NULL)
			return (NULL);
		n_str[0] = '-';
		ft_fill_str(-n_alt, n_str, ft_len_int(-n_alt) + 1);
		n_str[ft_len_int(-n_alt) + 1] = '\0';
	}
	else
	{
		n_str = malloc((ft_len_int(n_alt) + 1) * sizeof(char));
		if (n_str == NULL)
			return (NULL);
		ft_fill_str(n_alt, n_str, ft_len_int(n_alt));
		n_str[ft_len_int(n_alt)] = '\0';
	}
	return (n_str);
}

/*int	main(void)
{
	printf("%s", ft_itoa(0));
}*/