/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_utils_pt2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 15:32:37 by dong-kim          #+#    #+#             */
/*   Updated: 2023/06/21 02:47:32 by marvin           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	calculate_cost(t_deque *tail)
{
	size_t	cost;

	cost = 0;
	cost += record_a_cnt(tail);
	cost += record_b_cnt(tail);
	cost += record_move_cnt(tail);
	tail->cost = cost;
}

size_t	record_a_cnt(t_deque *tail)
{
	size_t		cost;
	t_record	*begin;

	cost = 0;
	begin = tail->record_a;
	while (tail->record_a)
	{
		cost++;
		tail->record_a = tail->record_a->next;
	}
	tail->record_a = begin;
	return (cost);
}

size_t	record_b_cnt(t_deque *tail)
{
	size_t		cost;
	t_record	*begin;

	cost = 0;
	begin = tail->record_b;
	while (tail->record_b)
	{
		cost++;
		tail->record_b = tail->record_b->next;
	}
	tail->record_b = begin;
	return (cost);
}

size_t	record_move_cnt(t_deque *tail)
{
	size_t		cost;
	t_record	*begin;

	cost = 0;
	begin = tail->record_move;
	while (tail->record_move)
	{
		cost++;
		tail->record_move = tail->record_move->next;
	}
	tail->record_move = begin;
	return (cost);
}

void	record_move(t_deque *tail, int letter)
{
	if (letter == A)
		record_add_back(&(tail->record_move), PB);
	if (letter == B)
		record_add_back(&(tail->record_move), PA);
}
