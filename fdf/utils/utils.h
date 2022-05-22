/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akami <akami@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 18:12:21 by akami             #+#    #+#             */
/*   Updated: 2022/05/21 18:17:57 by akami            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# define TRUE 1
# define FALSE 0

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <limits.h>

char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlen(const char *str);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strchr(const char *s, int c);

#endif
