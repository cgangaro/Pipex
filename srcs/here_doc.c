/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgangaro <cgangaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 10:57:17 by cgangaro          #+#    #+#             */
/*   Updated: 2021/09/22 13:34:05 by cgangaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

int	here_doc(char **argv)
{
	char		*line;
	int			fd;
	int			first;
	extern char	**environ;

	write(1, "here_doc >", 10);
	fd = open("__temp_here_doc", O_CREAT | O_RDWR | O_APPEND, S_IRWXU);
	first = 1;
	while (get_next_line(0, &line) != 0)
	{
		if (ft_strncmp(argv[2], line, ft_strlen(argv[2])) == 0)
			break ;
		if (first != 1)
			write(fd, "\n", 1);
		write(fd, line, ft_strlen(line));
		first = 0;
		free (line);
		write(1, "here_doc >", 10);
	}
	close(fd);
	return (here_doc_pipe(argv, environ));
}

int	here_doc_pipe(char **argv, char **environ)
{
	char	*path;
	int		fd_pipe[2];
	pid_t	pid;

	path = get_part_env("PATH", environ);
	pipe(fd_pipe);
	pid = fork();
	if (pid < 0)
		return (-1);
	if (pid == 0)
	{
		close (fd_pipe[0]);
		child_process_here_doc(fd_pipe[1], argv, path, environ);
	}
	else
	{
		close (fd_pipe[1]);
		parent_process_here_doc(fd_pipe[0], argv, path, environ);
	}
	return (0);
}

void	child_process_here_doc(int pid, char **argv, char *path, char **env)
{
	int		fd;

	fd = open("__temp_here_doc", O_RDONLY);
	if (fd == -1)
		exit (-1);
	dup2(fd, STDIN_FILENO);
	dup2(pid, STDOUT_FILENO);
	close (fd);
	remove("__temp_here_doc");
	close (pid);
	ft_execve(path, argv[3], env);
}

void	parent_process_here_doc(int pid, char **argv, char *path, char **env)
{
	int	fd;

	fd = open(argv[5], O_WRONLY | O_CREAT | O_TRUNC,
			S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
	if (fd == -1)
		exit (-1);
	dup2(pid, STDIN_FILENO);
	close(pid);
	dup2(fd, STDOUT_FILENO);
	close (fd);
	ft_execve(path, argv[4], env);
}
