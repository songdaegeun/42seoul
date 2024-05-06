/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_util.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasong <dasong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 23:17:22 by dasong            #+#    #+#             */
/*   Updated: 2023/04/13 22:59:54 by dasong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_CONVERT_UTIL_H
# define FT_CONVERT_UTIL_H
# include "ft_printf.h"

int	res_pdiux_capx_sign(t_res *p_conv_num, t_spec *spec, size_t arg);
int	res_pdiux_capx_plus(t_res *p_conv_num, t_spec *spec, size_t arg);
int	res_pdiux_capx_minus(t_res *p_conv_num, t_spec *spec, size_t arg);
int	read_ch_loop(const char *s, va_list *p_va, t_res *res);
int	res_ll(t_res *p_res, t_spec *spec, t_res conv_num);
int	res_rl(t_res *p_res, t_spec *spec, t_res conv_num);

#endif