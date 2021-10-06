/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execve.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgangaro <cgangaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 16:20:47 by cgangaro          #+#    #+#             */
/*   Updated: 2021/09/22 14:23:43 by cgangaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

int	ft_execve(char *path, char *cmd, char **env)
{
	char	**cmd_split;
	char	**path_split;
	int		i;
	char	*ret;

	i = 0;
	cmd_split = ft_split(cmd, ' ');
	path_split = ft_split(path, ':');
	free (path);
	path_split = ft_join_path(path_split, cmd_split);
	ret = ft_check_path(path_split);
	if (ret == NULL)
	{
		ft_putstr_1("Error: exe non trouvable\n");
		exit (-1);
	}
	if (execve(ret, cmd_split, env) == -1)
	{
		ft_putstr_1("Error execve\n");
		exit (-1);
	}
	return (0);
}

char	*ft_check_path(char **path)
{
	int			i;
	int			ret;
	struct stat	buf;

	i = 0;
	while (path[i] != NULL)
	{
		ret = stat(path[i], &buf);
		if (ret == 0)
			return (path[i]);
		i++;
	}
	return (NULL);
}

char	**ft_join_path(char **path, char **cmd)
{
	int	i;

	i = 0;
	while (path[i] != NULL)
	{
		path[i] = ft_strjoin(path[i], "/");
		if (path[i] == NULL)
			return (NULL);
		path[i] = ft_strjoin(path[i], cmd[0]);
		i++;
	}
	return (path);
}
