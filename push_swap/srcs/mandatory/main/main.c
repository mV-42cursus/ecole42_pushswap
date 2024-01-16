/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 15:31:53 by dong-kim          #+#    #+#             */
/*   Updated: 2023/06/22 01:26:12 by marvin           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char *av[])
{
	t_deque	*deque_a;
	t_deque	*deque_b;
	int		*buffer;
	int		size;

	deque_a = NULL;
	deque_b = NULL;
	buffer = NULL;
	size = 0;
	if (ac == 1)
		return (0);
	if (is_valid(ac, av, &buffer, &size) == ERROR)
		ft_putendl_fd("Error", 2);
	else
	{
		deque_a = deque_init(deque_a, buffer, 0, size);
		solve(&deque_a, &deque_b);
		deque_memory_mng(deque_a);
		deque_memory_mng(deque_b);
		free(buffer);
	}
	return (0);
}
