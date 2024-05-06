/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   option_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasong <dasong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 12:26:20 by dasong            #+#    #+#             */
/*   Updated: 2023/06/09 17:19:40 by dasong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

void	rotate_option(t_vars *vars, t_world_coordi *world_coordi)
{
	rotate_x(&world_coordi->y, &world_coordi->z, \
	vars->p_manipul_info->theta_x);
	rotate_y(&world_coordi->x, &world_coordi->z, \
	vars->p_manipul_info->theta_y);
	rotate_z(&world_coordi->x, &world_coordi->y, \
	vars->p_manipul_info->theta_z);
}
