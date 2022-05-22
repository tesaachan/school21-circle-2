/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_msg.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akami <akami@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 18:11:54 by akami             #+#    #+#             */
/*   Updated: 2022/05/21 18:11:58 by akami            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	ft_error_msg(const char *str)
{
	int	len;

	len = ft_strlen(str);
	write(2, "Error message: ", 16);
	write(2, str, len);
	write(2, "\n", 2);
	exit(1);
}
