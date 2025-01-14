/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpayet <alpayet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 16:57:03 by alpayet           #+#    #+#             */
/*   Updated: 2024/11/23 16:34:03 by alpayet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*lst_f_first;
	t_list	*lst_f_new;
	void	*f_content;

	if (lst == NULL || f == NULL || del == NULL)
		return (NULL);
	lst_f_first = NULL;
	while (lst != NULL)
	{
		f_content = f(lst->content);
		lst_f_new = ft_lstnew(f_content);
		if (lst_f_new == NULL)
		{
			del(f_content);
			ft_lstclear(&lst_f_first, del);
			return (NULL);
		}
		ft_lstadd_back(&lst_f_first, lst_f_new);
		lst = lst->next;
	}
	return (lst_f_first);
}
