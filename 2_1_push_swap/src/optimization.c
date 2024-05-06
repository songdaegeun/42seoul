/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimization.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasong <dasong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 20:12:08 by dasong            #+#    #+#             */
/*   Updated: 2023/05/22 20:24:49 by dasong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	sort_3_a(t_deque_info *deque_info)
{
	t_node	*head;
	int		cmp_0_1;
	int		cmp_1_2;
	int		cmp_0_2;

	head = deque_info->a.head;
	cmp_0_1 = ft_lstidx(head, 0)->content < ft_lstidx(head, 1)->content;
	cmp_1_2 = ft_lstidx(head, 1)->content < ft_lstidx(head, 2)->content;
	cmp_0_2 = ft_lstidx(head, 0)->content < ft_lstidx(head, 2)->content;
	if (cmp_0_1 && !cmp_1_2 && cmp_0_2)
	{
		command(deque_info, "sa\n");
		command(deque_info, "ra\n");
	}
	if (cmp_0_1 && !cmp_1_2 && !cmp_0_2)
		command(deque_info, "rra\n");
	if (!cmp_0_1 && cmp_1_2 && cmp_0_2)
		command(deque_info, "sa\n");
	if (!cmp_0_1 && cmp_1_2 && !cmp_0_2)
		command(deque_info, "ra\n");
	if (!cmp_0_1 && !cmp_1_2)
	{
		command(deque_info, "sa\n");
		command(deque_info, "rra\n");
	}
}

void	sort_4_a(t_deque_info *deque_info)
{
	int		min_pos;
	int		idx;

	min_pos = find_min_val(deque_info);
	idx = -1;
	while (++idx < min_pos)
		command(deque_info, "ra\n");
	command(deque_info, "pb\n");
	sort_3_a(deque_info);
	command(deque_info, "pa\n");
}

void	sort_5_a(t_deque_info *deque_info)
{
	int		min_pos;
	int		idx;

	if (sorted_length_return(&deque_info->a) == 5)
		return ;
	min_pos = find_min_val(deque_info);
	if (min_pos < 3)
	{
		idx = -1;
		while (++idx < min_pos)
			command(deque_info, "ra\n");
	}
	else
	{
		idx = -1;
		while (++idx < 5 - min_pos)
			command(deque_info, "rra\n");
	}
	command(deque_info, "pb\n");
	sort_4_a(deque_info);
	command(deque_info, "pa\n");
}

void	sort_6_a(t_deque_info *deque_info)
{
	int		min_pos;
	int		idx;

	if (sorted_length_return(&deque_info->a) == 6)
		return ;
	min_pos = find_min_val(deque_info);
	if (min_pos < 3)
	{
		idx = -1;
		while (++idx < min_pos)
			command(deque_info, "ra\n");
	}
	else
	{
		idx = -1;
		while (++idx < 6 - min_pos)
			command(deque_info, "rra\n");
	}
	command(deque_info, "pb\n");
	sort_5_a(deque_info);
	command(deque_info, "pa\n");
}

int	sorted_length_return(t_deque *deque)
{
	t_node	*cur;
	int		pre;
	int		len;

	len = deque->size;
	if (len < 2)
		return (len);
	cur = deque->head;
	pre = cur->content;
	cur = cur->next;
	len = 1;
	while (cur && pre < cur->content)
	{
		pre = cur->content;
		cur = cur->next;
		len++;
	}
	return (len);
}
