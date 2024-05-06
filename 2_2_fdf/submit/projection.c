/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasong <dasong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 12:29:19 by dasong            #+#    #+#             */
/*   Updated: 2023/06/09 16:36:25 by dasong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	projection(t_vars *vars, t_world_coordi *world_coordi, int *xy_s)
{
	if (ISOMETRIC)
	{
		isometric(&world_coordi->x, &world_coordi->y, &world_coordi->z);
		xy_s[0] = (world_coordi->x - world_coordi->z) * cos(M_PI / 6) + \
		vars->p_manipul_info->x_f + SCREEN_WIDTH / 2;
		xy_s[1] = (world_coordi->x + world_coordi->z) * sin(M_PI / 6) - \
		world_coordi->y + vars->p_manipul_info->y_f + SCREEN_HEIGHT / 2;
	}
	else if (PERSPECTIVE)
	{
		perspective(vars, &world_coordi->x, &world_coordi->y, &world_coordi->z);
		xy_s[0] = world_coordi->x + vars->p_manipul_info->x_f + \
		SCREEN_WIDTH / 2;
		xy_s[1] = world_coordi->y + vars->p_manipul_info->y_f + \
		SCREEN_HEIGHT / 2;
	}
}

void	isometric(int *x, int *y, int *z)
{
	rotate_x(y, z, -M_PI / 4);
	rotate_y(x, z, -asin(tan(M_PI / 6)));
	rotate_z(x, y, -M_PI / 6);
	rotate_x(y, z, -asin(tan(M_PI / 6)));
	rotate_y(x, z, M_PI / 4);
}

void	perspective(t_vars *vars, int *x, int *y, int *z)
{
	double	a;
	double	d;
	int		z_plane;

	d = vars->p_manipul_info->focal_l;
	a = SCREEN_WIDTH / SCREEN_HEIGHT;
	z_plane = 50;
	if (*z < z_plane)
		*z = z_plane;
	*x = (int)((1 / a) * (d / -(*z)) * (*x) * (SCREEN_WIDTH / 2));
	*y = (int)((d / -(*z)) * (*y) * (SCREEN_HEIGHT / 2));
}
