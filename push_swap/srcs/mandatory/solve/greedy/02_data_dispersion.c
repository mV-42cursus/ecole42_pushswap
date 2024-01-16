/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   02_data_dispersion.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 15:31:29 by dong-kim          #+#    #+#             */
/*   Updated: 2023/06/21 02:46:51 by marvin           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	greedy(t_deque **deque_a, t_deque **deque_b)
{
	int	size;

	size = deque_size(*deque_a);
	if (size >= 100)
	{
		allocate_idx(deque_a);
		sand_glass(deque_a, deque_b);
		return ;
	}
	else if (size > 50)
		preprocess_deque_a(deque_a, deque_b, size);
	else
	{
		while (size > 3)
		{
			pb(deque_a, deque_b);
			size--;
		}
		solve_three(deque_a, 0, 0, 0);
	}
	b_to_a(deque_a, deque_b);
	final_sort(deque_a, deque_b);
}

void	preprocess_deque_a(t_deque **deque_a, t_deque **deque_b, int size)
{
	t_deque	*head;
	int		*arr;

	arr = NULL;
	arr = (int *)malloc(sizeof(int) * size);
	head = (*deque_a)->head;
	arr = create_arr(arr, head);
	bubble_sort(&arr, size);
	perform(arr, deque_a, deque_b, size);
	solve_three(deque_a, 0, 0, 0);
	free(arr);
}

int	*create_arr(int *arr, t_deque *head)
{
	int	i;

	i = 0;
	while (head)
	{
		arr[i] = head->integer;
		head = head->next;
		i++;
	}
	return (arr);
}

void	perform(int *arr, t_deque **deque_a, t_deque **deque_b, int size)
{
	int	val;
	int	_size;

	val = 0;
	_size = size;
	while (_size)
	{
		val = (*deque_a)->tail->integer;
		if (_size == 3)
			break ;
		if (val > arr[(size / 3) * (3 - 2) - 1])
			ra(deque_a, PERFORM);
		else
		{
			pb(deque_a, deque_b);
			if (val < arr[(size / 3) * (3 - 1) - 1])
				rb(deque_b, PERFORM);
		}
		_size--;
	}
	remaining(deque_a, deque_b);
}

void	remaining(t_deque **deque_a, t_deque **deque_b)
{
	int	_size;

	_size = deque_size(*deque_a);
	while (_size > 3)
	{
		pb(deque_a, deque_b);
		_size--;
	}
}
