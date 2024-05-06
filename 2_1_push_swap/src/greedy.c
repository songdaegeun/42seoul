/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   greedy.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdg <sdg@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 19:50:36 by dasong            #+#    #+#             */
/*   Updated: 2023/05/23 01:04:18 by sdg              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	greedy(t_deque_info *d_i, int size)
{	
	int	idx;
	int	cost_case[2];
	int	pos_ab[2];
	int	min_ab_ca_co[4];

	idx = -1;
	while (++idx < size)
	{
		min_ab_ca_co[3] = d_i->a.size + d_i->b.size;
		pos_ab[1] = 0;
		while (pos_ab[1] < d_i->b.size)
		{
			pos_ab[0] = search_pos(d_i, ft_lstidx(d_i->b.head, pos_ab[1])->idx);
			cost_case[0] = cost_calcu(d_i, pos_ab[0], pos_ab[1], &cost_case[1]);
			if (min_ab_ca_co[3] > cost_case[0])
			{
				min_ab_ca_co[3] = cost_case[0];
				min_ab_ca_co[0] = pos_ab[0];
				min_ab_ca_co[1] = pos_ab[1];
				min_ab_ca_co[2] = cost_case[1];
			}
			pos_ab[1]++;
		}
		greedy_push(d_i, min_ab_ca_co[0], min_ab_ca_co[1], min_ab_ca_co[2]);
	}
}

void	pre_greedy(t_deque_info *deque_info)
{
	if (deque_info->a.size <= 5)
		hard_sort(deque_info);
	else
	{
		while (deque_info->a.size > 5)
			command(deque_info, "pb\n");
		sort_5_a(deque_info);
	}
}

void	sorted_move(t_deque_info *deque_info)
{
	int	sorted_len;
	int	idx;

	sorted_len = sorted_length_return(&deque_info->a);
	if (sorted_len != deque_info->a.size)
	{
		idx = -1;
		while (++idx < sorted_len)
			command(deque_info, "ra\n");
	}
}
