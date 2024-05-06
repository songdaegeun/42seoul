/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   callback.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasong <dasong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 21:27:00 by dasong            #+#    #+#             */
/*   Updated: 2023/06/09 15:52:41 by dasong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	zoom_callback(int keycode, t_vars *vars)
{
	if (keycode == KEY_ZOOM_IN)
		vars->p_manipul_info->zoom_scale += 1.0;
	if (keycode == KEY_ZOOM_OUT)
		vars->p_manipul_info->zoom_scale -= 1.0;
	if (vars->p_manipul_info->zoom_scale <= 1.0)
		vars->p_manipul_info->zoom_scale = 1.0;
	if (keycode == KEY_ZOOM_IN)
		vars->p_manipul_info->focal_l += 0.01;
	if (keycode == KEY_ZOOM_OUT)
		vars->p_manipul_info->focal_l -= 0.01;
	if (vars->p_manipul_info->focal_l <= 0.01)
		vars->p_manipul_info->focal_l = 0.01;
}

void	z_height_mani(int keycode, t_vars *vars)
{
	if (keycode == KEY_Z_HEIGHT_UP)
		vars->p_manipul_info->z_scale += 0.1;
	if (keycode == KEY_Z_HEIGHT_DOWN)
		vars->p_manipul_info->z_scale -= 0.1;
}

void	rotation(int keycode, t_vars *vars)
{
	int	angle_vel;

	angle_vel = 3;
	if (keycode == KEY_ROTATE_X_CLOCK)
		vars->p_manipul_info->theta_x -= angle_vel * (M_PI / 6) / 30;
	if (keycode == KEY_ROTATE_X_CLOCK_R)
		vars->p_manipul_info->theta_x += angle_vel * (M_PI / 6) / 30;
	if (keycode == KEY_ROTATE_Y_CLOCK)
		vars->p_manipul_info->theta_y -= angle_vel * (M_PI / 6) / 30;
	if (keycode == KEY_ROTATE_Y_CLOCK_R)
		vars->p_manipul_info->theta_y += angle_vel * (M_PI / 6) / 30;
	if (keycode == KEY_ROTATE_Z_CLOCK)
		vars->p_manipul_info->theta_z -= angle_vel * (M_PI / 6) / 30;
	if (keycode == KEY_ROTATE_Z_CLOCK_R)
		vars->p_manipul_info->theta_z += angle_vel * (M_PI / 6) / 30;
}

void	translation(int keycode, t_vars *vars)
{
	if (keycode == KEY_UP)
		vars->p_manipul_info->y_f -= 10;
	if (keycode == KEY_DOWN)
		vars->p_manipul_info->y_f += 10;
	if (keycode == KEY_LEFT)
		vars->p_manipul_info->x_f -= 10;
	if (keycode == KEY_RIGHT)
		vars->p_manipul_info->x_f += 10;
}

int	key_callback(int keycode, t_vars *vars)
{
	if (keycode == KEY_ESC)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		memory_release(vars->p_map_info);
		exit(0);
	}
	if (keycode == KEY_ZOOM_IN || keycode == KEY_ZOOM_OUT)
		zoom_callback(keycode, vars);
	if (keycode == KEY_UP || keycode == KEY_DOWN || keycode == KEY_LEFT
		|| keycode == KEY_RIGHT)
		translation(keycode, vars);
	if (keycode == KEY_ROTATE_Y_CLOCK || keycode == KEY_ROTATE_Y_CLOCK_R
		|| keycode == KEY_ROTATE_X_CLOCK || keycode == KEY_ROTATE_X_CLOCK_R
		|| keycode == KEY_ROTATE_Z_CLOCK || keycode == KEY_ROTATE_Z_CLOCK_R)
		rotation(keycode, vars);
	if (keycode == KEY_Z_HEIGHT_UP || keycode == KEY_Z_HEIGHT_DOWN)
		z_height_mani(keycode, vars);
	mlx_clear_window(vars->mlx, vars->win);
	my_clear_img(vars);
	draw_map(vars);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->p_img->img, 0, 0);
	put_ctl_msg(vars);
	return (0);
}
