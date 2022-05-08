/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_files.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akami <akami@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 18:32:18 by akami             #+#    #+#             */
/*   Updated: 2022/03/14 21:38:48 by akami            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex_bonus.h"

static int	write_heredoc(char *delimiter)
{
	int		fd;
	char	*buf;
	char	*shorten;

	fd = open(".heredoc", O_CREAT | O_WRONLY | O_TRUNC, 0000644);
	if (fd < 0)
		return (0);
	while (TRUE)
	{
		write(1, "heredoc> ", 9);
		buf = get_next_line(0);
		if (buf == NULL)
			return (0);
		shorten = ft_substr(buf, 0, ft_strlen(buf) - 1);
		if (ft_strncmp(delimiter, shorten, ft_strlen(delimiter) + 1) == 0)
			break ;
		write(fd, buf, ft_strlen(buf));
		free(buf);
		free(shorten);
	}
	free(buf);
	free(shorten);
	close(fd);
	return (1);
}

void	set_infile(char *delimiter, char *filename, t_ppx *data)
{
	if (data->is_heredoc == TRUE)
	{
		if (write_heredoc(delimiter) == 0)
			err_message("failed writing .heredoc");
		data->infile = open(".heredoc", O_RDONLY);
		if (data->infile < 0)
		{
			unlink(".heredoc");
			err_message("failed opening .heredoc");
		}
	}
	else
	{
		data->infile = open(filename, O_RDONLY);
		if (data->infile < 0)
			err_message("failed opening infile");
	}
}

void	set_outfile(char *filename, t_ppx *data)
{
	if (data->is_heredoc == TRUE)
		data->outfile = open(filename, O_CREAT | O_WRONLY | O_APPEND, 0000644);
	else
		data->outfile = open(filename, O_TRUNC | O_CREAT | O_RDWR, 0000644);
	if (data->outfile < 0)
		err_message("failed opening outfile");
}
