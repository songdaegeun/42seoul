/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdg <sdg@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 01:06:13 by sdg               #+#    #+#             */
/*   Updated: 2023/05/23 03:53:05 by sdg              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap_bonus.h"

void	ft_putstr_fd(char *s, int fd)
{
	int	len;

	len = ft_strlen(s);
	write(fd, s, len);
}

int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	ft_min(int a, int b)
{
	if (a <= b)
		return (a);
	else
		return (b);
}

int	ft_max(int a, int b)
{
	if (a >= b)
		return (a);
	else
		return (b);
}

int	ft_abs(int a, int b)
{
	if (a <= b)
		return (b - a);
	else
		return (a - b);
}
