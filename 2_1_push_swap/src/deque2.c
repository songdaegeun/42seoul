/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deque2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdg <sdg@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 20:11:22 by dasong            #+#    #+#             */
/*   Updated: 2023/05/23 03:29:34 by sdg              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	init(t_deque_info *deque_info)
{
	deque_info->a.head = 0;
	deque_info->a.tail = 0;
	deque_info->a.size = 0;
	deque_info->b.head = 0;
	deque_info->b.tail = 0;
	deque_info->b.size = 0;
}

void	init_deque(t_deque *deque)
{
	deque->head = 0;
	deque->size = 0;
	deque->tail = 0;
}

t_node	*ft_lstidx(t_node *lst, int idx)
{
	if (lst)
	{
		while (lst->next && idx--)
		{
			lst = lst->next;
		}
	}
	return (lst);
}

void	free_deque(t_deque *deque)
{
	t_node	*cur;
	t_node	*tmp;

	cur = deque->head;
	while (cur)
	{
		tmp = cur;
		cur = cur->next;
		free(tmp);
	}
}

void	memory_free(t_deque_info *deque_info)
{
	if (deque_info->a.head)
		free_deque(&deque_info->a);
	if (deque_info->b.head)
		free_deque(&deque_info->b);
	exit(0);
}
