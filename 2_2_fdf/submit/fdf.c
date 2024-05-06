/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasong <dasong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 03:09:09 by dasong            #+#    #+#             */
/*   Updated: 2023/06/09 21:10:36 by dasong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	init_manipul_info(t_manipul_info *manipul_info)
{
	manipul_info->x_f = 0;
	manipul_info->y_f = 0;
	manipul_info->theta_x = 0;
	manipul_info->theta_y = 0;
	manipul_info->theta_z = 0;
	manipul_info->z_scale = 1;
	manipul_info->zoom_scale = 1.0;
	manipul_info->focal_l = 0.1;
}

void	init(t_vars *vars, t_map_info *map_info, t_data *img, \
t_manipul_info *manipul_info)
{
	vars->p_map_info = map_info;
	vars->p_img = img;
	init_manipul_info(manipul_info);
	vars->p_manipul_info = manipul_info;
	zoom_preset(vars);
}

int	main(int argc, char **argv)
{
	t_data			img;
	t_map_info		map_info;
	t_vars			vars;
	t_manipul_info	manipul_info;

	if (argc != 2)
	{
		write(1, "format error!\n", 14);
		return (0);
	}
	map_info.map = 0;
	parse_map(&map_info, argv[1]);
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, PANEL + SCREEN_WIDTH, \
	SCREEN_HEIGHT, "fdf");
	img.img = mlx_new_image(vars.mlx, SCREEN_WIDTH, SCREEN_HEIGHT);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, \
	&img.line_length, &img.endian);
	init(&vars, &map_info, &img, &manipul_info);
	draw_map(&vars);
	mlx_put_image_to_window(vars.mlx, vars.win, img.img, 0, 0);
	put_ctl_msg(&vars);
	mlx_hook(vars.win, 2, 1L << 0, key_callback, &vars);
	mlx_hook(vars.win, 17, 1L << 19, destroy_callback, &vars);
	mlx_loop(vars.mlx);
}
