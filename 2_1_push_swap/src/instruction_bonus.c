/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdg <sdg@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 01:05:35 by sdg               #+#    #+#             */
/*   Updated: 2023/05/23 03:52:57 by sdg              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap_bonus.h"

int	push(t_deque *deque_src, t_deque *deque_dst)
{
	int	content;
	int	idx;

	if (deque_src->size == 0)
		return (0);
	ft_pop_front(deque_src, &content, &idx);
	ft_push_front(deque_dst, content, idx);
	return (1);
}

int	swap(t_deque *deque)
{
	int	content[2];
	int	idx[2];

	if (deque->size < 2)
		return (0);
	ft_pop_front(deque, &content[0], &idx[0]);
	ft_pop_front(deque, &content[1], &idx[1]);
	ft_push_front(deque, content[0], idx[0]);
	ft_push_front(deque, content[1], idx[1]);
	return (1);
}

int	rotate(t_deque *deque, int dir)
{
	int	content;
	int	idx;

	if (deque->size < 1)
		return (0);
	if (dir == 0)
	{
		ft_pop_front(deque, &content, &idx);
		ft_push_back(deque, content, idx);
	}
	else if (dir == 1)
	{
		ft_pop_back(deque, &content, &idx);
		ft_push_front(deque, content, idx);
	}
	return (1);
}

int	command(t_deque_info *deque_info, char *cmd)
{
	if (ft_strncmp(cmd, "pa\n", 4) == 0)
		return (push(&deque_info->b, &deque_info->a));
	if (ft_strncmp(cmd, "pb\n", 4) == 0)
		return (push(&deque_info->a, &deque_info->b));
	if (ft_strncmp(cmd, "sa\n", 4) == 0)
		return (swap(&deque_info->a));
	if (ft_strncmp(cmd, "sb\n", 4) == 0)
		return (swap(&deque_info->b));
	if (ft_strncmp(cmd, "ss\n", 4) == 0)
		return (swap(&deque_info->a) && swap(&deque_info->b));
	if (ft_strncmp(cmd, "ra\n", 4) == 0)
		return (rotate(&deque_info->a, 0));
	if (ft_strncmp(cmd, "rb\n", 4) == 0)
		return (rotate(&deque_info->b, 0));
	if (ft_strncmp(cmd, "rr\n", 5) == 0)
		return (rotate(&deque_info->a, 0) && rotate(&deque_info->b, 0));
	if (ft_strncmp(cmd, "rra\n", 5) == 0)
		return (rotate(&deque_info->a, 1));
	if (ft_strncmp(cmd, "rrb\n", 5) == 0)
		return (rotate(&deque_info->b, 1));
	if (ft_strncmp(cmd, "rrr\n", 5) == 0)
		return (rotate(&deque_info->a, 1) && rotate(&deque_info->b, 1));
	error_return(deque_info);
	return (-1);
}
