/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   greedy_cost.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdg <sdg@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 19:50:36 by dasong            #+#    #+#             */
/*   Updated: 2023/05/23 01:30:34 by sdg              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	cost_calcu(t_deque_info *deque_info, int pos_a, int pos_b, int *case_n)
{
	int	a_size;
	int	b_size;

	a_size = deque_info->a.size;
	b_size = deque_info->b.size;
	if ((pos_a <= a_size / 2) && (pos_b <= b_size / 2))
		*case_n = 1;
	else if ((pos_a <= a_size / 2) && !(pos_b <= b_size / 2))
		*case_n = 2;
	else if (!(pos_a <= a_size / 2) && (pos_b <= b_size / 2))
		*case_n = 3;
	else
		*case_n = 4;
	return ((*case_n == 1) * (ft_min(pos_a, pos_b) + ft_abs(pos_a, pos_b) + 1) \
	+ (*case_n == 2) * (pos_a + b_size - pos_b + 1) + (*case_n == 3) * (a_size \
	- pos_a + pos_b + 1) + (*case_n == 4) * (ft_min(a_size - pos_a, b_size - \
	pos_b) + ft_abs(a_size - pos_a, b_size - pos_b) + 1));
}

int	search_pos(t_deque_info *deque_info, int b_idx)
{
	t_deque	deque;
	int		size;
	int		pos;
	int		border;

	border = sorted_length_return(&deque_info->a);
	deque = deque_info->a;
	size = deque.size;
	if (deque_info->a.head->idx < deque_info->a.tail->idx)
	{
		pos = -1;
		while (++pos < size)
		{
			if (ft_lstidx(deque.head, pos)->idx > b_idx)
				break ;
		}
	}
	else
		search_pos_tri_2(deque_info, &pos, b_idx, border);
	return (pos);
}

void	search_pos_tri_2(t_deque_info *d_i, int *p_pos, int b_idx, int border)
{
	t_deque	deque;
	int		size;
	int		pos;

	deque = d_i->a;
	size = deque.size;
	if (b_idx < d_i->a.tail->idx)
	{
		pos = border - 1;
		while (++pos < size)
		{
			if (ft_lstidx(deque.head, pos)->idx > b_idx)
				break ;
		}
	}
	else
	{
		pos = -1;
		while (++pos < border)
		{
			if (ft_lstidx(deque.head, pos)->idx > b_idx)
				break ;
		}
	}
	*p_pos = pos;
}

void	hard_sort(t_deque_info *deque_info)
{
	if (deque_info->a.size <= 2)
	{
		if (deque_info->a.head->content > deque_info->a.tail->content)
			command(deque_info, "sa\n");
	}
	else if (deque_info->a.size == 3)
		sort_3_a(deque_info);
	else if (deque_info->a.size == 4)
		sort_4_a(deque_info);
	else if (deque_info->a.size == 5)
		sort_5_a(deque_info);
	else
		sort_6_a(deque_info);
}

int	find_min_val(t_deque_info *deque_info)
{
	t_node	*cur;
	int		min;
	int		pos;
	int		min_pos;

	cur = deque_info->a.head;
	min = 2147483647;
	pos = 0;
	while (cur)
	{
		if (min > cur->content)
		{
			min = cur->content;
			min_pos = pos;
		}
		pos++;
		cur = cur->next;
	}
	return (min_pos);
}
