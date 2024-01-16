/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_pt1_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 14:01:30 by dong-kim          #+#    #+#             */
/*   Updated: 2023/06/21 03:21:43 by marvin           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

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
		solve_bonus(&deque_a, &deque_b);
		deque_memory_mng(deque_a);
		deque_memory_mng(deque_b);
		free(buffer);
	}
	return (0);
}

void	solve_bonus(t_deque **deque_a, t_deque **deque_b)
{
	char	*line;
	int		operation;

	line = NULL;
	operation = 0;
	while (1)
	{
		line = get_next_line(STD_INPUT);
		if (line == NULL)
			break ;
		if (is_valid_bonus(line) == TRUE)
			is_valid_bonus_case(deque_a, deque_b, line, operation);
		else
		{
			ft_putendl_fd("Error", 2);
			free(line);
			return ;
		}
	}
	display_result_bonus(deque_a, deque_b);
}

void	is_valid_bonus_case(t_deque **deque_a, t_deque **deque_b, \
							char *line, int operation)
{
	operation = allocate_operation(line);
	perform_bonus_op(deque_a, deque_b, operation);
	free(line);
}

int	is_valid_bonus(char *line)
{
	if (ft_strncmp(line, "sa", 2) == SAME && ft_strlen2(line) == 3)
		return (1);
	if (ft_strncmp(line, "sb", 2) == SAME && ft_strlen2(line) == 3)
		return (1);
	if (ft_strncmp(line, "ss", 2) == SAME && ft_strlen2(line) == 3)
		return (1);
	if (ft_strncmp(line, "pa", 2) == SAME && ft_strlen2(line) == 3)
		return (1);
	if (ft_strncmp(line, "pb", 2) == SAME && ft_strlen2(line) == 3)
		return (1);
	if (ft_strncmp(line, "ra", 2) == SAME && ft_strlen2(line) == 3)
		return (1);
	if (ft_strncmp(line, "rb", 2) == SAME && ft_strlen2(line) == 3)
		return (1);
	if (ft_strncmp(line, "rr", 2) == SAME && ft_strlen2(line) == 3)
		return (1);
	if (ft_strncmp(line, "rra", 3) == SAME && ft_strlen2(line) == 4)
		return (1);
	if (ft_strncmp(line, "rrb", 3) == SAME && ft_strlen2(line) == 4)
		return (1);
	if (ft_strncmp(line, "rrr", 3) == SAME && ft_strlen2(line) == 4)
		return (1);
	return (0);
}

int	allocate_operation(char *line)
{
	if (ft_strncmp(line, "sa", 2) == SAME && ft_strlen2(line) == 3)
		return (1);
	if (ft_strncmp(line, "sb", 2) == SAME && ft_strlen2(line) == 3)
		return (2);
	if (ft_strncmp(line, "ss", 2) == SAME && ft_strlen2(line) == 3)
		return (3);
	if (ft_strncmp(line, "pa", 2) == SAME && ft_strlen2(line) == 3)
		return (4);
	if (ft_strncmp(line, "pb", 2) == SAME && ft_strlen2(line) == 3)
		return (5);
	if (ft_strncmp(line, "ra", 2) == SAME && ft_strlen2(line) == 3)
		return (6);
	if (ft_strncmp(line, "rb", 2) == SAME && ft_strlen2(line) == 3)
		return (7);
	if (ft_strncmp(line, "rr", 2) == SAME && ft_strlen2(line) == 3)
		return (8);
	if (ft_strncmp(line, "rra", 3) == SAME && ft_strlen2(line) == 4)
		return (9);
	if (ft_strncmp(line, "rrb", 3) == SAME && ft_strlen2(line) == 4)
		return (10);
	if (ft_strncmp(line, "rrr", 3) == SAME && ft_strlen2(line) == 4)
		return (11);
	return (0);
}
