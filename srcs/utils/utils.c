/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amura <amura@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 16:04:13 by antoinemura       #+#    #+#             */
/*   Updated: 2024/06/01 22:24:19 by amura            ###   ########.fr       */
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
		if (!line)
		{
			free(tmp);
			return (NULL);
		}
		free(tmp);
	}
	return (line);
}
