/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: georgy <georgy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 17:40:28 by akami             #+#    #+#             */
/*   Updated: 2022/03/16 18:15:49 by georgy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex_bonus.h"

void	err_message(char *str)
{
	perror(str);
	exit(1);
}

char	*get_path(char *envp[])
{
	size_t	i;

	i = 0;
	while (ft_strncmp("PATH", envp[i], 4) != 0)
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

int	min_args_number(char *arg, t_ppx *data)
{
	size_t	min_number;

	min_number = 5;
	data->is_heredoc = FALSE;
	if (arg && ft_strncmp("here_doc", arg, 9) == 0)
	{
		data->is_heredoc = TRUE;
		min_number++;
	}
	return (min_number);
}
