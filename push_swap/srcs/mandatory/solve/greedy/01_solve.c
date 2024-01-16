/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01_solve.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 15:31:25 by dong-kim          #+#    #+#             */
/*   Updated: 2023/06/21 02:46:45 by marvin           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	a_is_sorted(t_deque **deque_a)
{
	t_deque	*tail_a;

	tail_a = (*deque_a)->tail;
	if (less_than_three(deque_a) == TRUE)
		return (SORTED);
	if (tail_a)
	{
		while (tail_a)
		{
			if (tail_a->previous && \
				(tail_a->integer > tail_a->previous->integer))
				return (FALSE);
			tail_a = tail_a->previous;
		}
	}
	return (SORTED);
}

int	less_than_three(t_deque **deque_a)
{
	int	size;

	size = 0;
	if (*deque_a)
		size = deque_size(*deque_a);
	if (size == ONE)
		return (TRUE);
	if (size == TWO)
	{
		solve_two(deque_a);
		return (TRUE);
	}
	if (size == 3)
	{
		solve_three(deque_a, 0, 0, 0);
		return (TRUE);
	}
	return (FALSE);
}

void	solve_two(t_deque **deque_a)
{
	int	first;
	int	second;

	if (*deque_a == EMPTY)
		return ;
	first = (*deque_a)->tail->integer;
	second = (*deque_a)->tail->previous->integer;
	if (first < second)
		return ;
	else
		ra(deque_a, 1);
}

void	solve_three(t_deque **deque_a, int first, int second, int third)
{
	*deque_a = (*deque_a)->head;
	first = (*deque_a)->integer;
	second = (*deque_a)->next->integer;
	third = (*deque_a)->next->next->integer;
	if ((first < second) && (second > third) && (first > third))
	{
		sa(deque_a, PERFORM);
		ra(deque_a, PERFORM);
	}
	if ((first > second) && (second < third) && (first < third))
		ra(deque_a, PERFORM);
	if ((first < second) && (second > third) && (first < third))
		rra(deque_a, PERFORM);
	if ((first > second) && (second < third) && (first > third))
		sa(deque_a, PERFORM);
	if ((first < second) && (second < third) && (first < third))
	{
		sa(deque_a, PERFORM);
		rra(deque_a, PERFORM);
	}
}
