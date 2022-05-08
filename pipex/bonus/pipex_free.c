/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: georgy <georgy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 18:28:32 by akami             #+#    #+#             */
/*   Updated: 2022/03/16 18:22:49 by georgy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex_bonus.h"

void	free_child(t_ppx *data)
{
	size_t	i;

	i = 0;
	while (data->cmd_args[i] != NULL)
	{
		free(data->cmd_args[i]);
		i++;
	}
	free(data->cmd_args);
	free(data->cmd);
}

void	free_parent(t_ppx *data)
{
	size_t	i;

	i = 0;
	close(data->infile);
	close(data->outfile);
	if (data->is_heredoc)
		unlink(".heredoc");
	if (data->cmd_paths != NULL)
	{
		while (data->cmd_paths[i] != NULL)
		{
			free(data->cmd_paths[i]);
			i++;
		}
		free(data->cmd_paths);
	}
	free(data->pipes);
}
