/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgangaro <cgangaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 17:29:49 by cgangaro          #+#    #+#             */
/*   Updated: 2021/09/22 13:33:22 by cgangaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

int	verif(char **line, char **buff_mem)
{
	char	*temp;

	if (*buff_mem && ft_strchr(*buff_mem, 10) != NULL)
	{
		*line = ft_strncpy(*buff_mem, '\n');
		if (!*line)
			return (-1);
		temp = ft_substr_gnl(*buff_mem, '\n');
		if (!temp)
			return (-1);
		*buff_mem = temp;
		return (1);
	}
	else if (*buff_mem == NULL)
	{
		*buff_mem = ft_zero(NULL, 1);
		if (!*buff_mem)
			return (-1);
	}
	return (0);
}

int	get_next_line(int fd, char **line)
{
	char		buff_temp[2];
	static char	*buff_mem;
	int			retread;
	int			v;

	v = verif(line, &buff_mem);
	if (v != 0)
		return (v);
	retread = read(fd, buff_temp, 1);
	while (retread != 0)
	{
		if (retread == -1)
			return (-1);
		buff_temp[retread] = '\0';
		buff_mem = ft_strjoin(buff_mem, buff_temp);
		if (!buff_mem)
			return (-1);
		v = verif(line, &buff_mem);
		if (v != 0)
			return (v);
		retread = read(fd, buff_temp, 1);
	}
	*line = buff_mem;
	buff_mem = NULL;
	return (0);
}
