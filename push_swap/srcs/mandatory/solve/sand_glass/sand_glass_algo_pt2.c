/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sand_glass_algo_pt2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 15:32:26 by dong-kim          #+#    #+#             */
/*   Updated: 2023/06/21 02:47:13 by marvin           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*arr_init3(t_deque *deque_a, int *arr, int size)
{
	t_deque	*dup;
	int		i;

	dup = deque_a;
	i = 0;
	arr = (int *)malloc(sizeof(int) * size);
	if (!arr)
		exit(1);
	while (dup)
	{
		arr[i++] = dup->integer;
		dup = dup->next;
	}
	return (arr);
}

void	allocate_idx(t_deque **deque_a)
{
	t_deque		*dup;
	int			size;
	int			*arr;
	int			i;

	arr = NULL;
	size = deque_size(*deque_a);
	arr = arr_init3(*deque_a, arr, size);
	bubble_sort2(&arr, size);
	dup = *deque_a;
	i = 0;
	while (i < size)
	{
		while (dup)
		{	
			if (arr[i] == dup->integer)
				dup->index = i;
			dup = dup->next;
		}
		dup = *deque_a;
		i++;
	}
	free(arr);
}

void	b2a(t_deque **deque_a, t_deque **deque_b)
{
	t_deque		*target;
	int			head_loc;
	int			continue_flag;

	target = NULL;
	head_loc = 0;
	continue_flag = 0;
	while (1)
	{
		if (deque_size(*deque_b) == EMPTY)
			break ;
		allocate_loc(*deque_a, *deque_b);
		target = find_max2(deque_b);
		head_loc = (*deque_b)->head->loc;
		if (target->loc < head_loc / 2)
		{
			perform_pa_rb(target, deque_a, deque_b, &continue_flag);
			if (continue_flag == 1)
				continue ;
		}
		else
			perform_rrb(target, head_loc, deque_b);
		pa(deque_a, deque_b);
	}
}

void	perform_pa_rb(t_deque *target, t_deque **deque_a, \
					t_deque **deque_b, int *continue_flag)
{
	if (target->loc == target->tail->loc)
	{
		pa(deque_a, deque_b);
		*continue_flag = 1;
		return ;
	}
	while (target->loc > 0)
	{
		*continue_flag = 0;
		rb(deque_b, PERFORM);
		target->loc--;
	}
}

void	perform_rrb(t_deque *target, int head_loc, t_deque **deque_b)
{
	while (target->loc < head_loc + 1)
	{
		rrb(deque_b, PERFORM);
		target->loc++;
	}
}
