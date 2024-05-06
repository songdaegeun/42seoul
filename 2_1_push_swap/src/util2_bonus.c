/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util2_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdg <sdg@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 00:06:41 by sdg               #+#    #+#             */
/*   Updated: 2023/05/23 03:53:07 by sdg              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap_bonus.h"

int	ft_strncmp(const char *s1, const char *s2, int n)
{
	int				i;
	unsigned char	*u_s1;
	unsigned char	*u_s2;

	u_s1 = (unsigned char *)s1;
	u_s2 = (unsigned char *)s2;
	i = 0;
	while (u_s1[i] && i < n)
	{
		if (u_s1[i] != u_s2[i])
			return (u_s1[i] - u_s2[i]);
		i++;
	}
	if (i != n)
		return (u_s1[i] - u_s2[i]);
	else
		return (0);
}
