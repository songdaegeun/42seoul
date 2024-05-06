/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_res_print.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasong <dasong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 19:17:58 by dasong            #+#    #+#             */
/*   Updated: 2023/06/08 15:02:00 by dasong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_sprintf.h"
#include "../includes/ft_str_process.h"
#include "../includes/ft_convert_num.h"
#include "../includes/ft_res_s.h"
#include "../includes/ft_res_print.h"

static int	pad_and_conc(t_res *p_res, t_spec *spec, size_t arg);
static int	res_pdiux_capx(t_res *p_res, t_spec *spec, size_t arg);
static int	res_c(t_res *p_res, t_spec *spec, size_t arg);

int	ft_res_print(t_res *p_res, t_spec *spec, size_t arg)
{
	if (spec->flags_i != -1 && (spec->was_zero || spec->was_space))
	{
		if ("#+- 0"[spec->flags_i] == '0')
		{
			spec->pad_ch = '0';
		}
		else
		{
			spec->pad_ch = ' ';
			if (spec->precision_flag != 1 && spec->was_zero == 1)
				spec->pad_ch = '0';
		}
	}
	if (!pad_and_conc(p_res, spec, arg))
		return (0);
	return (1);
}

static int	pad_and_conc(t_res *p_res, t_spec *spec, size_t arg)
{
	if ("cspdiuxX%"[spec->conv_i] == 's')
	{
		if (!res_s(p_res, spec, arg))
			return (0);
	}
	else if ("cspdiuxX%"[spec->conv_i] == 'c')
	{
		if (!res_c(p_res, spec, arg))
			return (0);
	}
	else
	{
		if (!res_pdiux_capx(p_res, spec, arg))
			return (0);
	}
	return (1);
}

static int	res_pdiux_capx(t_res *p_res, t_spec *spec, size_t arg)
{
	t_res	conv_num;

	conv_num.print_str = 0;
	if (spec->flags_i != -1 && "#+- 0"[spec->flags_i] == '0' \
	&& spec->precision_flag == 1)
		spec->pad_ch = ' ';
	if (!res_pdiux_capx_proc(&conv_num, spec, arg, 0))
		return (0);
	if ("cspdiuxX%"[spec->conv_i] != 'p')
	{
		if (!add_prefix("cspdiuxX%"[spec->conv_i], spec, &conv_num, arg))
		{
			free(p_res->print_str);
			return (0);
		}
	}
	if (!res_pdiux_capx_post_proc(&conv_num, p_res, spec))
	{
		if (conv_num.print_str)
			free(conv_num.print_str);
		return (0);
	}
	if (conv_num.print_str)
		free(conv_num.print_str);
	return (1);
}

static int	res_c(t_res *p_res, t_spec *spec, size_t arg)
{
	char	arg_ch;

	arg_ch = (char)arg;
	if (spec->flags_i == -1)
	{
		if (!ch_n_join(p_res, spec->pad_ch, spec->width - 1))
			return (0);
		if (!ch_join(p_res, arg_ch))
			return (0);
	}
	else if ("#+- 0"[spec->flags_i] == '-')
	{
		if (!ch_join(p_res, arg_ch))
			return (0);
		if (!ch_n_join(p_res, spec->pad_ch, spec->width - 1))
			return (0);
	}
	else
		return (0);
	return (1);
}

int	add_prefix(char conv_ch, t_spec *spec, t_res *p_res, int num)
{
	if (conv_ch == 'p')
	{
		if (!ch_pre_join(p_res, 'x'))
			return (0);
		if (!ch_pre_join(p_res, '0'))
			return (0);
	}
	else if ((conv_ch == 'x' || conv_ch == 'X') && (num))
	{
		if (spec->was_shop)
		{
			if (!ch_pre_join(p_res, conv_ch))
				return (0);
			if (!ch_pre_join(p_res, '0'))
				return (0);
		}
	}
	return (1);
}
