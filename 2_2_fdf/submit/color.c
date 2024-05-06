/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasong <dasong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 23:45:25 by sdg               #+#    #+#             */
/*   Updated: 2023/06/09 14:22:55 by dasong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

double	get_ratio(int s, int e, int cur)
{
	double	ratio;

	if (s == e)
		return (1.0);
	ratio = (double)(cur - s) / (e - s);
	return (ratio);
}

int	get_dist(int s, int e, double d1)
{
	return ((int)(d1 * e + (1 - d1) * s));
}

int	get_color(int x, int y, t_point *s, t_point *e)
{
	double	ratio;
	int		red;
	int		green;
	int		blue;

	if (!is_gradi_over_1(s, e))
		ratio = get_ratio(s->x, e->x, x);
	else
		ratio = get_ratio(s->y, e->y, y);
	red = get_dist((s->color >> 16) & 0xFF, (e->color >> 16) & 0xFF, ratio);
	green = get_dist((s->color >> 8) & 0xFF, (e->color >> 8) & 0xFF, ratio);
	blue = get_dist(s->color & 0xFF, e->color & 0xFF, ratio);
	return (create_trgb(0, red, green, blue));
}

void	color_mapping(t_point *pos_s_list, int z_w, int idx)
{
	if (z_w == 0)
		pos_s_list[idx].color = create_trgb(0, 255, 153, 153);
	else
	{
		if (ft_abs(z_w) > 15)
			pos_s_list[idx].color = create_trgb(0, 255, 255, 255);
		else if (z_w > 10)
			pos_s_list[idx].color = create_trgb(0, 50 * (z_w - 10), 50, 255);
		else if (z_w > 5)
			pos_s_list[idx].color = create_trgb(0, 255, 50 * (z_w - 5), 155);
		else if (z_w > 0)
			pos_s_list[idx].color = create_trgb(0, 155, 255, 50 * (z_w - 0));
		else if (z_w > -5)
			pos_s_list[idx].color = create_trgb(0, 50 * (z_w + 5), 155, 255);
		else
			pos_s_list[idx].color = create_trgb(0, 0, 50 * (z_w + 5), 155);
	}
}
