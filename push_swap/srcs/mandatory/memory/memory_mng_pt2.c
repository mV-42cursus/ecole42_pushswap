/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_mng_pt2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 15:31:57 by dong-kim          #+#    #+#             */
/*   Updated: 2023/06/21 02:46:18 by marvin           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_move(t_deque *deque)
{
	t_record	*ptr;

	ptr = NULL;
	while (deque)
	{
		if (deque->record_move)
		{
			while (deque->record_move)
			{
				ptr = deque->record_move->next;
				free(deque->record_move);
				deque->record_move = ptr;
			}
		}
		deque = deque->next;
	}
}

void	free_greedy(t_deque *deque)
{
	t_record	*ptr;

	ptr = NULL;
	while (deque)
	{
		if (deque->record_greedy)
		{
			while (deque->record_greedy)
			{
				ptr = deque->record_greedy->next;
				free(deque->record_greedy);
				deque->record_greedy = ptr;
			}
		}
		deque = deque->next;
	}	
}

void	free_idx_lst(t_index *idx_lst)
{
	t_index	*ptr;

	ptr = NULL;
	while (idx_lst)
	{
		ptr = idx_lst->next;
		free(idx_lst);
		idx_lst = ptr;
	}
}
