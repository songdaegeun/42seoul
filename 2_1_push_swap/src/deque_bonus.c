/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deque_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdg <sdg@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 20:11:57 by dasong            #+#    #+#             */
/*   Updated: 2023/05/23 04:12:47 by sdg              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap_bonus.h"

int	ft_push_front(t_deque *deque, int content, int idx)
{
	t_node	*new_node;

	new_node = (t_node *)malloc(sizeof(t_node) * 1);
	if (!new_node)
		return (0);
	new_node->content = content;
	new_node->idx = idx;
	new_node->next = deque->head;
	new_node->pre = 0;
	if (!deque->head)
		deque->tail = new_node;
	else
		deque->head->pre = new_node;
	deque->head = new_node;
	deque->size++;
	return (1);
}

void	ft_pop_front(t_deque *deque, int *p_content, int *p_idx)
{
	t_node	*tmp;
	int		content;
	int		idx;

	if (!deque->head)
		return ;
	else
	{
		tmp = deque->head;
		content = tmp->content;
		idx = tmp->idx;
		deque->head = deque->head->next;
		free(tmp);
	}
	if (!deque->head)
		deque->tail = 0;
	else
		deque->head->pre = 0;
	deque->size--;
	*p_content = content;
	*p_idx = idx;
}

int	ft_push_back(t_deque *deque, int content, int idx)
{
	t_node	*new_node;

	new_node = (t_node *)malloc(sizeof(t_node) * 1);
	if (!new_node)
		return (0);
	new_node->content = content;
	new_node->idx = idx;
	new_node->pre = deque->tail;
	new_node->next = 0;
	if (!deque->tail)
		deque->head = new_node;
	else
		deque->tail->next = new_node;
	deque->tail = new_node;
	deque->size++;
	return (1);
}

void	ft_pop_back(t_deque *deque, int *p_content, int *p_idx)
{
	t_node	*tmp;
	int		content;
	int		idx;

	if (!deque->tail)
		return ;
	else
	{
		tmp = deque->tail;
		content = tmp->content;
		idx = tmp->idx;
		deque->tail = deque->tail->pre;
		free(tmp);
	}
	if (!deque->tail)
		deque->head = 0;
	else
		deque->tail->next = 0;
	deque->size--;
	*p_content = content;
	*p_idx = idx;
}

t_node	*ft_lstlast(t_node *lst)
{
	if (lst)
	{
		while (lst->next)
			lst = lst->next;
	}
	return (lst);
}
