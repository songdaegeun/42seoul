/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_res_s.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasong <dasong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 07:18:27 by dasong            #+#    #+#             */
/*   Updated: 2023/04/13 23:03:51 by dasong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../includes/ft_res_s.h"
#include "../includes/ft_str_process.h"
#include "../includes/ft_convert_util_2.h"

int	res_s(t_res *p_res, t_spec *spec, size_t arg)
{
	int		ret_res;
	t_npl	npl;

	npl.pad_ch = spec->pad_ch;
	ret_res = 1;
	if (!(spec->flags_i == -1 || (spec->flags_i >= 2 && spec->flags_i <= 4)))
		return (0);
	npl.null_flag = 0;
	if (!arg)
	{
		npl.null_flag = 1;
		arg = (size_t)ft_strdup("(null)");
		if (!arg)
			return (0);
	}
	npl.strlen = ft_strlen((char *)arg);
	if (spec->precision_flag == 1)
		npl.strlen = ft_min(spec->min_of_digit, ft_strlen((char *)arg));
	if (spec->flags_i == -1)
		ret_res = res_s_rightalign(npl, p_res, spec, arg);
	else
		ret_res = res_s_leftalign(npl, p_res, spec, arg);
	if (!ret_res)
		return (0);
	return (1);
}

int	res_s_rightalign(t_npl npl, t_res *p_res, t_spec *spec, size_t arg)
{
	int	i;

	i = 0;
	if (!ch_n_join(p_res, npl.pad_ch, spec->width - npl.strlen))
	{
		if (npl.null_flag)
			free((void *)arg);
		return (0);
	}
	while (i < npl.strlen)
	{
		if (!ch_join(p_res, ((char *)arg)[i++]))
		{
			if (npl.null_flag)
				free((void *)arg);
			return (0);
		}
	}
	if (npl.null_flag)
		free((void *)arg);
	return (1);
}

int	res_s_leftalign(t_npl npl, t_res *p_res, t_spec *spec, size_t arg)
{
	int	i;

	i = 0;
	while (i < npl.strlen)
	{
		if (!ch_join(p_res, ((char *)arg)[i++]))
		{
			if (npl.null_flag)
				free((void *)arg);
			return (0);
		}
	}
	if (!ch_n_join(p_res, npl.pad_ch, spec->width - npl.strlen))
	{
		if (npl.null_flag)
			free((void *)arg);
		return (0);
	}
	if (npl.null_flag)
		free((void *)arg);
	return (1);
}

int	res_pdiux_ll(t_spec *spec, t_res *conv_num)
{
	int	digit_len;

	digit_len = 0;
	if (conv_num->print_str != 0)
		digit_len = ft_strlen(conv_num->print_str);
	if (!ch_n_join(conv_num, spec->pad_ch, spec->width - digit_len))
	{
		if (digit_len)
			free(conv_num->print_str);
		return (0);
	}
	return (1);
}

int	res_pdiux_rl(t_spec *spec, t_res *conv_num)
{
	int	digit_len;
	int	i;

	digit_len = 0;
	if (conv_num->print_str != 0)
		digit_len = ft_strlen(conv_num->print_str);
	i = 0;
	while (i < spec->width - digit_len)
	{
		if (!ch_pre_join(conv_num, spec->pad_ch))
		{
			if (digit_len)
				free(conv_num->print_str);
			return (0);
		}
		i++;
	}
	return (1);
}
