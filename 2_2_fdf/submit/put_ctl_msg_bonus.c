/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_ctl_msg_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasong <dasong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 16:39:55 by dasong            #+#    #+#             */
/*   Updated: 2023/06/09 17:19:51 by dasong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

int	set_put_ctl_msg(t_vars *vars, char *(*str)[7])
{
	(*str)[0] = ft_sprintf(":%d x %d x %d", vars->p_map_info->width, \
	vars->p_map_info->height, vars->p_map_info->depth);
	(*str)[1] = ft_sprintf("theta-x: %d degree", \
	(int)(vars->p_manipul_info->theta_x * 180 / M_PI));
	(*str)[2] = ft_sprintf("theta-y: %d degree", \
	(int)(vars->p_manipul_info->theta_y * 180 / M_PI));
	(*str)[3] = ft_sprintf("theta-z: %d degree", \
	(int)(vars->p_manipul_info->theta_z * 180 / M_PI));
	(*str)[4] = ft_sprintf("height scale: %d%%", \
	(int)(vars->p_manipul_info->z_scale * 100));
	(*str)[5] = ft_sprintf("zoom scale: %d%%", \
	(int)(vars->p_manipul_info->zoom_scale * 100));
	(*str)[6] = ft_sprintf("focus: {%d,%d}", vars->p_manipul_info->x_f, \
	vars->p_manipul_info->y_f);
	if (!(*str)[0] || !(*str)[1] || !(*str)[2] || !(*str)[3] || \
	!(*str)[4] || !(*str)[5] || !(*str)[6])
		return (0);
	return (1);
}

void	ctl_msg_script1(t_vars *vars, char **str)
{
	mlx_string_put(vars->mlx, vars->win, SCREEN_WIDTH + \
	PANEL_X_MARGIN, PANEL_LINE_NUM, 0xFFFFFF, "[control panel]");
	mlx_string_put(vars->mlx, vars->win, SCREEN_WIDTH + \
	PANEL_X_MARGIN, 2 * PANEL_LINE_NUM, 0xFFFFFF, "<map info>");
	mlx_string_put(vars->mlx, vars->win, SCREEN_WIDTH + \
	PANEL_X_MARGIN, 3 * PANEL_LINE_NUM, 0xFFFFFF, str[0]);
	mlx_string_put(vars->mlx, vars->win, SCREEN_WIDTH + \
	PANEL_X_MARGIN, 4 * PANEL_LINE_NUM, 0xFFFFFF, "control");
	mlx_string_put(vars->mlx, vars->win, SCREEN_WIDTH + \
	PANEL_X_MARGIN, 5 * PANEL_LINE_NUM, 0xFFFFFF, "x-rotate(CCW, CW): z , x");
	mlx_string_put(vars->mlx, vars->win, SCREEN_WIDTH + \
	PANEL_X_MARGIN, 6 * PANEL_LINE_NUM, 0xFFFFFF, "y-rotate(CCW, CW): a , s");
	mlx_string_put(vars->mlx, vars->win, SCREEN_WIDTH + \
	PANEL_X_MARGIN, 7 * PANEL_LINE_NUM, 0xFFFFFF, "z-rotate(CCW, CW): q , w");
	mlx_string_put(vars->mlx, vars->win, SCREEN_WIDTH + \
	PANEL_X_MARGIN, 8 * PANEL_LINE_NUM, 0xFFFFFF, "height up/down: e , d");
	mlx_string_put(vars->mlx, vars->win, SCREEN_WIDTH + \
	PANEL_X_MARGIN, 9 * PANEL_LINE_NUM, 0xFFFFFF, "zoom in/out: + , -");
	mlx_string_put(vars->mlx, vars->win, SCREEN_WIDTH + \
	PANEL_X_MARGIN, 10 * PANEL_LINE_NUM, 0xFFFFFF, "transtation: arrow");
	mlx_string_put(vars->mlx, vars->win, SCREEN_WIDTH + \
	PANEL_X_MARGIN, 12 * PANEL_LINE_NUM, 0xFFFFFF, "<status>");
}

void	ctl_msg_script2(t_vars *vars, char **str)
{
	mlx_string_put(vars->mlx, vars->win, SCREEN_WIDTH + \
	PANEL_X_MARGIN, 13 * PANEL_LINE_NUM, 0xFFFFFF, str[1]);
	mlx_string_put(vars->mlx, vars->win, SCREEN_WIDTH + \
	PANEL_X_MARGIN, 14 * PANEL_LINE_NUM, 0xFFFFFF, str[2]);
	mlx_string_put(vars->mlx, vars->win, SCREEN_WIDTH + \
	PANEL_X_MARGIN, 15 * PANEL_LINE_NUM, 0xFFFFFF, str[3]);
	mlx_string_put(vars->mlx, vars->win, SCREEN_WIDTH + \
	PANEL_X_MARGIN, 17 * PANEL_LINE_NUM, 0xFFFFFF, str[4]);
	mlx_string_put(vars->mlx, vars->win, SCREEN_WIDTH + \
	PANEL_X_MARGIN, 18 * PANEL_LINE_NUM, 0xFFFFFF, str[5]);
	mlx_string_put(vars->mlx, vars->win, SCREEN_WIDTH + \
	PANEL_X_MARGIN, 16 * PANEL_LINE_NUM, 0xFFFFFF, str[6]);
}

void	put_ctl_msg(t_vars *vars)
{
	char	*str[7];

	if (!set_put_ctl_msg(vars, &str))
		exit(1);
	ctl_msg_script1(vars, str);
	ctl_msg_script2(vars, str);
	free_set_put_ctl_msg(str);
}

void	free_set_put_ctl_msg(char **str)
{
	int	i;

	i = -1;
	while (++i < 7)
		free(str[i]);
}
