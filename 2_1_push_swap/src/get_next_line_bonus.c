/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdg <sdg@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 00:51:24 by sdg               #+#    #+#             */
/*   Updated: 2023/05/23 03:58:10 by sdg              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	static t_buff	buff;
	char			*res;
	int				size;
	int				i;

	if (buff.capacity == 0 && !init_buff(&buff))
	{
		buff.capacity = 0;
		return (0);
	}
	size = -1;
	if (!load_buff(fd, &buff) || !ret_buff(&buff, &res, &size))
	{
		free(buff.buff);
		buff.capacity = 0;
		return (0);
	}
	i = -1;
	while (++i < (buff.size - size))
		(buff.buff)[i] = (buff.buff + size)[i];
	buff.size = buff.size - size;
	return (res);
}

int	init_buff(t_buff *p_buff)
{
	p_buff->capacity = 1024;
	p_buff->size = 0;
	p_buff->buff = (char *)malloc(sizeof(char) * p_buff->capacity);
	if (!p_buff->buff)
		return (0);
	return (1);
}

int	ret_buff(t_buff *p_buff, char **res, int *p_size)
{
	int	i;

	while (++(*p_size) < p_buff->size)
	{
		if (p_buff->buff[*p_size] == '\n')
		{
			(*p_size)++;
			break ;
		}
	}
	if (!*p_size)
	{
		*res = 0;
		free(p_buff->buff);
		p_buff->capacity = 0;
		return (1);
	}
	*res = (char *)malloc(sizeof(char) * (*p_size + 1));
	if (!*res)
		return (0);
	(*res)[*p_size] = 0;
	i = -1;
	while (++i < *p_size)
		(*res)[i] = p_buff->buff[i];
	return (1);
}

int	load_buff(int fd, t_buff *p_buff)
{
	char	temp_buff[BUFFER_SIZE];
	int		read_size;
	int		i;

	while (!is_in(p_buff, '\n'))
	{
		read_size = read(fd, temp_buff, BUFFER_SIZE);
		if (read_size <= 0)
			break ;
		i = -1;
		while (++i < read_size)
		{
			p_buff->buff[p_buff->size++] = temp_buff[i];
			if (!chk_size(p_buff))
				return (0);
		}
	}
	if (read_size < 0)
		return (0);
	return (1);
}

int	chk_size(t_buff *p_buff)
{
	char	*tmp_buff;
	int		i;

	if (p_buff->size == p_buff->capacity)
	{
		p_buff->capacity *= 2;
		tmp_buff = (char *)malloc(sizeof(char) * p_buff->capacity);
		if (!tmp_buff)
			return (0);
		i = -1;
		while (++i < p_buff->size)
			tmp_buff[i] = p_buff->buff[i];
		free(p_buff->buff);
		p_buff->buff = tmp_buff;
	}
	return (1);
}
