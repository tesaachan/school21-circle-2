/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_pipes.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: georgy <georgy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 18:29:52 by akami             #+#    #+#             */
/*   Updated: 2022/03/16 18:25:25 by georgy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex_bonus.h"

void	init_pipes(t_ppx *data)
{
	int	i;

	i = 0;
	while (i < data->cmds_length - 1)
	{
		if (pipe(data->pipes + 2 * i) < 0)
			free_parent(data);
		i++;
	}
}

void	close_pipes(t_ppx *data)
{
	int	i;

	i = 0;
	while (i < data->pipes_length)
	{
		close(data->pipes[i]);
		i++;
	}
}
