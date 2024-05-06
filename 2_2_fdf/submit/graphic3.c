/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphic3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasong <dasong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 18:10:21 by dasong            #+#    #+#             */
/*   Updated: 2023/06/09 14:53:54 by dasong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	not_adjacent(t_vars *vars, int *d_idx)
{
	int	condition1;
	int	condition2;

	condition1 = (d_idx[4] / vars->p_map_info->width != \
	(d_idx[4] + d_idx[d_idx[5]]) / vars->p_map_info->width);
	condition2 = (d_idx[4] % vars->p_map_info->width != \
	(d_idx[4] + d_idx[d_idx[5]]) % vars->p_map_info->width);
	return (condition1 && condition2);
}

void	set_draw_wire(int *d_idx, t_map_info *map_i, \
t_point *pos_s, t_point *pos_s_list)
{
	d_idx[0] = 1;
	d_idx[1] = -1;
	d_idx[2] = 1 * map_i->width;
	d_idx[3] = -1 * map_i->width;
	pos_s->x = pos_s_list[d_idx[4]].x;
	pos_s->y = pos_s_list[d_idx[4]].y;
	pos_s->color = pos_s_list[d_idx[4]].color;
}

void	rotate_z(int *x, int *y, double theta)
{
	int	prev_x;
	int	prev_y;

	prev_x = *x;
	prev_y = *y;
	*x = prev_x * cos(theta) - prev_y * sin(theta);
	*y = prev_x * sin(theta) + prev_y * cos(theta);
}

void	rotate_x(int *y, int *z, double theta)
{
	int	prev_z;
	int	prev_y;

	prev_z = *z;
	prev_y = *y;
	*z = prev_z * cos(theta) + prev_y * sin(theta);
	*y = -prev_z * sin(theta) + prev_y * cos(theta);
}

void	rotate_y(int *x, int *z, double theta)
{
	int	prev_z;
	int	prev_x;

	prev_z = *z;
	prev_x = *x;
	*z = prev_z * cos(theta) - prev_x * sin(theta);
	*x = prev_z * sin(theta) + prev_x * cos(theta);
}
