/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_syntax.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasong <dasong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 07:37:39 by dasong            #+#    #+#             */
/*   Updated: 2023/04/13 22:38:36 by dasong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf_syntax.h"
#include "../includes/ft_str_process.h"

int	syntax(t_res *p_res, const char **p_s, t_spec *spec, va_list *pp_va)
{
	(*p_s)++;
	if (is_in_specifier("#+- 0", **p_s, spec))
	{
		(*p_s)++;
		while (1)
		{
			loop_set_flag_was(p_s, spec);
			if (ft_strchr("#+- 0", **p_s))
				(*p_s)++;
			else
				break ;
		}
	}
	if (!reflect_num(&spec->width, p_s, spec))
		return (0);
	if (!check_syntax_prec(p_s, spec))
		return (0);
	if (is_in_specifier("cspdiuxX%", **p_s, spec))
	{
		if (!read_va("cspdiuxX%"[spec->conv_i], pp_va, p_res, spec))
			return (0);
	}
	else
		return (0);
	return (1);
}

int	check_syntax_prec(const char **p_s, t_spec *spec)
{
	if (**p_s == '.')
	{
		spec->precision_flag = 1;
		(*p_s)++;
		if (**p_s == '-')
		{
			if (!reflect_num(&spec->width, p_s, spec))
				return (0);
		}
		else
		{
			if (!reflect_num(&spec->min_of_digit, p_s, spec))
				return (0);
		}
	}
	return (1);
}

void	loop_set_flag_was(const char **p_s, t_spec *spec)
{
	if (**p_s == '#')
		spec->flags_i = 0;
	else if (**p_s == '-')
		spec->flags_i = 2;
	else if (**p_s == '+')
	{
		spec->flags_i = 1;
		spec->was_plus = 1;
		if (spec->was_minus)
			spec->flags_i = 2;
	}
	else if (**p_s == '0')
	{
		spec->flags_i = 4;
		spec->was_zero = 1;
		if (spec->was_minus == 1)
		{
			spec->flags_i = 2;
			spec->was_zero = 0;
		}
	}
	else if (**p_s == ' ')
		spec->flags_i = 3;
	if (**p_s != '0')
		set_flag_was(spec->flags_i, spec);
}
