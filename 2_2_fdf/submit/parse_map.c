/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasong <dasong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 21:07:45 by dasong            #+#    #+#             */
/*   Updated: 2023/06/09 21:10:22 by dasong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	free_res(char **res)
{
	int	i;

	i = -1;
	while (res[++i])
	{
		free(res[i]);
	}
}

void	allocate_map(char **res, t_map_info *map_info, int *max_depth)
{
	int		*map_row;
	int		idx;

	map_info->width = parse_strarr(res);
	map_row = (int *)malloc(sizeof(int) * map_info->width);
	if (!map_row)
		return ;
	idx = -1;
	while (++idx < map_info->width)
	{
		map_row[idx] = ft_atoi(res[idx]);
		if (*max_depth < map_row[idx])
			*max_depth = map_row[idx];
	}
	free_res(res);
	free(res);
	ft_lstadd_back(&map_info->map, ft_lstnew(map_row));
	map_info->depth = *max_depth;
}

int	parse_map(t_map_info *map_info, char *map_addr)
{
	int		fd;
	char	*str;
	char	**res;
	int		cnt;
	int		max_depth;

	max_depth = 0;
	cnt = 0;
	fd = open(map_addr, O_RDONLY);
	if (fd == -1)
		exit(0);
	while (1)
	{
		str = get_next_line(fd);
		if (!str)
			break ;
		res = ft_split(str, ' ');
		if (!res)
			exit(0);
		free(str);
		allocate_map(res, map_info, &max_depth);
		cnt++;
	}
	map_info->height = cnt;
	return (1);
}

int	parse_strarr(char **str_arr)
{
	int	i;

	i = 0;
	while (str_arr[i])
	{
		if (str_arr[i][0] == '\n')
			break ;
		i++;
	}
	return (i);
}

t_list	*ft_lstidx(t_list *lst, int idx)
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
