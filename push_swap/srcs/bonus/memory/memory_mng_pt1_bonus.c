/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_mng_pt1_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 15:31:56 by dong-kim          #+#    #+#             */
/*   Updated: 2023/06/21 03:21:38 by marvin           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	deque_memory_mng(t_deque *deque)
{
	t_deque	*ptr;

	if (deque)
	{
		ptr = deque->head;
		deque = deque->head;
	}
	while (deque)
	{
		ptr = deque;
		deque = deque->next;
		free(ptr);
	}
	deque = NULL;
}
