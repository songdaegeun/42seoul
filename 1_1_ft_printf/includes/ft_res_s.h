/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_res_s.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasong <dasong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 23:17:48 by dasong            #+#    #+#             */
/*   Updated: 2023/04/07 20:49:26 by dasong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_RES_S_H
# define FT_RES_S_H
# include "ft_printf.h"

typedef struct s_npl
{
	int	null_flag;
	int	pad_ch;
	int	strlen;
}	t_npl;

int	res_s(t_res *p_res, t_spec *spec, size_t arg);
int	res_s_rightalign(t_npl npl, t_res *p_res, t_spec *spec, size_t arg);
int	res_s_leftalign(t_npl npl, t_res *p_res, t_spec *spec, size_t arg);
int	res_pdiux_rl(t_spec *spec, t_res *conv_num);
int	res_pdiux_ll(t_spec *spec, t_res *conv_num);

#endif