/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: georgy <georgy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 20:47:57 by akami             #+#    #+#             */
/*   Updated: 2022/03/10 21:03:52 by georgy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdio.h>      /* perror */
# include <stdlib.h>     /* malloc, free, exit */
# include <string.h>     /* stderror */
# include <unistd.h>     /* pipe, dup2, execve, fork */
# include <fcntl.h>      /* open */
# include <sys/wait.h>   /* wait, waitpid */

typedef struct s_pipex {
	int		fd[2];
	int		infile;
	int		outfile;
	char	*cmd;
	char	**cmd_paths;
	char	**cmd_args;
}	t_ppx;

size_t	ft_strlen(const char *str);
char	**ft_split(char const *s, char c);
char	*ft_strjoin(char const *s1, char const *s2);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strdup(const char *s1);

void	err_message(char *str);
char	*get_path(char *envp[]);
char	*get_command(char **paths, char *cmd);
void	free_child(t_ppx *data);
void	free_parent(t_ppx *data);

#endif
