/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasong <dasong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 21:42:55 by dasong            #+#    #+#             */
/*   Updated: 2023/06/09 17:19:32 by dasong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

void	scale_coordi(t_vars *vars, t_world_coordi *world_coordi)
{
	double	scale;

	scale = vars->p_manipul_info->zoom_scale;
	world_coordi->w = world_coordi->w * scale;
	world_coordi->h = world_coordi->h * scale;
	world_coordi->d = world_coordi->d * scale;
	world_coordi->x = world_coordi->x * scale;
	world_coordi->y = world_coordi->y * scale;
	world_coordi->z = world_coordi->z * scale;
	if (world_coordi->z > 0)
		world_coordi->z *= vars->p_manipul_info->z_scale;
}

void	set_coordi(t_vars *vars, t_world_coordi *world_coordi, int *xyz_w)
{
	xyz_w[2] = ((int *)ft_lstidx(vars->p_map_info->map, \
	vars->p_map_info->height - 1 - xyz_w[1])->content)[xyz_w[0]];
	world_coordi->x = xyz_w[0];
	world_coordi->y = xyz_w[1];
	world_coordi->z = xyz_w[2];
	world_coordi->w = vars->p_map_info->width;
	world_coordi->h = vars->p_map_info->height;
	world_coordi->d = vars->p_map_info->depth;
	world_coordi->x -= world_coordi->w / 2;
	world_coordi->y -= world_coordi->h / 2;
	world_coordi->z -= world_coordi->d / 2;
}

void	my_clear_img(t_vars *vars)
{
	int	x;
	int	y;

	y = 0;
	while (y < SCREEN_HEIGHT)
	{
		x = 0;
		while (x < SCREEN_WIDTH)
		{
			my_mlx_pixel_put(vars->p_img, x, y, 0);
			x++;
		}
		y++;
	}
}

void	memory_release(t_map_info *map_info)
{
	t_list	*cur;

	cur = ft_lstidx(map_info->map, 0);
	while (cur)
	{
		free(cur->content);
		cur = cur->next;
	}
}

int	destroy_callback(t_vars *vars)
{
	memory_release(vars->p_map_info);
	exit(0);
}
