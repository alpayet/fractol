/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpayet <alpayet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 14:06:27 by alpayet           #+#    #+#             */
/*   Updated: 2024/11/23 01:39:54 by alpayet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_word(char const *s, char c)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	j = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			count++;
			j = 0;
			while ((s + i)[j])
			{
				if ((s + i)[j] == c)
					break ;
				j++;
			}
			i = i + j - 1;
		}
		i++;
	}
	return (count);
}

static void	ft_word_size(char const *s, char **tab, char c)
{
	int	i;
	int	j;
	int	index;

	i = 0;
	j = 0;
	index = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			j = 0;
			while ((s + i)[j])
			{
				if ((s + i)[j] == c)
					break ;
				j++;
			}
			tab[index] = ft_calloc(1, j + 1);
			index++;
			i = i + j - 1;
		}
		i++;
	}
}

static void	ft_filling(char const *s, char **tab, char c)
{
	int	i;
	int	j;
	int	index;

	i = 0;
	j = 0;
	index = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			j = 0;
			while ((s + i)[j])
			{
				if ((s + i)[j] == c)
					break ;
				tab[index][j] = (s + i)[j];
				j++;
			}
			index++;
			i = i + j - 1;
		}
		i++;
	}
}

static int	ft_free(char **tab, int len)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < len)
	{
		if (tab[i] == NULL)
		{
			while (j < len)
			{
				free(tab[j]);
				tab[j] = NULL;
				j++;
			}
			free(tab);
			tab = NULL;
			return (0);
		}
		i++;
	}
	return (1);
}

char	**ft_split(char const *s, char c)
{
	char	**tab;
	int		tab_size;

	if (s == NULL)
		return (NULL);
	tab_size = count_word(s, c);
	tab = malloc((tab_size + 1) * sizeof(char *));
	if (tab == NULL)
		return (NULL);
	tab[tab_size] = NULL;
	ft_word_size(s, tab, c);
	if (ft_free(tab, tab_size) == 0)
		return (NULL);
	ft_filling(s, tab, c);
	return (tab);
}

/*int	main(void)
{
	int	i;
	char const *s;
	s = NULL;

	i = 0;
	while (ft_split(s, 'c')[i] != NULL)
	{
		printf("%s\n", ft_split("caaccaabbccc", 'c')[i]);
		i++;
	}
}*/