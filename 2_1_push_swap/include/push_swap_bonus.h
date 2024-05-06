/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdg <sdg@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 00:55:27 by sdg               #+#    #+#             */
/*   Updated: 2023/05/23 04:03:37 by sdg              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H
# include <stdlib.h>
# include <unistd.h>
# include "get_next_line_bonus.h"

typedef struct s_node
{
	int				content;
	int				idx;
	struct s_node	*next;
	struct s_node	*pre;
}	t_node;

typedef struct s_deque
{
	int				size;
	t_node			*head;
	t_node			*tail;
}	t_deque;

typedef struct s_deque_info
{
	t_deque			a;
	t_deque			b;
}	t_deque_info;

void	indexing(t_deque	deque, int size);
void	checker(t_deque_info *d_i, int a_size);

int		ft_push_front(t_deque *deque, int content, int idx);
void	ft_pop_front(t_deque *deque, int *p_content, int *p_idx);
int		ft_push_back(t_deque *deque, int content, int idx);
void	ft_pop_back(t_deque *deque, int *p_content, int *p_idx);
void	init(t_deque_info *deque_info);
void	init_deque(t_deque *deque);
t_node	*ft_lstlast(t_node *lst);
t_node	*ft_lstidx(t_node *lst, int idx);
void	free_deque(t_deque *deque);
void	memory_free(t_deque_info *deque_info);
int		cost_calcu(t_deque_info *deque_info, int pos_a, int pos_b, int *case_n);
int		search_pos(t_deque_info *deque_info, int b_idx);
void	search_pos_tri_2(t_deque_info *d_i, int *p_pos, int b_idx, int border);
void	hard_sort(t_deque_info *deque_info);
int		find_min_val(t_deque_info *deque_info);
void	greedy_push(t_deque_info *d_i, int pos_a, int pos_b, int case_n);
void	greedy_push_case_1(t_deque_info *deque_info, int pos_a, int pos_b);
void	greedy_push_case_2(t_deque_info *d_i, int pos_a, int rrb_size);
void	greedy_push_case_3(t_deque_info *d_i, int rra_size, int pos_b);
void	greedy_push_case_4(t_deque_info *d_i, int rra_size, int rrb_size);
void	greedy(t_deque_info *d_i, int size);
void	pre_greedy(t_deque_info *deque_info);
void	sorted_move(t_deque_info *deque_info);
int		push(t_deque *deque_src, t_deque *deque_dst);
int		swap(t_deque *deque);
int		rotate(t_deque *deque, int dir);
int		command(t_deque_info *deque_info, char *cmd);
void	sort_3_a(t_deque_info *deque_info);
void	sort_4_a(t_deque_info *deque_info);
void	sort_5_a(t_deque_info *deque_info);
void	sort_6_a(t_deque_info *deque_info);
int		sorted_length_return(t_deque *deque);
int		parse(t_deque_info *deque_info, int argc, char **argv);
int		can_in_atoi(const char *nptr);
int		ft_atoi(t_deque_info *deque_info, const char *nptr, t_deque *number);
int		chk_sorted_and_repeat(t_deque_info *deque_info, \
t_deque *deque, int size);
void	error_return(t_deque_info *deque_info);
void	ft_putstr_fd(char *s, int fd);
int		ft_strlen(const char *s);
int		ft_min(int a, int b);
int		ft_max(int a, int b);
int		ft_abs(int a, int b);
int		ft_strncmp(const char *s1, const char *s2, int n);

#endif