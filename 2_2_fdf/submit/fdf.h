/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasong <dasong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 16:03:58 by dasong            #+#    #+#             */
/*   Updated: 2023/06/09 21:11:07 by dasong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define ISOMETRIC 1
# define PERSPECTIVE 0
# define FDF_H
# define PANEL 500
# define PANEL_X_MARGIN 10
# define PANEL_LINE_NUM 30
# define SCREEN_WIDTH 1920
# define SCREEN_HEIGHT 1080
# define KEY_ESC 53
# define KEY_ZOOM_IN 24
# define KEY_ZOOM_OUT 27
# define KEY_UP 126
# define KEY_DOWN 125
# define KEY_LEFT 123
# define KEY_RIGHT 124
# define KEY_ROTATE_Y_CLOCK 1
# define KEY_ROTATE_Y_CLOCK_R 0
# define KEY_ROTATE_X_CLOCK 7
# define KEY_ROTATE_X_CLOCK_R 6
# define KEY_ROTATE_Z_CLOCK 13
# define KEY_ROTATE_Z_CLOCK_R 12
# define KEY_Z_HEIGHT_UP 14
# define KEY_Z_HEIGHT_DOWN 2
# include "get_next_line.h"
# include "libft.h"
# include "ft_sprintf.h"
# include "ft_res_print.h"
# include "ft_str_process.h"
# include "ft_convert_base2nbr.h"
# include "ft_convert_num.h"
# include "ft_res_s.h"
# include "ft_printf_syntax.h"
# include "ft_convert_util.h"
# include "ft_convert_util_2.h"
# include "mlx.h"
# include <math.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct s_point {
	int	x;
	int	y;
	int	color;
}				t_point;

typedef struct s_world_coordi {
	int		x;
	int		y;
	int		z;
	int		w;
	int		h;
	int		d;
	t_point	*pos_s_list;
}	t_world_coordi;

typedef struct s_draw_line {
	int		det;
	int		*w_h;
	int		*xy;
	int		*xy_step;
	t_point	*s_pos;
	t_point	*e_pos;
}	t_draw_line;

typedef struct s_map_info {
	t_list	*map;
	int		width;
	int		height;
	int		depth;
}	t_map_info;

typedef struct s_manipul_info {
	int		x_f;
	int		y_f;
	double	theta_x;
	double	theta_y;
	double	theta_z;
	double	z_scale;
	double	zoom_scale;
	double	focal_l;
}	t_manipul_info;

typedef struct s_vars {
	void			*mlx;
	void			*win;
	t_data			*p_img;
	t_map_info		*p_map_info;
	t_manipul_info	*p_manipul_info;
}	t_vars;

int		is_gradi_over_1(t_point *s_pos, t_point *e_pos);
void	draw_line(t_data *img, t_point *s_pos, t_point *e_pos);
int		set_draw_line(t_draw_line *draw_line_v, t_data *img);
void	x_draw_line(t_draw_line	*draw_line_v, t_data *img);
void	y_draw_line(t_draw_line	*draw_line_v, t_data *img);
void	rotate_z(int *x, int *y, double theta);
void	rotate_x(int *y, int *z, double theta);
void	rotate_y(int *x, int *z, double theta);

int		parse_strarr(char **str_arr);
void	free_res(char **res);
void	allocate_map(char **res, t_map_info *map_info, int *max_depth);
int		parse_map(t_map_info *map_info, char *map_addr);
t_list	*ft_lstidx(t_list *lst, int idx);
int		oob_xy(int x, int y);
void	scale_coordi(t_vars *vars, t_world_coordi *world_coordi);
void	set_coordi(t_vars *vars, t_world_coordi *world_coordi, int *xyz_w);

void	my_mlx_pixel_put(t_data *data, int x, int y, int color);

double	get_ratio(int s, int e, int cur);
int		create_trgb(int t, int r, int g, int b);
int		get_dist(int s, int e, double d1);
int		oob_check(int x, int y, int z);
int		oob(t_map_info *map_info, double scale);
void	draw_map(t_vars *vars);
void	set_draw_map(t_vars *vars, t_world_coordi \
*world_coordi, int *xyz_w, int *idx);
int		get_color(int x, int y, t_point *s, t_point *e);
void	color_mapping(t_point *pos_s_list, int z_w, int idx);
void	draw_wire(t_vars *vars, int now_idx, t_point *pos_s_list);

void	zoom_callback(int keycode, t_vars *vars);
void	z_height_mani(int keycode, t_vars *vars);
void	rotation(int keycode, t_vars *vars);
void	translation(int keycode, t_vars *vars);
int		key_callback(int keycode, t_vars *vars);

void	my_clear_img(t_vars *vars);
void	memory_release(t_map_info *map_info);
int		destroy_callback(t_vars *vars);
void	init_manipul_info(t_manipul_info *manipul_info);
void	zoom_preset(t_vars *vars);
void	init(t_vars *vars, t_map_info *map_info, t_data *img, \
t_manipul_info *manipul_info);
int		set_put_ctl_msg(t_vars *vars, char *(*str)[7]);
void	ctl_msg_script1(t_vars *vars, char **str);
void	ctl_msg_script2(t_vars *vars, char **str);
void	put_ctl_msg(t_vars *vars);
void	free_set_put_ctl_msg(char **str);

int		not_adjacent(t_vars *vars, int *d_idx);
void	set_draw_wire(int *d_idx, t_map_info *map_i, \
t_point *pos_s, t_point *pos_s_list);

void	rotate_option(t_vars *vars, t_world_coordi *world_coordi);

void	projection(t_vars *vars, t_world_coordi *world_coordi, int *xy_s);
void	isometric(int *x, int *y, int *z);
void	perspective(t_vars *vars, int *x, int *y, int *z);

#endif