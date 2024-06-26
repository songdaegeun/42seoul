/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_process.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasong <dasong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 23:12:18 by dasong            #+#    #+#             */
/*   Updated: 2023/06/08 15:00:46 by dasong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STR_PROCESS_H
# define FT_STR_PROCESS_H
# include "ft_sprintf.h"

int		is_in_specifier(const char *spec_str, \
const char c, t_spec *syntax_info);
int		ch_join(t_res *p_res, const char c);
int		ch_n_join(t_res *p_res, const char c, int len);
int		ch_pre_join(t_res *p_res, const char c);
void	set_flag_was(int i, t_spec *syntax_info);

#endif