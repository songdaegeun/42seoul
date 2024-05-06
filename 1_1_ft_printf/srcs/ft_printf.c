/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasong <dasong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 16:28:10 by dasong            #+#    #+#             */
/*   Updated: 2023/04/13 23:02:29 by dasong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../includes/ft_str_process.h"
#include "../includes/ft_res_print.h"
#include "../includes/ft_convert_num.h"
#include "../includes/ft_printf_syntax.h"
#include "../includes/ft_convert_util.h"
#include "../includes/ft_res_s.h"
#include "../includes/ft_convert_base2nbr.h"

int	ft_printf(const char *s, ...)
{
	t_res		res;
	va_list		p_va;

	va_start(p_va, s);
	res.print_str = ft_strdup("");
	if (!res.print_str)
		return (-1);
	res.len = 0;
	if (!read_ch_loop(s, &p_va, &res))
	{
		free(res.print_str);
		return (-1);
	}
	res.len = write(1, res.print_str, res.len);
	free(res.print_str);
	return (res.len);
}

void	init_specifier_info(t_spec *spec)
{
	spec->conv_i = 0;
	spec->flags_i = 0;
	spec->min_of_digit = 0;
	spec->precision_flag = 0;
	spec->width = 0;
	spec->pad_ch = ' ';
	spec->was_space = 0;
	spec->was_plus = 0;
	spec->was_minus = 0;
	spec->was_zero = 0;
	spec->was_shop = 0;
}

int	reflect_num(int *p_num, const char **p_s, t_spec *spec)
{
	t_res		buff_res;
	const char	*s;

	buff_res.print_str = 0;
	s = *p_s;
	if (*s == '-' && spec->precision_flag == 1)
		spec->flags_i = 2;
	while (*s == '-' || ft_isdigit(*s))
	{
		if (!ch_join(&buff_res, *s))
		{
			free(buff_res.print_str);
			return (0);
		}
		s++;
	}
	if (buff_res.print_str)
	{
		*p_num = ft_abs(ft_atoi(buff_res.print_str));
		free(buff_res.print_str);
	}
	*p_s = s;
	return (1);
}

int	read_va(char conv_ch, va_list *pp_va, t_res *p_res, t_spec *spec)
{
	t_res	conv_num;

	conv_num.print_str = 0;
	if (conv_ch == '%')
	{
		if (!ch_join(&conv_num, '%'))
			return (0);
		ft_percent_res_print(&conv_num, p_res, spec, conv_num.len);
	}
	else if (conv_ch == 'c' || conv_ch == 'd' || conv_ch == 'i')
	{
		if (!ft_res_print(p_res, spec, va_arg(*pp_va, int)))
			return (0);
	}
	else if (conv_ch == 's' || conv_ch == 'p')
	{
		if (!ft_res_print(p_res, spec, va_arg(*pp_va, size_t)))
			return (0);
	}
	else
	{
		if (!ft_res_print(p_res, spec, va_arg(*pp_va, unsigned int)))
			return (0);
	}
	return (1);
}

int	ft_percent_res_print(t_res *conv_num, t_res *p_res, t_spec *spec, int len)
{
	if ((spec->conv_i >= 3 && spec->conv_i <= 7) && spec->pad_ch == '0')
	{
		while (spec->width-- - len > 0)
		{
			if (!ch_pre_join(conv_num, '0'))
			{
				free(conv_num->print_str);
				return (0);
			}
		}
	}
	if (spec->flags_i != -1 && "#+- 0"[spec->flags_i] == '-')
	{
		if (!res_ll(p_res, spec, *conv_num))
			return (0);
	}
	else
	{
		if (!res_rl(p_res, spec, *conv_num))
			return (0);
	}
	free(conv_num->print_str);
	return (1);
}
