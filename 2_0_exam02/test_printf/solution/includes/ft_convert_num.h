/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_num.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasong <dasong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 23:15:51 by dasong            #+#    #+#             */
/*   Updated: 2023/04/13 22:55:28 by dasong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_CONVERT_NUM_H
# define FT_CONVERT_NUM_H
# include "ft_printf.h"

int	convert_num(t_spec *spec, size_t num, t_res *p_res);
int	res_pdiux_capx_proc(t_res *p_conv_num, t_spec *spec, size_t arg, int len);
int	res_pdiux_capx_sign(t_res *p_conv_num, t_spec *spec, size_t arg);
int	pad_width(t_res *p_conv_num, t_spec *spec, size_t arg, int len);
int	res_pdiux_capx_post_proc(t_res *conv_num, t_res *p_res, t_spec *spec);

#endif