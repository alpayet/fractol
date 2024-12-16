/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpayet <alpayet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 16:57:03 by alpayet           #+#    #+#             */
/*   Updated: 2024/11/22 00:00:27 by alpayet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*lst_f_first;
	t_list	*lst_f_new;

	if (lst == NULL || f == NULL || del == NULL)
		return (NULL);
	lst_f_first = ft_lstnew(f(lst->content));
	if (lst_f_first == NULL)
		return (NULL);
	lst = lst->next;
	while (lst != NULL)
	{
		lst_f_new = ft_lstnew(f(lst->content));
		if (lst_f_new == NULL)
		{
			ft_lstclear(&lst_f_first, del);
			return (NULL);
		}
		ft_lstadd_back(&lst_f_first, lst_f_new);
		lst = lst->next;
	}
	return (lst_f_first);
}

