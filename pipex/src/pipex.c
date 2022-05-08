/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akami <akami@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 20:47:11 by akami             #+#    #+#             */
/*   Updated: 2022/03/10 20:55:58 by akami            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void	first_child_process(t_ppx data, char *args, char *envp[])
{
	dup2(data.fd[1], STDOUT_FILENO);
	close(data.fd[0]);
	dup2(data.infile, STDIN_FILENO);
	data.cmd_args = ft_split(args, ' ');
	data.cmd = get_command(data.cmd_paths, data.cmd_args[0]);
	if (data.cmd == NULL)
	{
		free_child(&data);
		err_message("command not found");
	}
	execve(data.cmd, data.cmd_args, envp);
}

void	second_child_process(t_ppx data, char *args, char *envp[])
{
	dup2(data.fd[0], STDIN_FILENO);
	close(data.fd[1]);
	dup2(data.outfile, STDOUT_FILENO);
	data.cmd_args = ft_split(args, ' ');
	data.cmd = get_command(data.cmd_paths, data.cmd_args[0]);
	if (data.cmd == NULL)
	{
		free_child(&data);
		err_message("command not found");
		exit(1);
	}
	execve(data.cmd, data.cmd_args, envp);
}

void	parent_process(t_ppx *data, char *argv[], char *envp[])
{
	pid_t	fs_pid;
	pid_t	sc_pid;
	char	*paths;

	paths = get_path(envp);
	data->cmd_paths = ft_split(paths, ':');
	fs_pid = fork();
	if (fs_pid == -1)
		err_message("failed fork");
	if (fs_pid == 0)
		first_child_process(*data, argv[2], envp);
	sc_pid = fork();
	if (sc_pid == -1)
		err_message("failed fork");
	if (sc_pid == 0)
		second_child_process(*data, argv[3], envp);
	close(data->fd[0]);
	close(data->fd[1]);
	waitpid(fs_pid, NULL, 0);
	waitpid(sc_pid, NULL, 0);
	free_parent(data);
}

int	main(int argc, char *argv[], char *envp[])
{
	t_ppx	data;

	if (argc != 5)
		err_message("the wrong number of arguments");
	data.infile = open(argv[1], O_RDONLY);
	if (data.infile == -1)
		err_message("failed opening infile");
	data.outfile = open(argv[argc - 1], O_TRUNC | O_CREAT | O_RDWR, 0644);
	if (data.outfile == -1)
		err_message("failed opening outfile");
	if (pipe(data.fd) < 0)
		err_message("failed pipe");
	parent_process(&data, argv, envp);
	return (0);
}
