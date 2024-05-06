/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdg <sdg@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 00:06:56 by sdg               #+#    #+#             */
/*   Updated: 2023/05/23 03:53:00 by sdg              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap_bonus.h"

int	parse(t_deque_info *deque_info, int argc, char **argv)
{
	int		idx;
	t_deque	number;
	t_node	*node_i;

	deque_info->a.head = 0;
	idx = -1;
	while (++idx < argc)
	{
		init_deque(&number);
		if (!ft_atoi(deque_info, argv[idx], &number))
			memory_free(deque_info);
		node_i = number.head;
		while (node_i)
		{
			if (!ft_push_back(&deque_info->a, node_i->content, -1))
				memory_free(deque_info);
			node_i = node_i->next;
		}
		free_deque(&number);
	}
	if (chk_sorted_and_repeat(deque_info, &deque_info->a, deque_info->a.size))
		memory_free(deque_info);
	return (1);
}

int	can_in_atoi(const char *nptr)
{
	int	i;

	i = 0;
	while (nptr[i] == 32 || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	if (nptr[i] == '+' || nptr[i] == '-')
		i++;
	if (nptr[i] >= '0' && nptr[i] <= '9')
		return (1);
	return (0);
}

int	ft_atoi(t_deque_info *deque_info, const char *nptr, t_deque *number)
{
	int			i;
	int			sign;
	long long	res;

	i = 0;
	if (!can_in_atoi(nptr + i))
		error_return(deque_info);
	while (can_in_atoi(nptr + i))
	{
		res = 0;
		sign = 1;
		while (nptr[i] == 32 || (nptr[i] >= 9 && nptr[i] <= 13))
			i++;
		if (nptr[i] == '+' || nptr[i] == '-')
			sign = 1 + -2 * (nptr[i++] == '-');
		while (nptr[i] >= '0' && nptr[i] <= '9')
			res = res * 10 + nptr[i++] - '0';
		res = res * sign;
		if (res > 2147483647 || res < -2147483648)
			error_return(deque_info);
		if (!ft_push_back(number, (int)res, -1))
			return (0);
	}
	return (1);
}

int	chk_sorted_and_repeat(t_deque_info *deque_info, t_deque *deque, int size)
{
	int		chk_sorted;
	int		idx_i;
	int		idx_j;
	int		min_idx;
	int		min_val;

	chk_sorted = 1;
	idx_i = -1;
	while (++idx_i < size - 1)
	{
		min_idx = idx_i;
		min_val = ft_lstidx(deque->head, min_idx)->content;
		idx_j = idx_i + 1;
		while (idx_j < size)
		{
			if (min_val > ft_lstidx(deque->head, idx_j)->content)
				chk_sorted = 0;
			else if (min_val == ft_lstidx(deque->head, idx_j)->content)
				error_return(deque_info);
			idx_j++;
		}
	}
	return (chk_sorted);
}

void	error_return(t_deque_info *deque_info)
{
	free_deque(&deque_info->a);
	free_deque(&deque_info->b);
	write(2, "Error\n", 6);
	exit(1);
}
