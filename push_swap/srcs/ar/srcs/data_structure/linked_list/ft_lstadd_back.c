/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 20:00:47 by dong-kim          #+#    #+#             */
/*   Updated: 2023/06/22 01:25:53 by marvin           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*p;

	p = ft_lstlast(*lst);
	if (*lst == NULL)
		(*lst) = new;
	else
	{
		p = ft_lstlast(*lst);
		p->next = new;
	}
}

// void	ft_print_result(t_list *elem)
// {
// 	int		len;
// 	len = 0;
// 	while (((char *)elem->content)[len])
// 		len++;
// 	write(1, elem->content, len);
// 	write(1, "\n", 1);
// }
// t_list	*ft_lstnewone(void *content)
// {
// 	t_list	*elem;
// 	elem = (t_list *)malloc(sizeof(t_list));
// 	if (!elem)
// 		return (NULL);
// 	if (!content)
// 		elem->content = NULL;
// 	else
// 		elem->content = content;
// 	elem->next = NULL;
// 	return (elem);
// }
// void ft_display_lst(t_list *head)
// {
// 	while (head)
// 	{
// 		printf("[%p]\t", head);
// 		printf("[%s]\n", (char *)head->content);
// 		head = head->next;
// 	}
// }
// #include <stdio.h>
// int main(int argc, const char *argv[])
// {
// 	// t_list		*begin;
// 	// t_list		*elem;
// 	// t_list		*elem2;
// 	// t_list		*elem3;
// 	// t_list		*elem4;
// 	// char		*str = strdup("lorem");
// 	// char		*str2 = strdup("ipsum");
// 	// char		*str3 = strdup("dolor");
// 	// char		*str4 = strdup("sit");
// 	// elem = ft_lstnewone(str);
// 	// elem2 = ft_lstnewone(str2);
// 	// elem3 = ft_lstnewone(str3);
// 	// elem4 = ft_lstnewone(str4);
// 	// // alarm(TIMEOUT);
// 	// if (argc == 1 || !elem || !elem2 || !elem3 || !elem4)
// 	// 	return (0);
// 	// else if (atoi(argv[1]) == 1)
// 	// {
// 	// 	begin = NULL;
// 	// 	ft_lstadd_back(&begin, elem);
// 	// 	ft_lstadd_back(&begin, elem2);
// 	// 	ft_lstadd_back(&begin, elem3);
// 	// 	ft_lstadd_back(&begin, elem4);
// 	// 	while (begin)
// 	// 	{
// 	// 		ft_print_result(begin);
// 	// 		begin = begin->next;
// 	// 	}
// 	// }
// 	t_list *l =  NULL; 
// 	t_list *l2 =  NULL;
// 	ft_lstadd_back(&l, ft_lstnew((void*)1));
// 	/* 1 */ 
// 	if (l->content == (void*)1)
// 		printf("True\n");
// 	else
// 		puts("False\n");
// 	/* 2 */ 
// 	if (l->next == 0)
// 		printf("True\n");
// 	else
// 		puts("False\n");
// 	ft_lstadd_back(&l, ft_lstnew((void*)2));
// 	/* 3 */ 
// 	if(l->content == (void*)1)
// 		printf("True\n");
// 	else
// 		puts("False\n");
// 	/* 4 */ 
// 	if(((t_list *)(l->next))->content == (void*)2)
// 		printf("True\n");
// 	else
// 		puts("False\n");
// 	/* 5 */ 
// 	if(((t_list *)(l->next))->next == 0)
// 		printf("True\n");
// 	else
// 		puts("False\n");
// 	ft_lstadd_back(&l2, ft_lstnew((void*)3));
// 	ft_lstadd_back(&l2, ft_lstnew((void*)4));
// 	ft_lstadd_back(&l, l2);
// 	/* 6 */ 
// 	if(l->content == (void*)1)
// 		printf("True\n");
// 	else
// 		puts("False\n");
// 	/* 7 */
// 	if(((t_list *)(l->next))->content == (void*)2)
// 		printf("True\n");
// 	else
// 		puts("False\n");
// 	/* 8 */ 
// 	if(((t_list *)(((t_list *)(l->next))->next))->content == (void*)3)
// 		printf("True\n");
// 	else
// 		puts("False\n");
// 	/* 9 */ // @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
// 	/*
// 		p = ft_lstlast(*lst);
// 		new->next = NULL; @@@@@@@@@@@@@@@@ this was the problem @@@@@@
// 		p->next = new;
// 	*/
// 	if(((t_list *)
// 		 ((t_list *)(((t_list *)(l->next))->next))->next)->content == (void*)4)
// 		printf("True\n");
// 	else
// 		puts("False\n");
// 	/* 10 */ 
// 	if(((t_list *)((t_list *)(((t_list *)(l->next))->next))->next)->next == 0)
// 		printf("True\n");
// 	else
// 		puts("False\n");
// 	return (0);
// }