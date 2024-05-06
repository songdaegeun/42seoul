/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   greedy_push.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasong <dasong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 22:13:18 by dasong            #+#    #+#             */
/*   Updated: 2023/05/22 22:22:27 by dasong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	greedy_push(t_deque_info *d_i, int pos_a, int pos_b, int case_n)
{
	int	a_size;
	int	b_size;

	a_size = d_i->a.size;
	b_size = d_i->b.size;
	if (case_n == 1)
		greedy_push_case_1(d_i, pos_a, pos_b);
	else if (case_n == 2)
		greedy_push_case_2(d_i, pos_a, b_size - pos_b);
	else if (case_n == 3)
		greedy_push_case_3(d_i, a_size - pos_a, pos_b);
	else if (case_n == 4)
		greedy_push_case_4(d_i, a_size - pos_a, b_size - pos_b);
	command(d_i, "pa\n");
}

void	greedy_push_case_1(t_deque_info *deque_info, int pos_a, int pos_b)
{
	int	idx;

	idx = -1;
	while (++idx < ft_min(pos_a, pos_b))
		command(deque_info, "rr\n");
	idx = -1;
	while (++idx < ft_abs(pos_a, pos_b))
	{
		if (pos_a < pos_b)
			command(deque_info, "rb\n");
		else
			command(deque_info, "ra\n");
	}
}

void	greedy_push_case_2(t_deque_info *d_i, int pos_a, int rrb_size)
{
	int	idx;

	idx = -1;
	while (++idx < pos_a)
		command(d_i, "ra\n");
	idx = -1;
	while (++idx < rrb_size)
		command(d_i, "rrb\n");
}

void	greedy_push_case_3(t_deque_info *d_i, int rra_size, int pos_b)
{
	int	idx;

	idx = -1;
	while (++idx < rra_size)
		command(d_i, "rra\n");
	idx = -1;
	while (++idx < pos_b)
		command(d_i, "rb\n");
}

void	greedy_push_case_4(t_deque_info *d_i, int rra_size, int rrb_size)
{
	int	idx;

	idx = -1;
	while (++idx < ft_min(rra_size, rrb_size))
		command(d_i, "rrr\n");
	idx = -1;
	while (++idx < ft_abs(rra_size, rrb_size))
	{
		if (rra_size < rrb_size)
			command(d_i, "rrb\n");
		else
			command(d_i, "rra\n");
	}
}
