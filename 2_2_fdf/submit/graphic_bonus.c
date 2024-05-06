/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphic_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasong <dasong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 17:51:16 by dasong            #+#    #+#             */
/*   Updated: 2023/06/09 17:19:04 by dasong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

int	is_gradi_over_1(t_point *s_pos, t_point *e_pos)
{
	return (ft_abs(e_pos->y - s_pos->y) > ft_abs(e_pos->x - s_pos->x));
}

int	set_draw_line(t_draw_line *draw_line_v, t_data *img)
{
	draw_line_v->xy[0] = draw_line_v->s_pos->x;
	draw_line_v->xy[1] = draw_line_v->s_pos->y;
	draw_line_v->xy_step[0] = 2 * (draw_line_v->e_pos->x - \
	draw_line_v->s_pos->x >= 0) - 1;
	draw_line_v->xy_step[1] = 2 * (draw_line_v->e_pos->y - \
	draw_line_v->s_pos->y >= 0) - 1;
	if (oob_xy(draw_line_v->s_pos->x, draw_line_v->s_pos->y))
		return (0);
	my_mlx_pixel_put(img, draw_line_v->s_pos->x, draw_line_v->s_pos->y, \
	get_color(draw_line_v->xy[0], draw_line_v->xy[1], draw_line_v->s_pos, \
	draw_line_v->e_pos));
	draw_line_v->w_h[0] = ft_abs(draw_line_v->e_pos->x - draw_line_v->s_pos->x);
	draw_line_v->w_h[1] = ft_abs(draw_line_v->e_pos->y - draw_line_v->s_pos->y);
	return (1);
}

void	x_draw_line(t_draw_line	*draw_line_v, t_data *img)
{
	draw_line_v->det = (2 * draw_line_v->w_h[1]) - draw_line_v->w_h[0];
	draw_line_v->xy[0] = draw_line_v->s_pos->x;
	while (draw_line_v->xy[0] != draw_line_v->e_pos->x)
	{
		if (draw_line_v->det < 0)
			draw_line_v->det += 2 * draw_line_v->w_h[1];
		else
		{
			draw_line_v->xy[1] += draw_line_v->xy_step[1];
			draw_line_v->det += (2 * draw_line_v->w_h[1] - 2 * \
			draw_line_v->w_h[0]);
		}
		if (oob_xy(draw_line_v->xy[0], draw_line_v->xy[1]))
		{
			draw_line_v->xy[0] += draw_line_v->xy_step[0];
			continue ;
		}
		my_mlx_pixel_put(img, draw_line_v->xy[0], draw_line_v->xy[1], \
		get_color(draw_line_v->xy[0], draw_line_v->xy[1], \
		draw_line_v->s_pos, draw_line_v->e_pos));
		draw_line_v->xy[0] += draw_line_v->xy_step[0];
	}
}

void	y_draw_line(t_draw_line	*draw_line_v, t_data *img)
{
	draw_line_v->det = (2 * draw_line_v->w_h[0]) - draw_line_v->w_h[1];
	draw_line_v->xy[1] = draw_line_v->s_pos->y;
	while (draw_line_v->xy[1] != draw_line_v->e_pos->y)
	{
		if (draw_line_v->det < 0)
			draw_line_v->det += 2 * draw_line_v->w_h[0];
		else
		{
			draw_line_v->xy[0] += draw_line_v->xy_step[0];
			draw_line_v->det += (2 * draw_line_v->w_h[0] - 2 * \
			draw_line_v->w_h[1]);
		}
		if (oob_xy(draw_line_v->xy[0], draw_line_v->xy[1]))
		{
			draw_line_v->xy[1] += draw_line_v->xy_step[1];
			continue ;
		}
		my_mlx_pixel_put(img, draw_line_v->xy[0], draw_line_v->xy[1], \
		get_color(draw_line_v->xy[0], draw_line_v->xy[1], \
		draw_line_v->s_pos, draw_line_v->e_pos));
		draw_line_v->xy[1] += draw_line_v->xy_step[1];
	}
}

void	draw_line(t_data *img, t_point *s_pos, t_point *e_pos)
{
	int			w_h[2];
	int			xy[2];
	int			xy_step[2];
	t_draw_line	draw_line_v;

	draw_line_v.s_pos = s_pos;
	draw_line_v.e_pos = e_pos;
	draw_line_v.w_h = w_h;
	draw_line_v.xy = xy;
	draw_line_v.xy_step = xy_step;
	if (!set_draw_line(&draw_line_v, img))
		return ;
	if (w_h[0] > w_h[1])
		x_draw_line(&draw_line_v, img);
	else
		y_draw_line(&draw_line_v, img);
}
