/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_process.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasong <dasong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 19:26:29 by dasong            #+#    #+#             */
/*   Updated: 2023/04/13 23:06:07 by dasong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_str_process.h"

int	is_in_specifier(const char *spec_str, const char c, t_spec *syntax_info)
{
	int	i;

	i = 0;
	if (ft_strncmp(spec_str, "#+- 0", ft_strlen(spec_str)) == 0)
	{
		while (spec_str[i] != c && spec_str[i])
			i++;
		syntax_info->flags_i = i;
		set_flag_was(i, syntax_info);
	}
	else if (ft_strncmp(spec_str, "cspdiuxX%", ft_strlen(spec_str)) == 0)
	{
		while (spec_str[i] != c && spec_str[i])
			i++;
		syntax_info->conv_i = i;
	}
	if (!spec_str[i])
	{
		syntax_info->flags_i = -1;
		return (0);
	}
	else
		return (1);
}

int	ch_join(t_res *p_res, const char c)
{
	int		total;
	char	*new_res;
	int		i;

	total = 1;
	if (p_res->print_str)
		total = p_res->len + 1;
	new_res = (char *)malloc(sizeof(char) * (total + 1));
	if (!new_res)
		return (0);
	new_res[total] = '\0';
	if (p_res->print_str)
	{
		i = 0;
		while (i < p_res->len)
		{
			new_res[i] = p_res->print_str[i];
			i++;
		}
		free(p_res->print_str);
	}
	new_res[total - 1] = c;
	p_res->print_str = new_res;
	p_res->len = total;
	return (1);
}

int	ch_n_join(t_res *p_res, const char c, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		if (!ch_join(p_res, c))
			return (0);
		i++;
	}
	return (1);
}

int	ch_pre_join(t_res *p_res, const char c)
{
	int		total;
	char	*new_res;
	int		i;

	total = 1;
	if (p_res->print_str)
		total = p_res->len + 1;
	new_res = (char *)malloc(sizeof(char) * (total + 1));
	if (!new_res)
		return (0);
	new_res[total] = '\0';
	if (p_res->print_str)
	{
		i = 0;
		while (i < p_res->len)
		{
			new_res[i + 1] = p_res->print_str[i];
			i++;
		}
		free(p_res->print_str);
	}
	new_res[0] = c;
	p_res->print_str = new_res;
	p_res->len = total;
	return (1);
}

void	set_flag_was(int i, t_spec *syntax_info)
{
	if (i == 3)
		syntax_info->was_space = 1;
	else if (i == 0)
		syntax_info->was_shop = 1;
	else if (i == 1)
		syntax_info->was_plus = 1;
	else if (i == 2)
		syntax_info->was_minus = 1;
	else if (i == 4)
		syntax_info->was_zero = 1;
}
