/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_utils_pt3.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 15:32:39 by dong-kim          #+#    #+#             */
/*   Updated: 2023/06/21 02:47:37 by marvin           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	solve(t_deque **deque_a, t_deque **deque_b)
{
	if (*deque_a == EMPTY)
		return ;
	if (a_is_sorted(deque_a) == SORTED)
		return ;
	greedy(deque_a, deque_b);
}

void	toss_node(t_deque **deque_a, t_deque **deque_b, int letter)
{
	t_deque	*cheapest;

	calculate_final_cost(*deque_a);
	if (letter == A)
		cheapest = find_cheapest_node(*deque_a);
	if (letter == B)
		cheapest = find_cheapest_node(*deque_b);
	initiate_op(cheapest->record_greedy, deque_a, deque_b);
}

t_deque	*find_cheapest_node(t_deque *deque)
{
	t_deque	*begin;
	t_deque	*tail;
	int		cheapest;

	tail = deque->tail;
	begin = tail;
	cheapest = tail->cost;
	while (begin)
	{
		if (cheapest > begin->cost)
			cheapest = begin->cost;
		begin = begin->previous;
	}
	begin = tail;
	while (begin)
	{
		if (begin->cost == cheapest)
			break ;
		begin = begin->previous;
	}
	return (begin);
}

void	calculate_final_cost(t_deque *deque_a)
{
	t_record	*begin;
	int			cost;

	begin = NULL;
	cost = 0;
	while (deque_a)
	{
		begin = deque_a->record_greedy;
		while (deque_a->record_greedy)
		{
			cost++;
			deque_a->record_greedy = deque_a->record_greedy->next;
		}
		deque_a->record_greedy = begin;
		deque_a->cost = cost;
		deque_a = deque_a->next;
	}
}

void	initiate_op(t_record *record, t_deque **deque_a, t_deque **deque_b)
{
	while (record)
	{
		if (record->operation[0] == PA)
			pa(deque_a, deque_b);
		if (record->operation[0] == PB)
			pb(deque_a, deque_b);
		if (record->operation[0] == RA)
			ra(deque_a, PERFORM);
		if (record->operation[0] == RB)
			rb(deque_b, PERFORM);
		if (record->operation[0] == RR)
			rr(deque_a, deque_b);
		if (record->operation[0] == RRA)
			rra(deque_a, PERFORM);
		if (record->operation[0] == RRB)
			rrb(deque_b, PERFORM);
		if (record->operation[0] == RRR)
			rrr(deque_a, deque_b);
		record = record->next;
	}
}
