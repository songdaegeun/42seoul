/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   preset.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasong <dasong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 13:24:06 by dasong            #+#    #+#             */
/*   Updated: 2023/06/09 16:38:42 by dasong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	zoom_preset(t_vars *vars)
{
	while (!oob(vars->p_map_info, vars->p_manipul_info->zoom_scale))
		vars->p_manipul_info->zoom_scale += 1.0;
	vars->p_manipul_info->zoom_scale -= 1.0;
}

int	oob_check(int x, int y, int z)
{
	int	x_s;
	int	y_s;

	isometric(&x, &y, &z);
	x_s = (x - z) * cos(M_PI / 6) + SCREEN_WIDTH / 2;
	y_s = (x + z) * sin(M_PI / 6) - y + SCREEN_HEIGHT / 2;
	return (x_s < 0 || x_s >= SCREEN_WIDTH || y_s < 0 || y_s >= SCREEN_HEIGHT);
}

int	oob(t_map_info *map_info, double scale)
{
	int	w;
	int	h;
	int	d;

	w = map_info->width * scale;
	h = map_info->height * scale;
	d = map_info->depth * scale;
	return (oob_check(w / 2, h / 2, d / 2) || oob_check(w / 2, h / 2, -d / 2) \
	|| oob_check(w / 2, -h / 2, d / 2) || oob_check(w / 2, -h / 2, -d / 2) || \
	oob_check(-w / 2, h / 2, d / 2) || oob_check(-w / 2, h / 2, -d / 2) || \
	oob_check(-w / 2, -h / 2, d / 2) || oob_check(-w / 2, -h / 2, -d / 2));
}
