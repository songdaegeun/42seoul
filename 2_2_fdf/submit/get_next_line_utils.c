/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasong <dasong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 00:52:10 by sdg               #+#    #+#             */
/*   Updated: 2023/06/02 15:57:15 by dasong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
