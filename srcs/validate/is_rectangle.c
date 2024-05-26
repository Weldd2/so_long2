/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_rectangle.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoinemura <antoinemura@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 14:42:11 by antoinemura       #+#    #+#             */
/*   Updated: 2024/05/26 15:35:55 by antoinemura      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

int	is_rectangle(char *filename)
{
	int		fd;
	char	*line;
	int		line_l;
	char	*tmp;

	fd = open(filename, O_RDONLY);
	line = ft_get_next_line(fd);
	if (line == NULL)
		return (close(fd), E_ERR);
	tmp = line;
	line = ft_strtrim(tmp, "\n");
	free(tmp);
	line_l = ft_strlen(line);
	while (line != NULL)
	{
		if (line_l != (int)ft_strlen(line))
			return (free(line), close(fd), E_ERR);
		line = ft_get_next_line(fd);
		tmp = line;
		line = ft_strtrim(tmp, "\n");
		free(tmp);
	}
	return (free(line), close(fd), E_OK);
}
