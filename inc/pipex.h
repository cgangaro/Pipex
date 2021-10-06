/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgangaro <cgangaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 15:44:07 by cgangaro          #+#    #+#             */
/*   Updated: 2021/09/22 13:57:51 by cgangaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <fcntl.h>
# include <signal.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <string.h>
# include <sys/types.h>
# include <sys/stat.h>

typedef struct s_process
{
	int					content;
	int					fd_pipe[2];
	int					fd_pipe_previous;
	pid_t				pid;
	int					n_cmd;
	int					n_this_cmd;
	int					n_pipe;
	int					n_this_pipe;
	char				*cmd1;
	char				*cmd2;
	char				*file1;
	char				*file2;
	struct s_process	*next;
}				t_process;

char		**ft_split(char const *s, char c);
void		*ft_calloc(size_t count, size_t size);
void		*ft_memcpy(void *dst, const void *src, size_t n);
void		ft_bzero(char *s, size_t n);
char		*ft_strchr(const char *s, int c);
char		*ft_substr(char const *s, unsigned int start, size_t len);
size_t		ft_strlen(char *s);
char		*ft_strjoin(char *s1, char *s2);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
char		*get_part_env(char *part, char **env);
int			ft_execve(char *path, char *cmd, char **env);
char		**ft_join_path(char **path, char **cmd);
char		*ft_check_path(char **path);
void		error_execve(char *error, char *path, char **path_split,
				char **cmd_split);
t_process	*create_list(t_process *process, int argc, char **argv);
void		ft_aff_list(t_process *process);
void		ft_lstadd_back(t_process **list, int i, int argc, char **argv);

int			get_next_line(int fd, char **line);
int			verif(char **line, char **buff_mem);
char		*ft_strncpy(char *s1, char c);
char		*ft_zero(char *s, int n);
char		*ft_substr_gnl(char *s1, char c);

int			here_doc(char **argv);
int			here_doc_pipe(char **argv, char **environ);
void		child_process_here_doc(int pid, char **argv, char *path,
				char **env);
void		parent_process_here_doc(int pid, char **argv, char *path,
				char **env);

void		child_process_start(int pipes[500][2], int i, char **argv);
void		child_process_middle(int pipes[500][2], int i, char **argv);
void		child_process_end(int pipes[500][2], int i, char **argv, int argc);
void		start_error(int argc, char **argv);
void		child_process(int pipes[500][2], int i, char **argv, int argc);

void		ft_putchar_1(char s);
void		ft_putstr_1(char *s);
#endif