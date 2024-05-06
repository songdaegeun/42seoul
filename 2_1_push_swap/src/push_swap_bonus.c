/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasong <dasong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 00:58:16 by sdg               #+#    #+#             */
/*   Updated: 2023/05/24 12:58:23 by dasong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap_bonus.h"

int	main(int argc, char **argv)
{
	t_deque_info	deque_info;

	if (argc <= 1)
		return (0);
	init(&deque_info);
	parse(&deque_info, argc - 1, argv + 1);
	indexing(deque_info.a, deque_info.a.size);
	checker(&deque_info, deque_info.a.size);
	free_deque(&deque_info.a);
	return (0);
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

void	checker(t_deque_info *d_i, int a_size)
{
	char	*cmd;

	cmd = get_next_line(0);
	while (cmd)
	{
		command(d_i, cmd);
		free(cmd);
		cmd = get_next_line(0);
	}
	if (d_i->b.size == 0 && chk_sorted_and_repeat(d_i, &d_i->a, a_size))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
}
