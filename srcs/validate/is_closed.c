/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_closed.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoinemura <antoinemura@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 15:00:08 by antoinemura       #+#    #+#             */
/*   Updated: 2024/05/26 16:04:11 by antoinemura      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

static int	is_line_start_end_closed(char *line)
{
	int	len;
	int	i;

	i = 0;
	if (line == NULL)
		return (-1);
	len = ft_strlen(line);
	while (i < len)
	{
		if (line[i] != '1')
			return (E_ERR);
		i++;
	}
	return (E_OK);
}

int	is_closed(char *filename)
{
	int		fd;
	char	*line;
	char	*tmp;

	fd = open(filename, O_RDONLY);
	line = gnl_and_trim(fd);
	if (line == NULL)
		return (close(fd), E_ERR);
	tmp = line;
	if (is_line_start_end_closed(line) == E_ERR)
		return (free(line), close(fd), E_ERR);
	while (line != NULL)
	{
		line = gnl_and_trim(fd);
		if (line != NULL)
		{
			if (!ft_str_start_with(line, "1") || !ft_str_end_with(line, "1"))
				return (free(tmp), close(fd), E_ERR);
			tmp = line;
		}
	}
	if (is_line_start_end_closed(tmp) == E_ERR)
		return (free(tmp), close(fd), E_ERR);
	return (free(line), close(fd), E_OK);
}
