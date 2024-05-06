/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_num.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasong <dasong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 20:19:37 by dasong            #+#    #+#             */
/*   Updated: 2023/06/08 15:02:08 by dasong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_sprintf.h"
#include "../includes/ft_convert_base2nbr.h"
#include "../includes/ft_str_process.h"
#include "../includes/ft_convert_num.h"
#include "../includes/ft_convert_util.h"
#include "../includes/ft_res_print.h"
#include "../includes/ft_res_s.h"

static int	pad_min_of_digit(t_spec *spec, t_res *p_res);

int	convert_num(t_spec *spec, size_t num, t_res *p_res)
{
	char		conv_ch;
	const char	*base_str;

	conv_ch = "cspdiuxX%"[spec->conv_i];
	base_str = "0123456789abcdef";
	if (conv_ch == 'd' || conv_ch == 'i' || conv_ch == 'u')
		base_str = "0123456789";
	else if (conv_ch == 'X')
		base_str = "0123456789ABCDEF";
	if (!ft_convert_base2nbr(spec, num, base_str, p_res))
		return (0);
	if ("cspdiuxX%"[spec->conv_i] == 'p')
	{
		if (!add_prefix(conv_ch, spec, p_res, num))
		{
			free(p_res->print_str);
			return (0);
		}
	}
	if (!pad_min_of_digit(spec, p_res))
	{
		free(p_res->print_str);
		return (0);
	}
	return (1);
}

static int	pad_min_of_digit(t_spec *spec, t_res *p_res)
{
	int	len;

	if (spec->precision_flag == 1)
	{
		len = ft_strlen(p_res->print_str);
		while (spec->min_of_digit - len > 0)
		{
			if (!ch_pre_join(p_res, '0'))
				return (0);
			spec->min_of_digit--;
		}
	}
	return (1);
}

int	res_pdiux_capx_proc(t_res *p_conv_num, t_spec *spec, size_t arg, int len)
{
	char	conv_ch;

	conv_ch = "cspdiuxX%"[spec->conv_i];
	if ((spec->was_zero == 1 && spec->precision_flag == 0) && \
	(((conv_ch == 'x' || conv_ch == 'X') && (arg)) && spec->was_shop))
		spec->width = spec->width - 2;
	if (!((spec->conv_i >= 3 && spec->conv_i <= 7) && \
	spec->precision_flag == 1 && spec->min_of_digit == 0 && arg == 0))
	{
		if (!convert_num(spec, arg, p_conv_num))
			return (0);
		if (!pad_width(p_conv_num, spec, arg, len))
		{
			free(p_conv_num->print_str);
			return (0);
		}
	}
	if (!res_pdiux_capx_sign(p_conv_num, spec, arg))
		return (0);
	return (1);
}

int	pad_width(t_res *p_conv_num, t_spec *spec, size_t arg, int len)
{
	if ((spec->conv_i >= 2 && spec->conv_i <= 7) && spec->pad_ch == '0')
	{
		if (((int)arg < 0 || (spec->flags_i >= 1 && \
		spec->flags_i <= 3)) && (spec->conv_i == 3 || spec->conv_i == 4))
			spec->width--;
		if (((int)arg >= 0) && spec->flags_i == 4 && \
		(spec->was_space || spec->was_plus))
			spec->width--;
		len = p_conv_num->len;
		while (spec->width-- - len > 0)
		{
			if (!ch_pre_join(p_conv_num, '0'))
				return (0);
		}
	}
	return (1);
}

int	res_pdiux_capx_post_proc(t_res *conv_num, t_res *p_res, t_spec *spec)
{
	int		digit_len;
	int		i;

	if (spec->was_minus == 1)
	{
		if (!res_pdiux_ll(spec, conv_num))
			return (0);
	}
	else
	{
		if (!res_pdiux_rl(spec, conv_num))
			return (0);
	}
	digit_len = 0;
	if (conv_num->print_str != 0)
		digit_len = ft_strlen(conv_num->print_str);
	i = 0;
	while (i < digit_len)
	{
		if (!ch_join(p_res, conv_num->print_str[i]))
			return (0);
		i++;
	}
	return (1);
}
