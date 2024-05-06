/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphic2_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasong <dasong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 18:10:21 by dasong            #+#    #+#             */
/*   Updated: 2023/06/09 17:19:10 by dasong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

void	make_pos_s_list(t_point *pos_s_list, int *xy_s, int *idx)
{
	pos_s_list[*idx].x = xy_s[0];
	pos_s_list[(*idx)++].y = xy_s[1];
}

void	set_draw_map(t_vars *vars, t_world_coordi	\
*world_coordi, int *xyz_w, int *idx)
{
	world_coordi->pos_s_list = (t_point *)malloc(sizeof(t_point) \
	* vars->p_map_info->height * vars->p_map_info->width);
	if (!world_coordi->pos_s_list)
		exit(1);
	xyz_w[1] = 0;
	idx[0] = 0;
}

void	draw_map(t_vars *vars)
{
	t_world_coordi	world_coordi;
	int				xyz_w[3];
	int				xy_s[2];
	int				idx[2];

	set_draw_map(vars, &world_coordi, xyz_w, idx);
	while (xyz_w[1] < vars->p_map_info->height)
	{
		xyz_w[0] = 0;
		while (xyz_w[0] < vars->p_map_info->width)
		{
			set_coordi(vars, &world_coordi, xyz_w);
			scale_coordi(vars, &world_coordi);
			rotate_option(vars, &world_coordi);
			projection(vars, &world_coordi, xy_s);
			color_mapping(world_coordi.pos_s_list, xyz_w[2], idx[0]);
			make_pos_s_list(world_coordi.pos_s_list, xy_s, &idx[0]);
			xyz_w[0]++;
		}
		xyz_w[1]++;
	}
	idx[1] = -1;
	while (++idx[1] < idx[0])
		draw_wire(vars, idx[1], world_coordi.pos_s_list);
	free(world_coordi.pos_s_list);
}

void	draw_wire(t_vars *vars, int now_idx, t_point *pos_s_list)
{
	int		d_idx[6];
	int		nxy[2];
	t_point	pos_s;
	t_point	n_pos_s;

	d_idx[4] = now_idx;
	set_draw_wire(d_idx, vars->p_map_info, &pos_s, pos_s_list);
	d_idx[5] = -1;
	while (++(d_idx[5]) < 4)
	{
		nxy[0] = pos_s_list[now_idx + d_idx[d_idx[5]]].x;
		nxy[1] = pos_s_list[now_idx + d_idx[d_idx[5]]].y;
		if (now_idx + d_idx[d_idx[5]] < 0 || now_idx + d_idx[d_idx[5]] \
		>= vars->p_map_info->height * vars->p_map_info->width)
			continue ;
		if (not_adjacent(vars, d_idx))
			continue ;
		n_pos_s.x = nxy[0];
		n_pos_s.y = nxy[1];
		n_pos_s.color = pos_s_list[now_idx + d_idx[d_idx[5]]].color;
		draw_line(vars->p_img, &pos_s, &n_pos_s);
	}
}

int	oob_xy(int x, int y)
{
	return (x < 0 || x >= SCREEN_WIDTH || y < 0 || y >= SCREEN_HEIGHT);
}
