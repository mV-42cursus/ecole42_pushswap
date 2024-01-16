/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 00:36:17 by dong-kim          #+#    #+#             */
/*   Updated: 2023/06/19 02:46:26 by marvin           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_list	*node_check(void *value, t_list *begin_lst, void (*del)(void *))
{
	del(value);
	ft_lstclear(&begin_lst, del);
	return (NULL);
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*begin_lst;
	t_list	*node;
	void	*value;

	begin_lst = NULL;
	node = NULL;
	while (lst)
	{
		value = f(lst->content);
		if (value)
		{
			node = ft_lstnew(value);
			if (!node)
				return (node_check(value, begin_lst, del));
			ft_lstadd_back(&begin_lst, node);
			lst = lst->next;
		}
		else
		{
			ft_lstclear(&begin_lst, del);
			return (NULL);
		}
	}
	return (begin_lst);
}
