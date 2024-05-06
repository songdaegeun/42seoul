/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_syntax.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasong <dasong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 23:17:22 by dasong            #+#    #+#             */
/*   Updated: 2023/06/08 15:01:00 by dasong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_SYNTAX_H
# define FT_PRINTF_SYNTAX_H
# include "ft_sprintf.h"

int		syntax(t_res *p_res, const char **p_s, t_spec *spec, va_list *pp_va);
int		check_syntax_prec(const char **p_s, t_spec *spec);
void	loop_set_flag_was(const char **p_s, t_spec *spec);

#endif