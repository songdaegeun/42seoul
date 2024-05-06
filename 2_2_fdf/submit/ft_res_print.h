/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_res_print.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasong <dasong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 23:17:48 by dasong            #+#    #+#             */
/*   Updated: 2023/06/08 15:00:50 by dasong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_RES_PRINT_H
# define FT_RES_PRINT_H
# include "ft_sprintf.h"

int	ft_res_print(t_res *p_res, t_spec *spec, size_t arg);
int	add_prefix(char conv_ch, t_spec *spec, t_res *p_res, int num);
int	res_pdiux_capx_post_proc(t_res *conv_num, t_res *p_res, t_spec *spec);

#endif