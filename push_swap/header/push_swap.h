/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 15:32:22 by dong-kim          #+#    #+#             */
/*   Updated: 2023/06/22 01:55:16 by marvin           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>

typedef struct s_deque
{
	int					integer;
	int					loc;
	int					cost;
	int					index;
	struct s_deque		*next;
	struct s_deque		*previous;
	struct s_deque		*head;
	struct s_deque		*tail;
	struct s_record		*record_a;
	struct s_record		*record_b;
	struct s_record		*record_move;
	struct s_record		*record_greedy;
}	t_deque;

typedef struct s_record
{
	int				operation[1];
	struct s_record	*next;
}	t_record;

typedef struct s_index
{
	int				integer;
	size_t			index;
	struct s_index	*next;
}					t_index;

enum e_operation_signal
{
	SA = 1,
	SB,
	SS,
	PA,
	PB,
	RA,
	RB,
	RR,
	RRA,
	RRB,
	RRR,
};

# define EMPTY 0
# define ERROR 0
# define ONE 1
# define TWO 2
# define THREE 3
# define SORTED 1
# define TRUE 1
# define FALSE 0
# define PERFORM 1
# define NOT_PERFORM 0
# define CAN_OPTIMIZE 1
# define CANNOT_OPTIMIZE 0
# define A 'A'
# define B 'B'
# define FOUR 3
# define FIVE 4

/* libft.a */
void		ft_putendl_fd(char *s, int fd);
void		ft_putstr(char *str);

/* main.c */
int			main(int ac, char *av[]);

/* parse_pt1.c */
int			is_valid(int ac, char *av[], int **buffer, int *size);
int			ft_strlen2(char *str);
int			is_wrongly_delimited(char *av[]);
int			is_only_delimited(char *av[]);
int			is_redundant(int ***buffer, int **size);

/* parse_pt2.c */
int			is_empty_string(int ac, char **av);
int			is_double_sign(char **av);
int			is_double(char **av, int _i, int i);
int			is_overflow(char **candidate, int ***buffer, int **size);
int			push_swap_atoi(char *str, int *overflow);

/* parse_pt3.c */
int			is_int_range(long res, char c, long sign);
int			is_non_numeric(char *av[]);
int			is_alpha(char c);
void		deque_head_tail(t_deque *deque);

/* push_swap_split.c */
char		**ft_split_ps(char **av, char c);
size_t		ft_count_words_ps(char **av, char c);
size_t		ft_count_wordlen_ps(char *s, char c);
char		**ft_memory_manager_ps(char **res, size_t rotation);
void		ft_word_cpy_ps(char ***res, char *s, size_t word_len, \
						size_t rotation);

/* deque_initialize.c */
t_deque		*deque_init(t_deque *node, int *buffer, int i, int size);
t_deque		*node_init(t_deque *node);
void		node_add_front(t_deque **node, t_deque *new);
void		node_add_back(t_deque **node, t_deque *new);

/* deque_utils_pt1.c */
t_deque		*deque_pop_front(t_deque **deque);
t_deque		*deque_pop_back(t_deque **deque);
void		deque_push_front(t_deque **deque, t_deque *new);
void		deque_push_back(t_deque **deque, t_deque *new);

/* deque_utils_pt2.c */
int			deque_size(t_deque *deque);
void		record_add_back(t_record **node, int op);

/* operations_pt1.c */
int			sa(t_deque **deque_a, int flag);
int			sb(t_deque **deque_b, int flag);
int			ss(t_deque **deque_a, t_deque **deque_b);

/* operations_pt2.c */
int			pa(t_deque **deque_a, t_deque **deque_b);
int			pb(t_deque **deque_a, t_deque **deque_b);
int			ra(t_deque **deque_a, int flag);
int			rb(t_deque **deque_b, int flag);

/* operations_pt3.c */
int			rr(t_deque **deque_a, t_deque **deque_b);
int			rra(t_deque **deque_a, int flag);
int			rrb(t_deque **deque_b, int flag);
int			rrr(t_deque **deque_a, t_deque **deque_b);

/* 01_solve.c */
int			a_is_sorted(t_deque **deque_a);
int			less_than_three(t_deque **deque_a);
void		solve_two(t_deque **deque_a);
void		solve_three(t_deque **deque_a, int first, \
						int second, int third);

/* 02_data_dispersion.c */
void		greedy(t_deque **deque_a, t_deque **deque_b);
void		preprocess_deque_a(t_deque **deque_a, t_deque **deque_b, \
								int size);
int			*create_arr(int *arr, t_deque *a);
void		perform(int *arr, t_deque **deque_a, t_deque **deque_b, int size);
void		remaining(t_deque **deque_a, t_deque **deque_b);

