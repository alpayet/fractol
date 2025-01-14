/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpayet <alpayet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 23:28:01 by alpayet           #+#    #+#             */
/*   Updated: 2024/11/24 20:10:03 by alpayet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (new == NULL || lst == NULL)
		return ;
	new->next = *lst;
	*lst = new;
}
/* int	main(void)
{
	t_list	*first;
	t_list	*new;

	first = ft_lstnew("first");
	new = ft_lstnew("new first");
	ft_lstadd_front(&first, new);
	if (first == new && new->next->content == "first")
		printf("New a bien été ajouter au debut de la liste");
	else
		printf("New n'a pas été ajouter à la liste");
} */
