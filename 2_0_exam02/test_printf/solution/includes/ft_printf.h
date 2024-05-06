/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasong <dasong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 23:17:22 by dasong            #+#    #+#             */
/*   Updated: 2023/04/13 23:00:50 by dasong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include "libft.h"

typedef struct s_spec
{
	int		flags_i;
	int		width;
	int		precision_flag;
	int		min_of_digit;
	int		conv_i;
	char	pad_ch;
	int		was_space;
	int		was_plus;
	int		was_zero;
	int		was_minus;
	int		was_shop;
}	t_spec;

typedef struct s_res
{
	char	*print_str;
	int		len;
}	t_res;

int		ft_printf(const char *s, ...);
int		reflect_num(int *p_num, const char **p_s, t_spec *spec);
int		read_va(char conv_ch, va_list *pp_va, t_res *p_res, t_spec *spec);
void	init_specifier_info(t_spec *spec);
int		ft_percent_res_print(t_res *conv_num, \
t_res *p_res, t_spec *spec, int len);

#endif