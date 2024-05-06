/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_util_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasong <dasong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 06:28:06 by sdg               #+#    #+#             */
/*   Updated: 2023/04/13 23:02:18 by dasong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_str_process.h"
#include "../includes/ft_convert_util_2.h"

int	res_rl(t_res *p_res, t_spec *spec, t_res conv_num)
{
	int	digit_len;
	int	i;

	i = 0;
	digit_len = 0;
	if (conv_num.print_str != 0)
		digit_len = ft_strlen(conv_num.print_str);
	if (!ch_n_join(p_res, spec->pad_ch, spec->width - digit_len))
	{
		if (digit_len)
			free(conv_num.print_str);
		return (0);
	}
	while (i < digit_len)
	{
		if (!ch_join(p_res, conv_num.print_str[i++]))
		{
			free(conv_num.print_str);
			return (0);
		}
	}
	return (1);
}

int	ft_min(int min, int x)
{
	if (min > x)
	{
		return (x);
	}
	return (min);
}
