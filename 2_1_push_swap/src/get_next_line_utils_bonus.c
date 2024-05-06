/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdg <sdg@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 00:52:10 by sdg               #+#    #+#             */
/*   Updated: 2023/05/23 04:03:55 by sdg              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/get_next_line_bonus.h"

int	is_in(t_buff *p_buff, char ch)
{
	int	i;

	i = -1;
	while (++i < p_buff->size)
	{
		if (p_buff->buff[i] == ch)
			return (1);
	}
	return (0);
}
