/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 15:32:22 by dong-kim          #+#    #+#             */
/*   Updated: 2023/06/22 01:55:18 by marvin           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

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
# define STD_INPUT 0
# define SAME 0
# define NOT_SAME 1
# define TRUE 1
# define PERFORM 1
# define NOT_PERFORM 0
# define ONE 1

/* libft.a */
char		*get_next_line(int fd);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
void		ft_putendl_fd(char *s, int fd);

/* main_pt1_bonus.c */
int			main(int ac, char *av[]);
void		solve_bonus(t_deque **deque_a, t_deque **deque_b);
void		is_valid_bonus_case(t_deque **deque_a, \
				t_deque **deque_b, char *line, int operation);
int			is_valid_bonus(char *line);
int			allocate_operation(char *line);

/* main_pt2_bonus.c */
int			is_sorted(t_deque **deque_a, t_deque **deque_b);
void		perform_bonus_op(t_deque **deque_a, t_deque **deque_b, \
								int operation);
void		display_result_bonus(t_deque **deque_a, t_deque **deque_b);

/* deque_initialize_bonus.c */
t_deque		*deque_init(t_deque *node, int *buffer, int i, int size);
t_deque		*node_init(t_deque *node);
void		node_add_front(t_deque **node, t_deque *new);
void		node_add_back(t_deque **node, t_deque *new);
void		deque_head_tail(t_deque *deque);

/* deque_utils_pt1_bonus.c */
t_deque		*deque_pop_front(t_deque **deque);
t_deque		*deque_pop_back(t_deque **deque);
void		deque_push_front(t_deque **deque, t_deque *new);
void		deque_push_back(t_deque **deque, t_deque *new);

/* deque_utils_pt2_bonus.c */
int			deque_size(t_deque *deque);

/* parse_pt1_bonus.c */
int			is_valid(int ac, char *av[], int **buffer, int *size);
int			ft_strlen2(char *str);
int			is_wrongly_delimited(char *av[]);
int			is_only_delimited(char *av[]);
int			is_redundant(int ***buffer, int **size);

/* parse_pt2_bonus.c */
int			is_empty_string(int ac, char **av);
int			is_double_sign(char **av);
int			is_double(char **av, int _i, int i);
int			is_overflow(char **candidate, int ***buffer, int **size);
int			push_swap_atoi(char *str, int *overflow);

/* parse_pt3_bonus.c */
int			is_int_range(long res, char c, long sign);
int			is_non_numeric(char *av[]);
int			is_alpha(char c);

/* push_swap_split_bonus.c */
char		**ft_split_ps_bonus(char **av, char c);
size_t		ft_count_words_ps_bonus(char **av, char c);
size_t		ft_count_wordlen_ps_bonus(char *s, char c);
char		**ft_memory_manager_ps_bonus(char **res, size_t rotation);
void		ft_word_cpy_ps_bonus(char ***res, char *s, size_t word_len,
				size_t rotation);

/* memory_man_pt1_bonus.c */
void		deque_memory_mng(t_deque *deque);

/* memory_man_pt2_bonus.c */
void		free_move(t_deque *deque);
void		free_greedy(t_deque *deque);

/* operation_pt1_bonus.c */
int			sa(t_deque **deque_a);
int			sb(t_deque **deque_b);
int			ss(t_deque **deque_a, t_deque **deque_b);

/* operation_pt2_bonus.c */
int			pa(t_deque **deque_a, t_deque **deque_b);
int			pb(t_deque **deque_a, t_deque **deque_b);
int			ra(t_deque **deque_a);
int			rb(t_deque **deque_b);
int			rr(t_deque **deque_a, t_deque **deque_b);

/* operation_pt3_bonus.c */
int			rra(t_deque **deque_a);
int			rrb(t_deque **deque_b);
int			rrr(t_deque **deque_a, t_deque **deque_b);

#endif