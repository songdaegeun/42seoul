/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2nbr.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasong <dasong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 23:17:58 by dasong            #+#    #+#             */
/*   Updated: 2023/04/13 23:00:32 by dasong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_CONVERT_BASE2NBR_H
# define FT_CONVERT_BASE2NBR_H
# include "ft_printf.h"

char	*ft_convert_base2nbr(t_spec *spec, size_t nbr, \
const char *base_to, t_res *p_res);
int		ft_abs(int x);

#endif