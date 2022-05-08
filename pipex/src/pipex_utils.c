/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akami <akami@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 20:47:09 by akami             #+#    #+#             */
/*   Updated: 2022/03/10 20:47:10 by akami            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void	err_message(char *str)
{
	perror(str);
	exit(1);
}

char	*get_path(char *envp[])
{
	size_t	i;

	i = 0;
	while (ft_strncmp("PATH", envp[i], 4))
		i++;
	return (*(envp + i) + 5);
}

char	*get_command(char **paths, char *cmd)
{
	size_t	i;
	char	*possible_path;
	char	*full_cmd_path;

	i = 0;
	while (paths[i])
	{
		possible_path = ft_strjoin(paths[i], "/");
		full_cmd_path = ft_strjoin(possible_path, cmd);
		free(possible_path);
		if (access(full_cmd_path, 0) == 0)
			return (full_cmd_path);
		free(full_cmd_path);
		i++;
	}
	return (NULL);
}

void	free_child(t_ppx *data)
{
	size_t	i;

	i = 0;
	while (data->cmd_args[i])
	{
		free(data->cmd_args[i]);
		i++;
	}
	free(data->cmd_args);
	close(data->fd[0]);
	close(data->fd[1]);
}

void	free_parent(t_ppx *data)
{
	size_t	i;

	i = 0;
	while (data->cmd_paths[i])
	{
		free(data->cmd_paths[i]);
		i++;
	}
	free(data->cmd_paths);
	close(data->infile);
	close(data->outfile);
}
