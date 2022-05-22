/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akami <akami@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 18:12:19 by akami             #+#    #+#             */
/*   Updated: 2022/05/21 18:12:20 by akami            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

static void	ft_read(int fd, char *buf, char **str)
{
	size_t	i;
	char	*tmp;

	if (!(*str) || !ft_strchr(*str, '\n'))
	{
		i = read(fd, buf, BUFFER_SIZE);
		while (i)
		{
			buf[i] = '\0';
			if (!(*str))
				*str = ft_substr(buf, 0, i);
			else
			{
				tmp = *str;
				*str = ft_strjoin(*str, buf);
				free(tmp);
			}
			if (ft_strchr(buf, '\n'))
				break ;
			i = read(fd, buf, BUFFER_SIZE);
		}
	}
	free(buf);
}

static char	*ft_getline(char **str)
{
	size_t	i;
	size_t	j;
	char	*line;
	char	*line_end;
	char	*tmp;

	line_end = ft_strchr(*str, '\n');
	if (!line_end)
	{
		line = ft_substr(*str, 0, ft_strlen(*str));
		free(*str);
		*str = NULL;
		return (line);
	}
	i = ft_strlen(*str);
	j = ft_strlen(line_end);
	line = ft_substr(*str, 0, i - j + 1);
	tmp = *str;
	*str = ft_substr(line_end, 1, j - 1);
	free(tmp);
	return (line);
}

char	*get_next_line(int fd)
{
	char		*buf;
	static char	*str;

	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	if (BUFFER_SIZE < 1 || fd == -1 || read(fd, buf, 0) == -1)
	{
		free(buf);
		return (NULL);
	}
	ft_read(fd, buf, &str);
	if (!str)
		return (NULL);
	if (ft_strlen(str) == 0)
	{
		free(str);
		return (NULL);
	}
	return (ft_getline(&str));
}
