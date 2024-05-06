/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_util.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasong <dasong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 06:28:06 by sdg               #+#    #+#             */
/*   Updated: 2023/06/08 15:03:27 by dasong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_sprintf.h"
#include "../includes/ft_str_process.h"
#include "../includes/ft_printf_syntax.h"
#include "../includes/ft_convert_util.h"

int	res_pdiux_capx_sign(t_res *p_conv_num, t_spec *spec, size_t arg)
{
	if (!res_pdiux_capx_minus(p_conv_num, spec, arg))
	{
		free(p_conv_num->print_str);
		return (0);
	}
	if (!res_pdiux_capx_plus(p_conv_num, spec, arg))
	{
		free(p_conv_num->print_str);
		return (0);
	}
	return (1);
}

int	res_pdiux_capx_plus(t_res *p_conv_num, t_spec *spec, size_t arg)
{
	char	conv_ch;

	conv_ch = "cspdiuxX%"[spec->conv_i];
	if (spec->was_plus == 1)
	{
		if (conv_ch == 'd' || conv_ch == 'i')
		{
			if ((int)arg >= 0)
			{
				if (!ch_pre_join(p_conv_num, '+'))
					return (0);
			}
		}
		else
		{
			return (0);
		}
	}
	return (1);
}

int	res_pdiux_capx_minus(t_res *p_conv_num, t_spec *spec, size_t arg)
{
	char	conv_ch;

	conv_ch = "cspdiuxX%"[spec->conv_i];
	if (conv_ch == 'd' || conv_ch == 'i')
	{
		if ((int)arg < 0)
		{
			if (!ch_pre_join(p_conv_num, '-'))
			{
				return (0);
			}
		}
		else if ((spec->flags_i != -1) && spec->was_space == 1)
		{
			if (!ch_pre_join(p_conv_num, ' '))
			{
				return (0);
			}
		}
	}
	return (1);
}

int	read_ch_loop(const char *s, va_list *p_va, t_res *res)
{
	int		ret_res;
	t_spec	spec;

	while (*s)
	{
		init_specifier_info(&spec);
		if (*s == '%')
			ret_res = syntax(res, &s, &spec, p_va);
		else
			ret_res = ch_join(res, *s);
		if (!ret_res)
		{
			return (0);
		}
		s++;
	}
	return (1);
}

int	res_ll(t_res *p_res, t_spec *spec, t_res conv_num)
{
	int	digit_len;
	int	i;

	i = 0;
	digit_len = 0;
	if (conv_num.print_str != 0)
		digit_len = ft_strlen(conv_num.print_str);
	while (i < digit_len)
	{
		if (!ch_join(p_res, conv_num.print_str[i++]))
		{
			free(conv_num.print_str);
			return (0);
		}
	}
	if (!ch_n_join(p_res, spec->pad_ch, spec->width - digit_len))
	{
		if (digit_len)
			free(conv_num.print_str);
		return (0);
	}
	return (1);
}