/* 03_b_to_a_pt1.c */
void		b_to_a(t_deque **deque_a, t_deque **deque_b);
void		toss_one_b2a(t_deque **deque_a, t_deque **deque_b);
void		record_a2(t_deque *tail_a, t_deque *tail_b);
void		record_ra(int down_loc, int *arr, t_deque *tail_b);
void		record_rra(int down_loc, int *arr, t_deque *tail_a, \
						t_deque *tail_b);

/* 03_b_to_a_pt2.c */
void		record_b2(t_deque *tail_b);
void		record_rb(t_deque *tail_b, int loc);
void		record_rrb(t_deque *tail_b, int loc);
int			*arr_init2(t_deque *tail_a, int tail_b_integer, int *size);
int			find_val_loc(t_deque *tail_a, int up);

/* 03_b_to_a_pt3.c */
void		bubble_sort2(int **arr, int size);
int			find_down(int *arr, int size, int tail_b_integer);
int			find_up(int *arr, int size, int tail_b_integer);
void		optimize_record(t_deque *deque_a);
int			is_not_optimized(t_deque *deque_a);

/* 03_b_to_a_pt4.c */
int			find_arr_size(t_deque *deque_a, int flag);
int			find_best_case(t_deque *deque_a);
int			find_original_case(t_deque *deque_a);
int			*arr_init(int *arr, int size, int flag, t_deque *deque_a);
void		optimize1(int size_a, int size_b, t_deque *deque_a, int *arr);

/* 03_b_to_a_pt5.c */
void		optimize2(int size_a, int size_b, t_deque *deque_a, int *arr);
void		do_not_optimize(int size_a, int size_b, t_deque *deque_a, int *arr);
void		create_record_greedy(int *arr, int size, t_deque *deque_a);

/* 04_final_sort.c */
void		final_sort(t_deque **deque_a, t_deque **deque_b);
int			find_min(t_deque *deque_a);
int			find_min_loc(t_deque *deque_a, int min);
void		push_down(t_deque **deque_a, int min);
void		push_up(t_deque **deque_a, int min);

/* sand_glass_algo_pt1.c */
void		sand_glass(t_deque **deque_a, t_deque **deque_b);
int			ra_is_beter(t_deque *deque_a, int _pivot);
void		a2b(t_deque **deque_a, t_deque **deque_b);
void		perform_sand_glass(int *info, int *idx, t_deque **deque_a, \
								t_deque **deque_b);
void		avoid_worst_case(t_deque **deque_a, t_deque **deque_b, int idx, \
							int pivot);

/* sand_glass_algo_pt2.c */
int			*arr_init3(t_deque *deque_a, int *arr, int size);
void		allocate_idx(t_deque **deque_a);
void		b2a(t_deque **deque_a, t_deque **deque_b);
void		perform_pa_rb(t_deque *target, t_deque **deque_a, \
						t_deque **deque_b, int *continue_flag);
void		perform_rrb(t_deque *target, int head_loc, t_deque **deque_b);

/* sand_glass_algo_pt3.c */
t_deque		*find_max2(t_deque **deque_b);

/* sorting_utils_pt1.c */
void		allocate_loc(t_deque *deque_a, t_deque *deque_b);
void		initialize_cost(t_deque *deque_a, t_deque *deque_b);
int			is_all_calculated(t_deque *deque);
int			record_size(t_record *record);
void		bubble_sort(int **arr, int size);

/* sorting_utils_pt2.c */
void		calculate_cost(t_deque *deque_a);
size_t		record_a_cnt(t_deque *tail);
size_t		record_b_cnt(t_deque *tail);
size_t		record_move_cnt(t_deque *tail);
void		record_move(t_deque *tail, int letter);

/* sorting_utils_pt3.c */
void		solve(t_deque **deque_a, t_deque **deque_b);
void		toss_node(t_deque **deque_a, t_deque **deque_b, int letter);
t_deque		*find_cheapest_node(t_deque *deque_a);
void		calculate_final_cost(t_deque *deque_a);
void		initiate_op(t_record *record, t_deque **deque_a, t_deque **deque_b);

/* memory_mng_pt1.c */
void		deque_memory_mng(t_deque *deque);
void		free_record(t_deque *deque_a, t_deque *deque_b);
void		free_record_a(t_deque *deque);
void		free_record_b(t_deque *deque);

/* memory_mng_pt2.c */
void		free_move(t_deque *deque);
void		free_greedy(t_deque *deque);
void		free_idx_lst(t_index *idx_lst);

#endif