/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   03_b_to_a_pt2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 15:31:33 by dong-kim          #+#    #+#             */
/*   Updated: 2023/06/21 02:46:57 by marvin           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	record_b2(t_deque *tail_b)
{
	int	loc;

	loc = tail_b->loc;
	if (tail_b->loc <= tail_b->head->loc / 2)
		record_rb(tail_b, loc);
	if (tail_b->loc > tail_b->head->loc / 2)
		record_rrb(tail_b, loc);
}

void	record_rb(t_deque *tail_b, int loc)
{
	while (loc != 0)
	{
		record_add_back(&(tail_b->record_b), RB);
		loc--;
	}
}

void	record_rrb(t_deque *tail_b, int loc)
{
	if (tail_b->loc == tail_b->head->loc)
	{
		record_add_back(&(tail_b->record_b), RRB);
		return ;
	}
	while (loc != tail_b->head->loc + 1)
	{
		record_add_back(&(tail_b->record_b), RRB);
		loc++;
	}
}

int	*arr_init2(t_deque *tail_a, int tail_b_integer, int *size)
{
	int	*arr;
	int	i;

	*size = deque_size(tail_a) + 1;
	arr = (int *)malloc(sizeof(int) * (*size));
	if (!arr)
		exit(1);
	i = 0;
	while (tail_a)
	{
		arr[i++] = tail_a->integer;
		tail_a = tail_a->previous;
	}
	arr[i] = tail_b_integer;
	return (arr);
}

int	find_val_loc(t_deque *tail_a, int val)
{
	while (tail_a)
	{
		if (tail_a->integer == val)
			break ;
		tail_a = tail_a->previous;
	}
	return (tail_a->loc);
}
