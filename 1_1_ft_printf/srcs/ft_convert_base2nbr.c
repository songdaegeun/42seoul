/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2nbr.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasong <dasong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 02:46:28 by sdg               #+#    #+#             */
/*   Updated: 2023/04/13 23:03:02 by dasong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../includes/ft_convert_base2nbr.h"

static void	convert_base(size_t nbr, const char *base, char *res);
static int	count_digit(size_t nbr, int num);

char	*ft_convert_base2nbr(t_spec *spec, size_t nbr, \
const char *base_to, t_res *p_res)
{
	int			num;
	long long	l_nbr;
	int			len;
	char		*res;

	l_nbr = (long long)nbr;
	if (l_nbr < 0)
		(l_nbr) *= -1;
	num = ft_strlen(base_to);
	if ("cspdiuxX%"[spec->conv_i] == 'p' || "cspdiuxX%"[spec->conv_i] == 'x')
		len = count_digit(nbr, num);
	else
		len = count_digit(l_nbr, num);
	res = (char *)malloc(sizeof(char) * (len + 1));
	if (!res)
		return (0);
	if ("cspdiuxX%"[spec->conv_i] == 'p' || "cspdiuxX%"[spec->conv_i] == 'x')
		convert_base(nbr, base_to, res);
	else
		convert_base(l_nbr, base_to, res);
	res[len] = '\0';
	p_res->print_str = res;
	p_res->len = ft_strlen(p_res->print_str);
	return (res);
}

static void	convert_base(size_t nbr, const char *base, char *res)
{
	int	num;
	int	len;
	int	depth;

	num = ft_strlen(base);
	len = count_digit(nbr, num);
	depth = 0;
	res[len - 1 - depth] = base[nbr % num];
	nbr /= num;
	depth++;
	while (nbr)
	{
		res[len - 1 - depth] = base[nbr % num];
		nbr /= num;
		depth++;
	}
}

static int	count_digit(size_t nbr, int num)
{
	int	cnt;

	cnt = 1;
	while (nbr / num)
	{
		nbr /= num;
		cnt++;
	}
	return (cnt);
}

int	ft_abs(int x)
{
	if (x < 0)
	{
		return (-x);
	}
	return (x);
}
