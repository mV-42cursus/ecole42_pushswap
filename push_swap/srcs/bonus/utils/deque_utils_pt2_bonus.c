/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deque_utils_pt2_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 15:31:46 by dong-kim          #+#    #+#             */
/*   Updated: 2023/06/21 03:21:47 by marvin           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	deque_size(t_deque *deque)
{
	t_deque	*tail;
	int		size;

	tail = NULL;
	size = 0;
	if (deque)
		tail = deque->tail;
	while (tail)
	{
		size++;
		tail = tail->previous;
	}
	return (size);
}
