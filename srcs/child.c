/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgangaro <cgangaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 11:45:25 by cgangaro          #+#    #+#             */
/*   Updated: 2021/09/22 14:30:24 by cgangaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

void	child_process(int pipes[500][2], int i, char **argv, int argc)
{
	if (i == 0)
		child_process_start(pipes, i, argv);
	else if (i < (argc - 3) - 1)
		child_process_middle(pipes, i, argv);
	else
		child_process_end(pipes, i, argv, argc);
}

void	child_process_start(int pipes[500][2], int i, char **argv)
{
	int			fd;
	char		*path;
	extern char	**environ;

	path = get_part_env("PATH", environ);
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		free (path);
		ft_putstr_1("Error file\n");
		exit (-1);
	}
	dup2(fd, STDIN_FILENO);
	dup2(pipes[i][1], STDOUT_FILENO);
	close (fd);
	close (pipes[i][1]);
	ft_execve(path, argv[i + 2], environ);
}

void	child_process_middle(int pipes[500][2], int i, char **argv)
{
	char		*path;
	extern char	**environ;

	path = get_part_env("PATH", environ);
	dup2(pipes[i - 1][0], STDIN_FILENO);
	dup2(pipes[i][1], STDOUT_FILENO);
	close(pipes[i][1]);
	close(pipes[i - 1][0]);
	ft_execve(path, argv[i + 2], environ);
}

void	child_process_end(int pipes[500][2], int i, char **argv, int argc)
{
	int			fd;
	char		*path;
	extern char	**environ;

	path = get_part_env("PATH", environ);
	fd = open(argv[argc - 1], O_WRONLY | O_CREAT | O_TRUNC,
			S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
	if (fd == -1)
	{
		free (path);
		ft_putstr_1("Error file\n");
		exit (-1);
	}
	dup2(pipes[i - 1][0], STDIN_FILENO);
	close(pipes[i - 1][0]);
	close(pipes[i][1]);
	close(pipes[i][0]);
	dup2(fd, STDOUT_FILENO);
	close(fd);
	ft_execve(path, argv[i + 2], environ);
}
