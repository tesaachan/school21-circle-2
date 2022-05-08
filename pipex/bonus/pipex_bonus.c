/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akami <akami@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 17:40:31 by akami             #+#    #+#             */
/*   Updated: 2022/03/19 18:54:31 by akami            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex_bonus.h"

static void	child_dup2(int id, t_ppx *data)
{
	if (id == 0)
	{
		dup2(data->infile, STDIN_FILENO);
		dup2(data->pipes[1], STDOUT_FILENO);
	}
	else if (id != data->cmds_length - 1)
	{
		dup2(data->pipes[2 * id - 2], STDIN_FILENO);
		dup2(data->pipes[2 * id + 1], STDOUT_FILENO);
	}
	else
	{
		dup2(data->pipes[2 * id - 2], STDIN_FILENO);
		dup2(data->outfile, STDOUT_FILENO);
	}
}

static void	check_cmd(t_ppx *data)
{
	if (data->cmd == NULL)
	{
		err_message("error with command");
		free_child(data);
		exit(1);
	}
}

static void	child_process(int id, char *argv[], char *envp[], t_ppx data)
{
	pid_t	pid;
	size_t	args_position;

	pid = fork();
	if (pid == 0)
	{
		child_dup2(id, &data);
		close_pipes(&data);
		args_position = 2 + id;
		if (data.is_heredoc)
			args_position++;
		data.cmd_args = ft_split(argv[args_position], ' ');
		data.cmd = get_command(data.cmd_paths, data.cmd_args[0]);
		check_cmd(&data);
		execve(data.cmd, data.cmd_args, envp);
	}
}

static void	parent_process(t_ppx *data, char *argv[], char *envp[])
{
	int		id;
	char	*paths;

	paths = get_path(envp);
	data->cmd_paths = ft_split(paths, ':');
	if (data->cmd_paths == NULL)
	{
		free_parent(data);
		err_message("wrong envp");
		exit(1);
	}
	init_pipes(data);
	id = 0;
	while (id < data->cmds_length)
	{
		child_process(id, argv, envp, *data);
		id++;
	}
	close_pipes(data);
	waitpid(-1, NULL, 0);
	free_parent(data);
}

int	main(int argc, char *argv[], char *envp[])
{
	t_ppx	data;

	if (argc < min_args_number(argv[1], &data))
		err_message("the wrong number of arguments");
	set_infile(argv[2], argv[1], &data);
	set_outfile(argv[argc - 1], &data);
	data.cmds_length = argc - 3;
	if (data.is_heredoc == TRUE)
		data.cmds_length--;
	data.pipes_length = 2 * (data.cmds_length - 1);
	data.pipes = (int *)malloc(sizeof(int) * data.pipes_length);
	if (data.pipes == NULL)
		err_message("failed pipe");
	parent_process(&data, argv, envp);
	return (0);
}
