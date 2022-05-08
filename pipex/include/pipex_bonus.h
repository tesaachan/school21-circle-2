/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akami <akami@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 20:48:01 by akami             #+#    #+#             */
/*   Updated: 2022/03/14 20:47:08 by akami            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include <stdio.h>      /* perror */
# include <stdlib.h>     /* malloc, free, exit */
# include <string.h>     /* stderror */
# include <unistd.h>     /* pipe, dup2, execve, fork */
# include <fcntl.h>      /* open */
# include <sys/wait.h>   /* wait, waitpid */

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# define TRUE 1
# define FALSE 0

typedef struct s_pipex {
	char	*cmd;
	char	**cmd_paths;
	char	**cmd_args;
	int		*pipes;
	int		fd[2];
	int		infile;
	int		outfile;
	int		cmds_length;
	int		pipes_length;
	int		is_heredoc;
	int		pid;
}			t_ppx;

size_t	ft_strlen(const char *str);
char	**ft_split(char const *s, char c);
char	*ft_strjoin(char const *s1, char const *s2);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strdup(const char *s1);

void	err_message(char *str);
char	*get_path(char *envp[]);
char	*get_command(char **paths, char *cmd);
void	init_pipes(t_ppx *data);
void	close_pipes(t_ppx *data);
void	free_child(t_ppx *data);
void	free_parent(t_ppx *data);
void	set_infile(char *delimiter, char *filename, t_ppx *data);
void	set_outfile(char *filename, t_ppx *data);
int		min_args_number(char *arg, t_ppx *data);

char	*get_next_line(int fd);
char	*ft_substr(char const *s, unsigned int start, size_t len);

#endif
