/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgangaro <cgangaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 13:55:00 by cgangaro          #+#    #+#             */
/*   Updated: 2021/10/06 15:20:37 by cgangaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

int	main(int argc, char **argv)
{
	int			pids[1000];
	int			pipes[500][2];
	int			pid;
	int			i;

	start_error(argc, argv);
	i = -1;
	while (++i < (argc - 3))
	{
		pipe(pipes[i]);
		pid = fork();
		pids[i] = pid;
		if (pid < 0)
			return (-1);
		else if (pid > 0)
			close(pipes[i][1]);
		else
			child_process(pipes, i, argv, argc);
	}
	i = -1;
	while (++i < (argc - 3))
		waitpid(pids[i], 0, 0);
	return (0);
}

void	start_error(int argc, char **argv)
{	
	if (argc < 4)
	{
		ft_putstr_1("Error\n");
		exit(-1);
	}
	if (ft_strncmp("here_doc", argv[1], 8) == 0 && argc != 6)
	{
		ft_putstr_1("Error cmd\n");
		exit(-1);
	}
	if (argc == 6 && ft_strncmp("here_doc", argv[1], 8) == 0)
	{
		if (here_doc(argv) == 0)
			exit(0);
		else
		{
			ft_putstr_1("Error\n");
			exit(-1);
		}
	}
}

char	*get_part_env(char *part, char **env)
{
	int		i;
	int		j;
	char	*retour;

	i = 0;
	while (env[i] != NULL)
	{
		j = 0;
		while (env[i][j] == part[j])
			j++;
		if (env[i][j] == '=' && part[j] == '\0')
		{
			retour = ft_substr(env[i], j + 1, ft_strlen(env[i]) - j);
			return (retour);
		}
		i++;
	}
	return (NULL);
}

void	ft_putchar_1(char s)
{
	write(1, &s, 1);
}

void	ft_putstr_1(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		ft_putchar_1(s[i]);
		i++;
	}
}
