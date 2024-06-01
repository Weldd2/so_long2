/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoinemura <antoinemura@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 16:04:13 by antoinemura       #+#    #+#             */
/*   Updated: 2024/05/26 16:22:19 by antoinemura      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

char	*gnl_and_trim(int fd)
{
	char	*line;
	char	*tmp;

	line = ft_get_next_line(fd);
	tmp = line;
	if (line != NULL)
	{
		line = ft_strtrim(line, "\n");
		free(tmp);
	}
	return (line);
}