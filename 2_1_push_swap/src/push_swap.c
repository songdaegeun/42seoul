/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdg <sdg@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 00:58:16 by sdg               #+#    #+#             */
/*   Updated: 2023/05/23 03:29:25 by sdg              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	main(int argc, char **argv)
{
	t_deque_info	deque_info;

	if (argc <= 1)
		return (0);
	init(&deque_info);
	parse(&deque_info, argc - 1, argv + 1);
	indexing(deque_info.a, deque_info.a.size);
	if (deque_info.a.size <= 6)
		hard_sort(&deque_info);
	else
	{
		pivot_split(&deque_info, 0, 0, deque_info.a.size);
		pre_greedy(&deque_info);
		greedy(&deque_info, deque_info.b.size);
		sorted_move(&deque_info);
	}
	free_deque(&deque_info.a);
	return (0);
}

void	pivot_split(t_deque_info *d_i, int ra_cnt, int rb_cnt, int a_size)
{
	int	top;
	int	idx;

	idx = -1;
	while (++idx < a_size)
	{
		top = d_i->a.head->content;
		if (top >= ft_max(ft_lstidx(d_i->a.head, a_size / 3)->content, \
		ft_lstidx(d_i->a.head, 2 * (a_size / 3))->content))
		{
			command(d_i, "ra\n");
			ra_cnt++;
		}
		else
		{
			command(d_i, "pb\n");
			if (top >= ft_min(ft_lstidx(d_i->a.head, a_size / 3)->content, \
			ft_lstidx(d_i->a.head, 2 * (a_size / 3))->content))
			{
				command(d_i, "rb\n");
				rb_cnt++;
			}
		}
	}
	pivot_split_rewind(d_i, ra_cnt, rb_cnt);
}

void	pivot_split_rewind(t_deque_info *deque_info, int ra_cnt, int rb_cnt)
{
	int	idx;

	idx = -1;
	while (++idx < ft_min(ra_cnt, rb_cnt))
		command(deque_info, "rrr\n");
	idx = -1;
	while (++idx < ft_abs(ra_cnt, rb_cnt))
	{
		if (ra_cnt > rb_cnt)
			command(deque_info, "rra\n");
		else
			command(deque_info, "rrb\n");
	}
}

void	indexing(t_deque	deque, int size)
{
	t_node	*cur;
	int		min_idx;
	int		min_val;
	int		idx_i;
	int		idx_j;

	cur = deque.head;
	idx_i = -1;
	while (++idx_i < size)
	{
		min_idx = idx_i;
		min_val = 2147483647;
		idx_j = -1;
		while (++idx_j < size)
		{
			if (ft_lstidx(cur, idx_j)->idx != -1)
				continue ;
			if (min_val >= ft_lstidx(cur, idx_j)->content)
			{
				min_val = ft_lstidx(cur, idx_j)->content;
				min_idx = idx_j;
			}
		}
		ft_lstidx(cur, min_idx)->idx = idx_i;
	}
}
